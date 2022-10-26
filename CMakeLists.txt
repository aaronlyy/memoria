cmake_minimum_required(VERSION 3.23)
project(memoria)

set(CMAKE_CXX_STANDARD 23)

add_executable(memoria src/main.cpp src/memoria.h src/memoria.cpp src/offsets.h)
