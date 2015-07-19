project(CompoundTypeDifferentiator)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

set (SOURCE_FILES
		CompoundType.hpp
		main.cpp
	)

add_executable(compundTypeDifferentiator ${SOURCE_FILES})