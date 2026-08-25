cmake_minimum_required(VERSION 3.21)
project(C_code C)

set(CMAKE_C_STANDARD 99)

add_executable(C_code main.c gameFunctions.h gamefunctions1.c gamefunctions1.h)
