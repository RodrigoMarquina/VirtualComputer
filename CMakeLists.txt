cmake_minimum_required(VERSION 3.16)
project(VirtualComputer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

option(BUILD_TESTS "Build Unit Tests" ON)
if(BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

add_executable(virtual-computer
    src/logic_gates.cpp
    src/alu.cpp
    src/memory.cpp
    src/cpu.cpp
    src/minesweeper.cpp
    src/main.cpp
)

add_library(virtual_computer_library STATIC src/logic_gates.cpp src/alu.cpp src/memory.cpp src/cpu.cpp src/minesweeper.cpp)

target_include_directories(virtual_computer_library PUBLIC include)

target_link_libraries(virtual-computer virtual_computer_library)