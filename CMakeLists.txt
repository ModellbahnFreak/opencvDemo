cmake_minimum_required(VERSION 3.10)

project(OpenCVDemo VERSION 1.2)
enable_testing()

find_package( OpenCV REQUIRED core highgui imgcodecs imgproc )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(OpenCVDemo
    src/main.cpp
    "src/loadmanipulate.cpp"
    "include/loadmanipulate.hpp")

add_executable(OpenCVTests 
    "src/loadmanipulate.cpp"
    "include/loadmanipulate.hpp"
    "test/test_loadmaniputale.cpp"
        test/test_arithmetic.cpp 
        )

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET (CMAKE_GENERATOR "Win32")
    set_property(TARGET OpenCVDemo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endif()

target_link_libraries( OpenCVDemo ${OpenCV_LIBS} )
target_link_libraries( OpenCVTests ${OpenCV_LIBS} )
target_link_libraries( OpenCVTests gtest_main )

set_property(TARGET OpenCVDemo PROPERTY CXX_STANDARD 17)
set_property(TARGET OpenCVDemo PROPERTY CXX_STANDARD_REQUIRED 17)
gtest_discover_tests(OpenCVTests)