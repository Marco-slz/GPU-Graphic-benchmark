# Build configuration for the Qt GPU graphics benchmark application.
cmake_minimum_required(VERSION 3.16)

project(test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

# Locate the GUI toolkit and OpenCL runtime used by the application.
find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
    Sql
)
find_package(OpenCL REQUIRED)


qt_standard_project_setup()

# Collect application sources, headers, and the compiled Qt resource manifest.
qt_add_executable(test
    src/main.cpp
    src/backend/devices/device.cpp
    src/backend/devices/device.h
    src/backend/devices/gpu.cpp
    src/backend/devices/gpu.h
    src/backend/database_management/database_management.cpp
    src/backend/database_management/database_management.h
    src/backend/gpu_scanner/gpu_scanner.cpp
    src/backend/gpu_scanner/gpu_scanner.h
    src/gui/main_window/main_window.cpp
    src/gui/main_window/main_window.h
    src/gui/image_label.cpp
    src/gui/image_label.h
    src/gui/sidebar/sidebar.cpp
    src/gui/sidebar/sidebar.h
    src/gui/sections/sections.cpp
    src/gui/sections/sections.h
    src/gui/sections/gpu_section/gpu_section.cpp
    src/gui/sections/gpu_section/gpu_section.h
    src/gui/sections/gpu_section/gpu_selector.cpp
    src/gui/sections/gpu_section/gpu_selector.h
    src/gui/sections/gpu_section/device_overview.cpp
    src/gui/sections/gpu_section/device_overview.h
    src/gui/sections/gpu_section/section_header.cpp
    src/gui/sections/gpu_section/section_header.h
    resources.qrc
)

# Allow project sources to include headers by their short project-relative names.
target_include_directories(test PRIVATE
    src/backend
    src/backend/devices
    src/backend/database_management
    src/backend/gpu_scanner
    src/gui/main_window
    src/gui
    src/gui/sidebar
    src/gui/sections
    src/gui/sections/gpu_section
)

# Link the GUI and GPU discovery dependencies into the executable.
target_link_libraries(test PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt6::Sql
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
