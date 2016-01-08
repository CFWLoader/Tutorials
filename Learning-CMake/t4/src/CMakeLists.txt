set(CMAKE_INCLUDE_DIRECTORIES_DEFORE on)

include_directories(/home/cfwloader/Documents/Pseudo/t3/headers)

link_directories(/home/cfwloader/Documents/Pseudo/t3/lib)

add_executable(main main.c)

target_link_libraries(main hello)
