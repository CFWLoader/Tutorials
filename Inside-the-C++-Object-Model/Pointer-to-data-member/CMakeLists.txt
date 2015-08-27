cmake_minimum_required(VERSION 3.2)
project(Pointer_to_data_member)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Pointer_to_data_member ${SOURCE_FILES}  Point.hpp)