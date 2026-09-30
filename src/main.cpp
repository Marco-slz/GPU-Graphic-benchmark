// ---------------------------------------------------------------------------
// GPU Benchmark - starter window
//
// What this does right now:
//   1. Opens a window with an OpenGL 4.1 core context (GLFW + glad)
//   2. Draws a spinning triangle loaded from shaders/ (proves the GPU pipeline works)
//   3. Measures how long the GPU spends drawing it, using a timer query
//   4. Shows a Dear ImGui panel with GPU info, FPS, and GPU time
//
// The benchmark tests (geometry throughput, memory bandwidth) get added later.
// ---------------------------------------------------------------------------
#include <glad/gl.h>          // must come before GLFW so GLFW doesn't pull in old GL headers
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>

// ---- Small helpers ---------------------------------------------------------

static void glfwErrorCallback(int code, const char* description)
{
    std::fprintf(stderr, "GLFW error %d: %s\n", code, description);
}

// Reads a whole text file into a string (used for shader source files).
static std::string readFile(const char* path)
{
    std::ifstream file(path);
    if (!file) {
        std::fprintf(stderr, "Could not open %s\n", path);
        return {};
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Compiles one shader stage and prints the error log if it fails.
static GLuint compileShader(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    GLint ok = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
    if (!ok) {
        char log[1024];
        glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
        std::fprintf(stderr, "Shader compile error:\n%s\n", log);
    }
    return shader;
}

// Links a vertex + fragment shader into a program the GPU can run.
static GLuint createProgram(const char* vertPath, const char* fragPath)
{
    GLuint vs = compileShader(GL_VERTEX_SHADER, readFile(vertPath));
    GLuint fs = compileShader(GL_FRAGMENT_SHADER, readFile(fragPath));

    GLuint program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    GLint ok = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &ok);
    if (!ok) {
        char log[1024];
        glGetProgramInfoLog(program, sizeof(log), nullptr, log);
        std::fprintf(stderr, "Program link error:\n%s\n", log);
    }
    glDeleteShader(vs);   // the program keeps its own copy
    glDeleteShader(fs);
    return program;
}

// ---- main ------------------------------------------------------------------

int main()
{
    // 1. Initialise GLFW and ask for an OpenGL 4.1 core context.
    //    4.1 is the highest version macOS supports, so this works on every OS.
    glfwSetErrorCallback(glfwErrorCallback);
    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(1280, 720, "GPU Benchmark", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // 2. Load the OpenGL functions. Nothing gl* works before this line.
    int glVersion = gladLoadGL(glfwGetProcAddress);
    if (glVersion == 0) {
        std::fprintf(stderr, "Failed to load OpenGL\n");
        return 1;
    }

    // Vsync OFF: otherwise the frame rate is capped at the monitor refresh rate.
    bool vsync = false;
    glfwSwapInterval(vsync ? 1 : 0);

    // 3. Set up Dear ImGui.
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 410");

    // 4. Upload a triangle to the GPU: position (x, y) + colour (r, g, b).
    const float vertices[] = {
        //  x      y      r     g     b
         0.0f,  0.6f,  1.0f, 0.2f, 0.2f,
        -0.5f, -0.4f,  0.2f, 1.0f, 0.2f,
         0.5f, -0.4f,  0.2f, 0.4f, 1.0f,
    };

    GLuint vao = 0, vbo = 0;
    glGenVertexArrays(1, &vao);          // VAO = remembers how vertex data is laid out
    glGenBuffers(1, &vbo);               // VBO = the vertex data itself, in GPU memory
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // SHADER_DIR is set by CMakeLists.txt to the project's shaders/ folder.
    GLuint program = createProgram(SHADER_DIR "triangle.vert", SHADER_DIR "triangle.frag");
    GLint angleLoc = glGetUniformLocation(program, "uAngle");

    // 5. GPU timer query: asks the GPU itself how long the draw took.
    //    The answer arrives a frame later, so we only read it when it's ready.
    GLuint timerQuery = 0;
    glGenQueries(1, &timerQuery);
    bool queryPending = false;
    double gpuDrawMs = 0.0;

    // Copy the GPU name strings now so the GUI can show them.
    const char* gpuVendor   = (const char*)glGetString(GL_VENDOR);
    const char* gpuRenderer = (const char*)glGetString(GL_RENDERER);
    const char* glVerString = (const char*)glGetString(GL_VERSION);

    // 6. Main loop: one iteration = one frame.
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        int width = 0, height = 0;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Read last frame's timer result if the GPU has finished it.
        if (queryPending) {
            GLint available = 0;
            glGetQueryObjectiv(timerQuery, GL_QUERY_RESULT_AVAILABLE, &available);
            if (available) {
                GLuint64 ns = 0;
                glGetQueryObjectui64v(timerQuery, GL_QUERY_RESULT, &ns);
                gpuDrawMs = ns / 1.0e6;
                queryPending = false;
            }
        }

        // Draw the triangle, timed on the GPU.
        if (!queryPending) glBeginQuery(GL_TIME_ELAPSED, timerQuery);
        glUseProgram(program);
        glUniform1f(angleLoc, (float)glfwGetTime());
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        if (!queryPending) { glEndQuery(GL_TIME_ELAPSED); queryPending = true; }

        // ---- GUI --------------------------------------------------------
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
        ImGui::Begin("GPU Benchmark");
        ImGui::Text("GPU:     %s", gpuRenderer);
        ImGui::Text("Vendor:  %s", gpuVendor);
        ImGui::Text("OpenGL:  %s", glVerString);
        ImGui::Separator();
        ImGui::Text("FPS:        %.1f", ImGui::GetIO().Framerate);
        ImGui::Text("Frame time: %.3f ms", 1000.0f / ImGui::GetIO().Framerate);
        ImGui::Text("GPU draw:   %.4f ms", gpuDrawMs);
        if (ImGui::Checkbox("VSync", &vsync))
            glfwSwapInterval(vsync ? 1 : 0);
        ImGui::Separator();
        ImGui::BeginDisabled();                 // placeholders for the real tests
        ImGui::Button("Run geometry test");
        ImGui::Button("Run bandwidth test");
        ImGui::EndDisabled();
        ImGui::End();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // 7. Clean up in reverse order of creation.
    glDeleteQueries(1, &timerQuery);
    glDeleteProgram(program);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
