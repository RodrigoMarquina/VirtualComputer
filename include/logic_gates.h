#pragma once

#include <iostream>
#include <utility>
#include <array>

//Header file with the declarations of the logic gates.

//NAND gate declaration
bool NAND(bool a, bool b); 

bool NOT(bool a);

bool AND(bool a, bool b);

bool XOR(bool a, bool b);

bool OR(bool a, bool b);

std::pair<bool, bool> HalfAdder(bool a, bool b);

std::pair<bool, bool> FullAdder(bool a, bool b, bool c);

bool MUX(bool sel, bool a, bool b);

struct ALUStructure{
    std::array<bool, 8> c;
    bool signFlag;
    bool zeroFlag;
    bool overflowFlag;
};

ALUStructure MUXFields(bool sel, ALUStructure field1, ALUStructure field2);

ALUStructure ALU(std::array<bool, 8> a, std::array<bool, 8> b, std::array<bool, 3> upcode);