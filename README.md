# GPU Benchmark

A graphics benchmark written in C++ and OpenGL that tests how fast your GPU is at
**processing geometry** and **moving data through memory**, with a live on-screen
GUI that shows results while the tests run.

> School project, in progress.

## Features

- [x] OpenGL window with a Dear ImGui control panel
- [x] GPU-side timing with OpenGL timer queries
- [ ] Geometry throughput test (triangles per second)
- [ ] Memory bandwidth test (GB/s)
- [ ] Results saved to CSV
- [ ] Final score summary

## Libraries used

| Library | What it does | How it's included |
|---|---|---|
| [GLFW 3.4](https://www.glfw.org/) | Creates the window and OpenGL context, handles input | Downloaded by CMake |
| [glad 2](https://github.com/Dav1dde/glad) | Loads OpenGL functions | Generated files in `external/glad` |
| [GLM 1.0.1](https://github.com/g-truc/glm) | Vector and matrix math | Downloaded by CMake |
| [Dear ImGui 1.91.9](https://github.com/ocornut/imgui) | On-screen GUI | Downloaded by CMake |

## Requirements

- A C++17 compiler (Visual Studio 2022, GCC 9+, or Clang 10+)
- CMake 3.20 or newer
- Git
- A GPU that supports OpenGL 4.1 or newer
- **Linux only:** `sudo apt install libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libgl-dev`

## Building

```bash
git clone https://github.com/<your-username>/<your-repo>.git
cd <your-repo>
cmake -S . -B build
cmake --build build --config Release
```

The first configure takes a minute because CMake downloads GLFW, GLM and ImGui.

## Running

- **Windows:** `build\Release\gpu_benchmark.exe`
- **Linux / macOS:** `./build/gpu_benchmark`

Close any games or heavy programs first, and plug in your laptop charger; both affect results.

## Project layout

```
.
├── CMakeLists.txt      Build instructions for CMake
├── external/glad/      OpenGL loader (generated, don't edit)
├── shaders/            GLSL shader files
├── src/                C++ source code
└── results/            CSV output from benchmark runs
```

## How the tests work

*(Fill this in as each test is written; it's the core of the project write-up.)*

## Results

*(Add a table or graph of your results on different GPUs here.)*
