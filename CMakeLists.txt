cmake_minimum_required(VERSION 3.5)
project(pnk-linked-list VERSION 1.1)

set(library-source
	inc/pnk/linked_list.h
	src/linked_list.c
)

add_library(pnk-linked-list INTERFACE)
target_include_directories(pnk-linked-list INTERFACE inc)
target_compile_features(pnk-linked-list INTERFACE c_std_99)

add_executable(init_test tests/init_test.c ${library-source})
add_executable(insert_test tests/insert_test.c ${library-source})

target_link_libraries(init_test PRIVATE pnk-linked-list)
target_link_libraries(insert_test PRIVATE pnk-linked-list)