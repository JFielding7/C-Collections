cmake_minimum_required(VERSION 3.27)
project(C_Collections C)

set(CMAKE_C_STANDARD 11)

add_library(C_Collections STATIC
        vector.c
        vector.h)
