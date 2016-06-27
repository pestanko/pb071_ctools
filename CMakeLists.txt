cmake_minimum_required(VERSION 3.5)
project(pb071_ctools)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c99 -g")

include_directories("include/")


set(SOURCE_FILES src/CHelpers.c src/vector.c)
set(SOURCE_FILES_TEST ${SOURCE_FILES} tests/tests.c )
set(SOURCE_FILES_MAIN ${SOURCE_FILES} example/main.c)
add_executable(pb071_test_tools ${SOURCE_FILES_TEST})
add_executable(pb071_test_vector ${SOURCE_FILES} tests/vector.c)
add_executable(pb071_example ${SOURCE_FILES_MAIN})
add_executable(play_vector ${SOURCE_FILES} example/vector_play.c)