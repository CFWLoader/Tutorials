cmake_minimum_required(VERSION 3.2)
project(Class_Layout_in_Memory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Class_Layout_in_Memory ${SOURCE_FILES} TheClass.hpp ClassRecorder.hpp)