cmake_minimum_required(VERSION 3.4)
project(ocv_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(ocv_test ${SOURCE_FILES})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ocv_test ${OpenCV_LIBS})
