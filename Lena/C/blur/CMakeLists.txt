cmake_minimum_required(VERSION 3.6)
project(C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c qdbmp.c)

add_executable(C ${SOURCE_FILES})