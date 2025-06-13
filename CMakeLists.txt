cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_FLAGS "-O3")

set(PROJECT_NAME "CCT")

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} STATIC mat.c option.c string.c vector.c)