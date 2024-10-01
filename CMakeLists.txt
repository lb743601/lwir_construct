cmake_minimum_required(VERSION 3.5)

project(LWIR_Camera)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenCV REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Enable automatic MOC, UIC, and RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Specify additional search paths for UIC
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

# Include directories
include_directories(inc ${OpenCV_INCLUDE_DIRS})

# Source and header files
set(SOURCES
    src/main.cpp
    src/Camera.cpp
    src/SerialPort.cpp
    src/MainWindow.cpp
    src/ConstructDialog.cpp
)

set(HEADERS
    inc/MainWindow.h
    inc/ConstructDialog.h
)

# Add executable
add_executable(LWIR_Camera ${SOURCES} ${HEADERS})

# Link libraries
target_link_libraries(LWIR_Camera ${OpenCV_LIBS} Qt5::Widgets)
