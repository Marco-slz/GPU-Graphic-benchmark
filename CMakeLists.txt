# Build configuration for the Qt GPU graphics benchmark application.
cmake_minimum_required(VERSION 3.16)

project(test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

# Locate the GUI toolkit and OpenCL runtime used by the application.
find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
)
find_package(OpenCL REQUIRED)


qt_standard_project_setup()

# Collect application sources, headers, and the compiled Qt resource manifest.
qt_add_executable(test
    src/main.cpp
    src/backend/devices/device.cpp
    src/backend/devices/device.h
    src/backend/gpuscanner.cpp
    src/backend/gpuscanner.h
    src/gui/mainwindow/mainwindow.cpp
    src/gui/mainwindow/mainwindow.h
    src/gui/imagelabel.cpp
    src/gui/imagelabel.h
    src/gui/sidebar/sidebar.cpp
    src/gui/sidebar/sidebar.h
    src/gui/sections/sections.cpp
    src/gui/sections/sections.h
    src/gui/sections/gpusection/gpusection.cpp
    src/gui/sections/gpusection/gpusection.h
    src/gui/sections/gpusection/deviceoverview.cpp
    src/gui/sections/gpusection/deviceoverview.h
    src/gui/sections/gpusection/sectionheader.cpp
    src/gui/sections/gpusection/sectionheader.h
    resources.qrc
)

# Allow project sources to include headers by their short project-relative names.
target_include_directories(test PRIVATE
    src/backend
    src/backend/devices
    src/gui/mainwindow
    src/gui
    src/gui/sidebar
    src/gui/sections
    src/gui/sections/gpusection
)

# Link the GUI and GPU discovery dependencies into the executable.
target_link_libraries(test PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    OpenCL::OpenCL
   )

# Configure platform-specific executable packaging metadata.
set_target_properties(test PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install the executable using the platform's standard destination directories.
include(GNUInstallDirs)
install(TARGETS test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
