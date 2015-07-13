project(ConstraintsClass)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(SOURCE_FILES
		HasClone.hpp
		PseudoComponent.hpp
		TestClass.h
		TestClass.cpp
		main.cpp
	)

add_executable(constraintClass ${SOURCE_FILES})