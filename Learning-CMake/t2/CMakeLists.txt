project(HELLO)

install(FILES COPYRIGHT README.md DESTINATION /home/cfwloader/Documents/Pseudo/cmake/t2)

install(PROGRAMS runHello.sh DESTINATION /home/cfwloader/Documents/Pseduo/bin)

install(DIRECTORY doc/ DESTINATION /home/cfwloader/Documents/Pseudo/doc)

add_subdirectory(src bin)
