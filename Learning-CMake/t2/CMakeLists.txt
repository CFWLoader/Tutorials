project(HELLO)

add_subdirectory(src bin)

install(FILES COPYRIGHT README.md DESTINATION Pseudo/cmake/t2)

install(PROGRAMS runHello.sh DESTINATION Pseudo/bin)

install(DIRECTORY doc/ DESTINATION Pseudo/doc)
