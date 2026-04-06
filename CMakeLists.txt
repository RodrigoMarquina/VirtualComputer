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
    src/main.cpp
)

add_library(logic_gates STATIC src/logic_gates.cpp)

target_include_directories(logic_gates PUBLIC include)

target_link_libraries(virtual-computer logic_gates)