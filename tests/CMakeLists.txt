add_executable(virtual-computer-gtest
    logic_gates_test.cpp
)

target_link_libraries(virtual-computer-gtest logic_gates gtest_main)

gtest_discover_tests(virtual-computer-gtest)