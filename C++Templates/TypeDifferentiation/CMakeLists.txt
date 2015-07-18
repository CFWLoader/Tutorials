project(TypeDifferentiation)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

set(SOURCE_FILES
		TypeDifferentiator.hpp
		main.cpp
	)

add_executable(typeDifferetiator ${SOURCE_FILES})