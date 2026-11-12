# Build and run instructions

## Framework and requirements

This application uses **Qt Widgets 6** for its graphical interface. The project was inspected with **Qt 6.11.2** (`qmake6 -query QT_VERSION`). CMake requests Qt 6 `Widgets` and `Sql` modules and requires **CMake 3.16 or newer** and a **C++17** compiler. GPU discovery also requires an OpenCL development package and a working OpenCL platform/runtime. The SQLite connection uses Qt's `QSQLITE` driver.

The Qt version above is the version observed in the development environment; the CMake project accepts Qt 6 installations with the required modules.

## Build on macOS

Run these commands from the repository root:

```sh
cmake -S . -B build
cmake --build build
```

CMake configures the target as a macOS application bundle. Launch the GUI with:

```sh
open build/test.app
```

To run the executable directly in Terminal and see diagnostic output:

```sh
./build/test.app/Contents/MacOS/test
```

## Runtime note

A successful build does not guarantee GPU discovery. The application queries OpenCL during backend initialization; the current scanner throws an exception if it cannot retrieve an OpenCL platform. Confirm that an OpenCL platform is available on the machine when testing the GPU scan flow. The project currently does not display that failure as a recoverable GUI error.

## Verification record

In the development environment, `cmake --build build` completed successfully. A direct launch attempt exited with status 134 and reported macOS PasteBoard/Hiservices connection errors, so a successful interactive GUI run has not been verified there.
