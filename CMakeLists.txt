cmake_minimum_required(VERSION 3.5)
project(pb071_ctools)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c99")

include_directories("headers/")


set(SOURCE_FILES lib/CHelpers.c)
set(SOURCE_FILES_TEST ${SOURCE_FILES} tests/tests.c)
set(SOURCE_FILES_MAIN ${SOURCE_FILES} example/main.c)
add_executable(pb071_test ${SOURCE_FILES_TEST})
add_executable(pb071_example ${SOURCE_FILES_MAIN})