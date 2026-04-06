cmake_minimum_required(VERSION 3.16)
project(VirtualComputer)

set(CMAKE_CXX_STANDARD 20)

add_executable(virtual-computer
    src/main.cpp
    src/logic_gates.cpp
)

target_include_directories(virtual-computer PRIVATE include)