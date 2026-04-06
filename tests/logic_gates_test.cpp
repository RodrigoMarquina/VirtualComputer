#include "logic_gates.h"
#include <gtest/gtest.h>

TEST(NANDTest, Inputs00) {
    EXPECT_EQ(NAND(0,0), 1);
}

TEST(NANDTest, Inputs01) {
    EXPECT_EQ(NAND(0,1), 1);
}

TEST(NANDTest, Inputs10) {
    EXPECT_EQ(NAND(1,0), 1);
}

TEST(NANDTest, Inputs11) {
    EXPECT_EQ(NAND(1,1), 0);
}