cmake_minimum_required(VERSION 3.2)
project(PureVirtualFunction)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PureVirtualFunction ${SOURCE_FILES} AbstractBase.cpp AbstractBase.h ConcreteDerived.cpp ConcreteDerived.h AbstractBase2.cpp AbstractBase2.h)