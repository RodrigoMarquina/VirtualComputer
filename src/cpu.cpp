#include "cpu.h"
#include "memory.h"

void CPU::iterateCPU(){
    int counterIndex = binaryToDecimal(instructionCounter);
    std::array<bool, 8> currentInstruction = instructionMemory[counterIndex];
    std::array<bool, 4> upcode = {currentInstruction[0], currentInstruction[1], currentInstruction[2], currentInstruction[3]};
    std::array<bool, 4> addressA = {currentInstruction[4], currentInstruction[5], currentInstruction[6], currentInstruction[7]};

    int addressAIndex = binaryToDecimal(addressA);
    if(upcode == std::array<bool, 4> {0, 1, 1, 1}){ //Load
        accumulator = dataMemory[addressAIndex];
    }
    else if(upcode == std::array<bool, 4> {1, 0, 0, 0}){ //Store
        dataMemory[addressAIndex] = accumulator;
    }
    else{
        ALUStructure ALUOutput = ALU(dataMemory[addressAIndex], accumulator, std::array<bool, 3> {upcode[1], upcode[2], upcode[3]});
        accumulator = ALUOutput.c;
    }    
    instructionCounter = incrementBinaryNumber(instructionCounter);
}

std::array<bool, 8> CPU::getAccumulator(){
    return accumulator;
}

void CPU::setRegister(std::array<bool, 8> a, int index){
    dataMemory[index] = a;
}