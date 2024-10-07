cmake_minimum_required(VERSION 3.5)
project(LWIR_Camera)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(OpenCV REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(HDF5 REQUIRED)
include_directories(inc ${OpenCV_INCLUDE_DIRS} ${HDF5_INCLUDE_DIRS} ) 
link_directories(lib)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)
set(SOURCES
    src/main.cpp
    src/Camera.cpp
    src/SerialPort.cpp
    src/MainWindow.cpp
    src/ConstructDialog.cpp
    src/mat2bmp.cpp
    src/curve.cpp
    src/SpectralPlotWidget.cpp
    src/daheng_camera.cpp
    src/cam_info.cpp
)
set(HEADERS
    inc/MainWindow.h
    inc/ConstructDialog.h
    inc/mat2bmp.h
    inc/curve.h
    inc/SpectralPlotWidget.h
    inc/daheng_camera.h
    inc/DxImageProc.h
    inc/GxIAPI.h
    inc/cam_info.h

)
add_executable(LWIR_Camera ${SOURCES} ${HEADERS})
target_link_libraries(LWIR_Camera ${OpenCV_LIBS} Qt5::Widgets ${HDF5_LIBRARIES} gxiapi) 
