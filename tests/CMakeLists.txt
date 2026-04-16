add_executable(virtual-computer-gtest
    virtual_computer_tests.cpp
)

target_link_libraries(virtual-computer-gtest virtual_computer_library gtest_main)

gtest_discover_tests(virtual-computer-gtest)