#include "cpu.h"
#include "memory.h"

void CPU::iterateCPU(){
    int counterIndex = binaryToDecimal(instructionCounter);
    std::array<bool, 16> currentInstruction = instructionMemory[counterIndex];
    std::array<bool, 4> upcode = {currentInstruction[0], currentInstruction[1], currentInstruction[2], currentInstruction[3]};
    std::array<bool, 12> addressA = {currentInstruction[4], currentInstruction[5], currentInstruction[6], currentInstruction[7], 
                                     currentInstruction[8], currentInstruction[9], currentInstruction[10], currentInstruction[11],
                                     currentInstruction[12], currentInstruction[13], currentInstruction[14], currentInstruction[15]};

    int addressAIndex = binaryToDecimal(addressA);
    if(upcode == std::array<bool, 4> {0, 1, 1, 1}){ //Load
        if(dataMemory[addressAIndex] == std::array<bool, 8> {0, 0, 0, 0, 0, 0, 0, 0}){
            zeroFlag = 1;
        } else{
            zeroFlag = 0;
        }
        if(dataMemory[addressAIndex][0] == 1){
            signFlag = 1;
        } else{
            signFlag = 0;
        }
        accumulator = dataMemory[addressAIndex];
        instructionCounter = incrementBinaryNumber(instructionCounter);
    }
    else if(upcode == std::array<bool, 4> {1, 0, 0, 0}){ //Store
        dataMemory[addressAIndex] = accumulator;
        instructionCounter = incrementBinaryNumber(instructionCounter);
    }
    else if(upcode == std::array<bool, 4> {1, 0, 0, 1}){ //Jump
        instructionCounter = {addressA[4], addressA[5], addressA[6], addressA[7], addressA[8], addressA[9], addressA[10], addressA[11]};
    }
    else if(upcode == std::array<bool, 4> {1, 0, 1, 0}){ //Jump if zero flag
        if(zeroFlag){
            instructionCounter = {addressA[4], addressA[5], addressA[6], addressA[7], addressA[8], addressA[9], addressA[10], addressA[11]};
        }
        else{
            instructionCounter = incrementBinaryNumber(instructionCounter);
        }
    }
    else if(upcode == std::array<bool, 4> {1, 0, 1, 1}){ //Jump if sign flag
        if(signFlag){
            instructionCounter = {addressA[4], addressA[5], addressA[6], addressA[7], addressA[8], addressA[9], addressA[10], addressA[11]};
        }
        else{
            instructionCounter = incrementBinaryNumber(instructionCounter);
        }
    }
    else{
        ALUStructure ALUOutput = ALU(dataMemory[addressAIndex], accumulator, std::array<bool, 3> {upcode[1], upcode[2], upcode[3]});
        zeroFlag = ALUOutput.zeroFlag;
        signFlag = ALUOutput.signFlag;
        accumulator = ALUOutput.c;
        instructionCounter = incrementBinaryNumber(instructionCounter);
    }    
}

std::array<bool, 8> CPU::getAccumulator(){
    return accumulator;
}

void CPU::setRegister(std::array<bool, 8> a, int index){
    dataMemory[index] = a;
}

std::array<bool, 8> CPU::getRegister(int index){
    return dataMemory[index];
}
