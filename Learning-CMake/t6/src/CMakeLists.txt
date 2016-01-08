find_package(HELLO)

if(HELLO_FOUND)
	add_executable(hello main.c)
	include_directories(${HELLO_INCLUDE_DIR})
	target_link_libraries(hello ${HELLO_LIBRARY})
else(HELLO_FOUND)
	message(STATUS "HELLO_FOUND?")
endif(HELLO_FOUND)
