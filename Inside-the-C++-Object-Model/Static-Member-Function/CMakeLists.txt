cmake_minimum_required(VERSION 3.2)
project(Static_Member_Function)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Static_Member_Function ${SOURCE_FILES})