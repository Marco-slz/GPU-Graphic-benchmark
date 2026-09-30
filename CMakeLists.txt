# ---------------------------------------------------------------------------
# GPU Benchmark - top-level build file
# Libraries: GLFW (window), glad (OpenGL loader), GLM (math), Dear ImGui (GUI)
# GLFW, GLM and ImGui are downloaded automatically at configure time.
# glad is already generated and lives in external/glad.
# ---------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.20)
project(GpuBenchmark VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to a Release build: a benchmark measured in Debug mode is meaningless.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

include(FetchContent)

# --- GLFW: window, OpenGL context, keyboard/mouse input ---------------------
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)
FetchContent_Declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
    GIT_SHALLOW    TRUE)

# --- GLM: vectors and matrices (header-only) --------------------------------
FetchContent_Declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG        1.0.1
    GIT_SHALLOW    TRUE)

# --- Dear ImGui: the on-screen GUI ------------------------------------------
FetchContent_Declare(imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG        v1.91.9
    GIT_SHALLOW    TRUE)

FetchContent_MakeAvailable(glfw glm imgui)

# --- glad: loads OpenGL function pointers (checked into the repo) ----------
add_library(glad STATIC external/glad/src/gl.c)
target_include_directories(glad PUBLIC external/glad/include)

# --- ImGui has no CMakeLists of its own, so we build it here ----------------
add_library(imgui STATIC
    ${imgui_SOURCE_DIR}/imgui.cpp
    ${imgui_SOURCE_DIR}/imgui_draw.cpp
    ${imgui_SOURCE_DIR}/imgui_tables.cpp
    ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    ${imgui_SOURCE_DIR}/imgui_demo.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
    ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp)
target_include_directories(imgui PUBLIC
    ${imgui_SOURCE_DIR}
    ${imgui_SOURCE_DIR}/backends)
target_link_libraries(imgui PUBLIC glfw)
# Stop GLFW from including the system's old <GL/gl.h>; glad provides OpenGL instead.
target_compile_definitions(imgui PUBLIC GLFW_INCLUDE_NONE)

# --- The benchmark program itself --------------------------------------------
add_executable(gpu_benchmark
    src/main.cpp)

target_link_libraries(gpu_benchmark PRIVATE
    glad glfw glm::glm imgui)   # glad loads OpenGL at runtime, so no GL library to link

if(MSVC)
    target_compile_options(gpu_benchmark PRIVATE /W4)
else()
    target_compile_options(gpu_benchmark PRIVATE -Wall -Wextra)
endif()

# Tell the program where the shaders folder is, so it works no matter which
# folder you run it from (and you can edit shaders without rebuilding).
target_compile_definitions(gpu_benchmark PRIVATE
    SHADER_DIR="${CMAKE_SOURCE_DIR}/shaders/")
