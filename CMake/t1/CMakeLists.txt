project(HELLO)

set(SRC_LIST main.c)

message(STATUS "This is binary dir " ${HELLO_BINARY_DIR})

message(STATUS "This is source dir " ${HELLO_SOURCE_DIR})

add_executable(hello ${SRC_LIST})
