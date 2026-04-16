#pragma once

#include <array>

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

template<std::size_t N>                                                                                                                                                                                                              
int binaryToDecimal(std::array<bool, N> a){
    int total = 0;
    for(int i = N - 1; i >= 0; i--){
        total += a[N - i - 1] * (1 << i);
    }
    return total;
}

template<std::size_t N>
std::array<bool, N> incrementBinaryNumber(std::array<bool, N> a){
    std::array<bool, N> output;
    bool carry = 1;
    for(int i = N - 1; i >= 0; i--){
        std::pair<bool, bool> iterationSum = FullAdder(a[i], 0, carry);
        output[i] = iterationSum.first;
        carry = iterationSum.second;
    }
    return output;
}