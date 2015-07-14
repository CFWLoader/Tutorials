project(TraitsClass)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(SOURCE_FILES
		AccumulationTraits.hpp
		Accumulation.hpp
		main.cpp
	)

add_executable(traitsClass ${SOURCE_FILES})

project(PolicyClass)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(SOURCE_FILES
		AccumulationTraits.hpp
		SumPolicy.hpp
		MultiPolicy.hpp
		Accumulation.hpp
		main.cpp
	)

add_executable(policyClass ${SOURCE_FILES})