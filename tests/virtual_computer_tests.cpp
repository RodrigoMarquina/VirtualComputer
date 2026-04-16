#include "logic_gates.h"
#include "alu.h"
#include "memory.h"
#include "cpu.h"
#include "assembler.h"
#include "minesweeper.h"
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

//OR Gate
TEST(ORTest, Input00){
    EXPECT_EQ(OR(0, 0), 0);
}

TEST(ORTest, Input01){
    EXPECT_EQ(OR(0, 1), 1);
}

TEST(ORTest, Input10){
    EXPECT_EQ(OR(1, 0), 1);
}

TEST(ORTest, Input11){
    EXPECT_EQ(OR(1, 1), 1);
}

//Half Adder
TEST(HalfAdderTest, Inputs00){
    EXPECT_EQ(HalfAdder(0, 0), std::make_pair(0, 0));
}

TEST(HalfAdderTest, Inputs01){
    EXPECT_EQ(HalfAdder(0, 1), std::make_pair(1, 0));
}

TEST(HalfAdderTest, Inputs10){
    EXPECT_EQ(HalfAdder(1, 0), std::make_pair(1, 0));
}

TEST(HalfAdderTest, Inputs11){
    EXPECT_EQ(HalfAdder(1, 1), std::make_pair(0, 1));
}

//Full Adder
TEST(FullAdderTest, Inputs000){
    EXPECT_EQ(FullAdder(0, 0, 0), std::make_pair(0, 0));
}

TEST(FullAdderTest, Inputs001){
    EXPECT_EQ(FullAdder(0, 0, 1), std::make_pair(1, 0));
}

TEST(FullAdderTest, Inputs010){
    EXPECT_EQ(FullAdder(0, 1, 0), std::make_pair(1, 0));
}

TEST(FullAdderTest, Inputs011){
    EXPECT_EQ(FullAdder(0, 1, 1), std::make_pair(0, 1));
}

TEST(FullAdderTest, Inputs100){
    EXPECT_EQ(FullAdder(1, 0, 0), std::make_pair(1, 0));
}

TEST(FullAdderTest, Inputs101){
    EXPECT_EQ(FullAdder(1, 0, 1), std::make_pair(0, 1));
}

TEST(FullAdderTest, Inputs110){
    EXPECT_EQ(FullAdder(1, 1, 0), std::make_pair(0, 1));
}

TEST(FullAdderTest, Inputs111){
    EXPECT_EQ(FullAdder(1, 1, 1), std::make_pair(1, 1));
}

//MUX
TEST(MUXTest, Inputs000){
    EXPECT_EQ(MUX(0, 0, 0), 0);
}

TEST(MUXTest, Inputs001){
    EXPECT_EQ(MUX(0, 0, 1), 0);
}

TEST(MUXTest, Inputs010){
    EXPECT_EQ(MUX(0, 1, 0), 1);
}

TEST(MUXTest, Inputs011){
    EXPECT_EQ(MUX(0, 1, 1), 1);
}

TEST(MUXTest, Inputs100){
    EXPECT_EQ(MUX(1, 0, 0), 0);
}

TEST(MUXTest, Inputs101){
    EXPECT_EQ(MUX(1, 0, 1), 1);
}

TEST(MUXTest, Inputs110){
    EXPECT_EQ(MUX(1, 1, 0), 0);
}

TEST(MUXTest, Inputs111){
    EXPECT_EQ(MUX(1, 1, 1), 1);
}

//ALU
TEST(ALUTest, SignFlagTest){
    std::array<bool, 8> a = {0, 0, 0, 0, 0, 0, 1, 0};
    std::array<bool, 8> b = {1, 0, 0, 0, 0, 1, 0, 0};
    std::array<bool, 3> upcode = {0, 0, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 0, 0, 0, 0, 1, 1, 0};

    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, ZeroFlagTest){
    std::array<bool, 8> a = {0, 0, 0, 0, 0, 1, 0, 0};
    std::array<bool, 8> b = {1, 1, 1, 1, 1, 1, 0, 0};
    std::array<bool, 3> upcode = {0, 0, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {0, 0, 0, 0, 0, 0, 0, 0};

    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 0);
    EXPECT_EQ(result.zeroFlag, 1);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, OverFlowFlagTest){
    std::array<bool, 8> a = {0, 1, 1, 1, 1, 1, 1, 1};
    std::array<bool, 8> b = {0, 0, 0, 0, 0, 0, 0, 1};
    std::array<bool, 3> upcode = {0, 0, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 1);
}

TEST(ALUTest, ADDTest){
    std::array<bool, 8> a = {0, 0, 0, 1, 0, 1, 1, 0};
    std::array<bool, 8> b = {0, 0, 1, 0, 1, 0, 1, 0};
    std::array<bool, 3> upcode = {0, 0, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {0, 1, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 0);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, SUBTest){
    std::array<bool, 8> a = {0, 0, 1, 1, 0, 1, 1, 1};
    std::array<bool, 8> b = {0, 1, 0, 0, 0, 1, 1, 0};
    std::array<bool, 3> upcode = {0, 0, 1};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 1, 1, 1, 0, 0, 0, 1};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, NOTTest){
    std::array<bool, 8> a = {0, 0, 1, 1, 0, 1, 0, 1};
    std::array<bool, 8> b = {0, 1, 0, 1, 0, 1, 0, 0};
    std::array<bool, 3> upcode = {0, 1, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 1, 0, 0, 1, 0, 1, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, ANDTest){
    std::array<bool, 8> a = {0, 1, 1, 1, 1, 1, 0, 1};
    std::array<bool, 8> b = {0, 1, 0, 1, 1, 0, 1, 0};
    std::array<bool, 3> upcode = {0, 1, 1};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {0, 1, 0, 1, 1, 0, 0, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 0);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, ORTest){
    std::array<bool, 8> a = {1, 0, 0, 0, 1, 1, 0, 0};
    std::array<bool, 8> b = {0, 1, 1, 0, 1, 0, 1, 0};
    std::array<bool, 3> upcode = {1, 0, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 1, 1, 0, 1, 1, 1, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, NANDTest){
    std::array<bool, 8> a = {0, 1, 0, 0, 1, 1, 0, 1};
    std::array<bool, 8> b = {1, 0, 0, 1, 1, 0, 1, 1};
    std::array<bool, 3> upcode = {1, 0, 1};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {1, 1, 1, 1, 0, 1, 1, 0};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 1);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

TEST(ALUTest, XORTest){
    std::array<bool, 8> a = {0, 1, 1, 1, 0, 0, 0, 1};
    std::array<bool, 8> b = {0, 0, 1, 1, 0, 1, 1, 0};
    std::array<bool, 3> upcode = {1, 1, 0};
    ALUStructure result = ALU(a, b, upcode);

    std::array<bool, 8> c = {0, 1, 0, 0, 0, 1, 1, 1};
    EXPECT_EQ(result.c, c);
    EXPECT_EQ(result.signFlag, 0);
    EXPECT_EQ(result.zeroFlag, 0);
    EXPECT_EQ(result.overflowFlag, 0);
}

//SRLatch
TEST(SRLatchTest, Inputs00){
    EXPECT_EQ(SRLatch(0, 0, 1), 1);
}

TEST(SRLatchTest, Inputs01){
    EXPECT_EQ(SRLatch(0, 1, 0), 0);
}

TEST(SRLatchTest, Inputs10){
    EXPECT_EQ(SRLatch(1, 0, 0), 1);
}

TEST(SRLatchTest, Inputs11){
    EXPECT_THROW(SRLatch(1, 1, 0), std::runtime_error);
}

//Register
TEST(Register, Write){
    std::array<bool, 8> d = {0, 1, 1, 1, 0, 0, 0, 1};
    bool we = 1;
    bool reset = 0;
    std::array<bool, 8> q = {0, 0, 1, 1, 0, 0, 0, 0};
    std::array<bool, 8> output = Register(d, we, reset, q);

    std::array<bool, 8> expected = {0, 1, 1, 1, 0, 0, 0, 1};
    EXPECT_EQ(output, expected);
}

TEST(Register, Hold){
    std::array<bool, 8> d = {1, 0, 0, 1, 0, 0, 0, 0};
    bool we = 0;
    bool reset = 0;
    std::array<bool, 8> q = {0, 1, 0, 0, 0, 1, 0, 1};
    std::array<bool, 8> output = Register(d, we, reset, q);

    std::array<bool, 8> expected = {0, 1, 0, 0, 0, 1, 0, 1};
    EXPECT_EQ(output, expected);
}

TEST(Register, Reset){
    std::array<bool, 8> d = {0, 1, 0, 0, 0, 0, 0, 1};
    bool we = 0;
    bool reset = 1;
    std::array<bool, 8> q = {0, 1, 0, 0, 0, 1, 0, 1};
    std::array<bool, 8> output = Register(d, we, reset, q);

    std::array<bool, 8> expected = {0, 0, 0, 0, 0, 0, 0, 0};
    EXPECT_EQ(output, expected);
}

//CPU
TEST(CPU, Load){
    CPU cpuTest;
    cpuTest.setRegister(std::array<bool, 8> {0, 1, 0, 1, 0, 1, 0, 1}, 8);
    cpuTest.instructionMemory[0] = std::array<bool, 8> {0, 1, 1, 1, 1, 0, 0, 0}; //Upcode goes first
    
    cpuTest.iterateCPU();

    std::array<bool, 8> output = cpuTest.getAccumulator();
    std::array<bool, 8> expected = {0, 1, 0, 1, 0, 1, 0, 1};
    EXPECT_EQ(output, expected);
}

TEST(CPU, Store){
    CPU cpuTest;
    cpuTest.setRegister(std::array<bool, 8> {1, 1, 1, 1, 1, 1, 1, 1}, 2);
    cpuTest.instructionMemory[0] = std::array<bool, 8> {0, 1, 1, 1, 0, 0, 1, 0}; //Loads register 2 to the accumulator
    cpuTest.instructionMemory[1] = std::array<bool, 8> {1, 0, 0, 0, 0, 1, 0, 0}; //Stores value from accumulator to register 4

    cpuTest.iterateCPU();
    cpuTest.iterateCPU();

    std::array<bool, 8> output = cpuTest.getRegister(4);
    std::array<bool, 8> expected = {1, 1, 1, 1, 1, 1, 1, 1};
    EXPECT_EQ(output, expected);  
}

TEST(CPU, Add){
    CPU cpuTest;
    cpuTest.setRegister(std::array<bool, 8> {0, 1, 0, 0, 0, 1, 0, 1}, 10);
    cpuTest.setRegister(std::array<bool, 8> {0, 0, 0, 0, 0, 0, 1, 1}, 12);
    cpuTest.instructionMemory[0] = std::array<bool, 8> {0, 1, 1, 1, 1, 0, 1, 0}; 
    cpuTest.instructionMemory[1] = std::array<bool, 8> {0, 0, 0, 0, 1, 1, 0, 0};

    cpuTest.iterateCPU();
    cpuTest.iterateCPU();

    std::array<bool, 8> output = cpuTest.getAccumulator();
    std::array<bool, 8> expected = {0, 1, 0, 0, 1, 0, 0, 0};
    EXPECT_EQ(output, expected);
}

//Assembler
TEST(Assembler, decimalToByteTest){
    std::array<bool, 8> output = decimalToByte(5);
    std::array<bool, 8> expected = {0, 0, 0, 0, 0, 1, 0, 1};
    EXPECT_EQ(output, expected);
}

TEST(Assembler, addTest){
    std::array<std::array<bool, 8>, 256> assemblerMemory = assembler("AssemblerCodeTest.txt");

    CPU cpuTest;
    cpuTest.instructionMemory = assemblerMemory;

    cpuTest.setRegister(std::array<bool, 8> {0, 0, 0, 0, 0, 1, 0, 1}, 0);
    cpuTest.setRegister(std::array<bool, 8> {0, 0, 0, 1, 0, 1, 0, 1}, 1);
    cpuTest.setRegister(std::array<bool, 8> {0, 1, 0, 0, 0, 0, 0, 0}, 2);

    cpuTest.iterateCPU();
    cpuTest.iterateCPU();
    cpuTest.iterateCPU();
    cpuTest.iterateCPU();
    
    std::array<bool, 8> output = cpuTest.getAccumulator();
    std::array<bool, 8> expected = {0, 1, 0, 1, 1, 0, 1, 0};
    EXPECT_EQ(output, expected);
}

