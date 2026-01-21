cmake_minimum_required(VERSION 3.16)
project(VirtualComputer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER clang++)

add_executable(virtual_computer
    src/main.cpp
)
