add_executable(virtual-computer-gtest
    virtual_computer_tests.cpp
)

target_link_libraries(virtual-computer-gtest virtual_computer_library gtest_main)

gtest_discover_tests(virtual-computer-gtest)

configure_file(AddTest.txt ${CMAKE_CURRENT_BINARY_DIR}/AddTest.txt COPYONLY)

configure_file(AddTest.txt ${CMAKE_CURRENT_BINARY_DIR}/SubTest.txt COPYONLY)

configure_file(JumpTest.txt ${CMAKE_CURRENT_BINARY_DIR}/JumpTest.txt COPYONLY)

configure_file(JumpZeroTestTrue.txt ${CMAKE_CURRENT_BINARY_DIR}/JumpZeroTestTrue.txt COPYONLY)

configure_file(JumpZeroTestFalse.txt ${CMAKE_CURRENT_BINARY_DIR}/JumpZeroTestFalse.txt COPYONLY)

configure_file(JumpSignTestTrue.txt ${CMAKE_CURRENT_BINARY_DIR}/JumpSignTestTrue.txt COPYONLY)

configure_file(JumpSignTestFalse.txt ${CMAKE_CURRENT_BINARY_DIR}/JumpSignTestFalse.txt COPYONLY)