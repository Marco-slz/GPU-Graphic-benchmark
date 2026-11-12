# GPU Graphics Benchmark

A Qt Widgets desktop application for discovering GPU devices and presenting basic device information. GPU discovery uses OpenCL; the project also contains a SQLite persistence layer for GPU records.

## Current features

- Scan for GPU devices exposed by available OpenCL platforms.
- Display discovered GPUs as selectable buttons.
- Show the selected GPU's vendor and model in the overview panel.
- Navigate between the GPU and placeholder Settings sections, or close the application from the sidebar.
- Store and retrieve GPU records through the `DatabaseManager` SQLite layer.

The current GUI scan path updates the overview's vendor and model fields. VRAM and base clock fields are present but are not populated yet. The Statistics button and Settings page are not fully connected. Database persistence is implemented in the backend but is not yet exposed as a complete GUI workflow.

## Build and run

See [BUILD_AND_RUN.md](BUILD_AND_RUN.md) for framework/version details, dependencies, and macOS build and launch commands.

The interface uses **Qt Widgets 6**. Qt 6.11.2 was present in the inspected development environment. The project also requires CMake 3.16 or newer, a C++17 compiler, Qt's Widgets and Sql modules, and an OpenCL development/runtime installation.

## Runtime requirements and current limitations

GPU discovery requires an available OpenCL platform. `GpuScanner` currently throws an exception if it cannot query an OpenCL platform, and the GUI does not yet catch that exception or display a recoverable error message. Selecting a GPU updates vendor and model only; the VRAM and base clock fields remain blank.

## Project layout

```text
src/
├── backend/
│   ├── backend.*
│   ├── database_management/
│   ├── devices/
│   └── gpu_scanner/
├── gui/
│   ├── main_window/
│   ├── sections/
│   │   └── gpu_section/
│   └── sidebar/
└── main.cpp
assets/
├── database/
├── icons/
├── images/
└── models/
```

The main GUI flow is `GpuSelector` → `Backend` / `GpuScanner` → GPU selection signal → `DeviceOverview`.

## Database

The SQLite database file and schema are under `assets/database/`. The Qt SQL layer uses the `QSQLITE` driver. Database file paths are currently relative to the application's working directory; run from the repository root when using the development commands in `BUILD_AND_RUN.md`.
