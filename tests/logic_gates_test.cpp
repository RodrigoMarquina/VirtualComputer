#include "logic_gates.h"
#include <gtest/gtest.h>

//NAND Gate
TEST(NANDTest, Inputs00){
    EXPECT_EQ(NAND(0, 0), 1);
}

TEST(NANDTest, Inputs01){
    EXPECT_EQ(NAND(0, 1), 1);
}

TEST(NANDTest, Inputs10){
    EXPECT_EQ(NAND(1, 0), 1);
}

TEST(NANDTest, Inputs11){
    EXPECT_EQ(NAND(1, 1), 0);
}

//Not Gate
TEST(NOTTest, Input0){
    EXPECT_EQ(NOT(0), 1);
}

TEST(NOTTest, Input1){
    EXPECT_EQ(NOT(1), 0);
}

//AND Gate
TEST(ANDTest, Input00){
    EXPECT_EQ(AND(0, 0), 0);
}

TEST(ANDTest, Input01){
    EXPECT_EQ(AND(0, 1), 0);
}

TEST(ANDTest, Input10){
    EXPECT_EQ(AND(1, 0), 0);
}

TEST(ANDTest, Input11){
    EXPECT_EQ(AND(1, 1), 1);
}

//XOR Gate
TEST(XORTest, Input00){
    EXPECT_EQ(XOR(0, 0), 0);
}

TEST(XORTest, Input01){
    EXPECT_EQ(XOR(0, 1), 1);
}

TEST(XORTest, Input10){
    EXPECT_EQ(XOR(1, 0), 1);
}

TEST(XORTest, Input11){
    EXPECT_EQ(XOR(1, 1), 0);
}

//Half Adder
TEST(HalfAdderTest, Inputs00){
    EXPECT_EQ(HalfAdder(0,0), std::make_pair(0, 0));
}

TEST(HalfAdderTest, Inputs01){
    EXPECT_EQ(HalfAdder(0,1), std::make_pair(1, 0));
}

TEST(HalfAdderTest, Inputs10){
    EXPECT_EQ(HalfAdder(1,0), std::make_pair(1, 0));
}

TEST(HalfAdderTest, Inputs11){
    EXPECT_EQ(HalfAdder(1,1), std::make_pair(0, 1));
}