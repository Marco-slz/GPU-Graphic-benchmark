cmake_minimum_required(VERSION 3.16)

project(test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS 
    Widgets
)
find_package(OpenCL REQUIRED)


qt_standard_project_setup()

qt_add_executable(test
    src/main.cpp
    src/backend/devices/device.cpp
    src/backend/devices/device.h
    src/backend/gpuscanner.cpp
    src/backend/gpuscanner.h
    src/gui/mainwindow/mainwindow.cpp
    src/gui/mainwindow/mainwindow.h
    src/gui/sidebar/sidebar.cpp
    src/gui/sidebar/sidebar.h
    src/gui/sections/sections.cpp
    src/gui/sections/sections.h
    src/gui/sections/gpusection/gpusection.cpp
    src/gui/sections/gpusection/gpusection.h
    src/gui/sections/gpusection/sectionheader.cpp
    src/gui/sections/gpusection/sectionheader.h
    resources.qrc
)

target_include_directories(test PRIVATE
    src/backend
    src/backend/devices
    src/gui/mainwindow
    src/gui/sidebar
    src/gui/sections
    src/gui/sections/gpusection
)

target_link_libraries(test PRIVATE 
    Qt${QT_VERSION_MAJOR}::Widgets
    OpenCL::OpenCL
   )

set_target_properties(test PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
