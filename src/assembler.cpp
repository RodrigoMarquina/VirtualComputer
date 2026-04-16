#include "assembler.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

std::array<bool, 8> decimalToByte(int a){
    if(a > 255){
        throw std::runtime_error("Cant convert number to byte, number out of range!");
    }

    std::array<bool, 8> c;
    for(int i = 0; i < 8; i++){
        if((a & (1 << (7 - i))) >= 1){
            c[i] = 1;
        } else{
            c[i] = 0;
        }
    }
    return c;
}

std::array<std::array<bool, 8>, 256> assembler(std::string assemblerCode){
    std::ifstream assemblerFile(assemblerCode);
    std::string line;
    std::array<std::array<bool, 8>, 256> assemblerMemory;
    int i = 0;

    if(!assemblerFile.is_open()){                                                                                                                                                                                                             
      throw std::runtime_error("Could not open file: " + assemblerCode);                                                                                                                                                                    
    } 

    while(getline(assemblerFile, line)){
        std::istringstream lineStream(line);
        std::string command;
        int memoryIndex;

        lineStream >> command;
        lineStream >> memoryIndex;

        if(memoryIndex > 15 || memoryIndex < 0){
            throw std::runtime_error("Incorrect command");
        }

        std::array<bool, 8> instruction;
        instruction = decimalToByte(memoryIndex);
        if(command == "ADD"){
            instruction[0] = 0;
            instruction[1] = 0;
            instruction[2] = 0;
            instruction[3] = 0;
        } else if(command == "SUB"){
            instruction[0] = 0;
            instruction[1] = 0;
            instruction[2] = 0;
            instruction[3] = 1;
        } else if(command == "NOT"){
            instruction[0] = 0;
            instruction[1] = 0;
            instruction[2] = 1;
            instruction[3] = 0;
        } else if(command == "AND"){
            instruction[0] = 0;
            instruction[1] = 0;
            instruction[2] = 1;
            instruction[3] = 1;
        } else if(command == "OR"){
            instruction[0] = 0;
            instruction[1] = 1;
            instruction[2] = 0;
            instruction[3] = 0;
        } else if(command == "NAND"){
            instruction[0] = 0;
            instruction[1] = 1;
            instruction[2] = 0;
            instruction[3] = 1;
        } else if(command == "XOR"){
            instruction[0] = 0;
            instruction[1] = 1;
            instruction[2] = 1;
            instruction[3] = 0;
        } else if(command == "LOAD"){
            instruction[0] = 0;
            instruction[1] = 1;
            instruction[2] = 1;
            instruction[3] = 1;
        } else if(command == "STORE"){
            instruction[0] = 1;
            instruction[1] = 0;
            instruction[2] = 0;
            instruction[3] = 0;
        } else{
            throw std::runtime_error("Incorrect command");
        }
        assemblerMemory[i] = instruction;
        i++;
    }

    assemblerFile.close();

    return assemblerMemory;
}
