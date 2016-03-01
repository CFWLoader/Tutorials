cmake_minimum_required(VERSION 2.6)

project(ConcurrencyStack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ConcurrencyStack.hpp ConcurrencyStackDecl.hpp)

add_executable(ConcurrencyStack ${SOURCE_FILES})