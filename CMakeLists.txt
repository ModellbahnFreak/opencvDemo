cmake_minimum_required(VERSION 3.10)

project(OpenCVDemo VERSION 1.2)

find_package( OpenCV REQUIRED core highgui imgcodecs imgproc )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(OpenCVDemo src/main.cpp)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET (CMAKE_GENERATOR "Win32")
    set_property(TARGET OpenCVDemo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()

target_link_libraries( OpenCVDemo ${OpenCV_LIBS} )

set_property(TARGET OpenCVDemo PROPERTY CXX_STANDARD 17)
set_property(TARGET OpenCVDemo PROPERTY CXX_STANDARD_REQUIRED 17)