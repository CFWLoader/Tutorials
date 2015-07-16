project(PromotionTraits)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -g")

set(SOURCE_FILES
		IfThenElse.hpp
		Promote.hpp
		PromoteInstances.hpp
		main.cpp
	)

add_executable(promotionTraits ${SOURCE_FILES})