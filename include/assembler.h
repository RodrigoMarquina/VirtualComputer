#pragma once

#include <array>
#include <fstream>
#include <string>

std::array<std::array<bool, 16>, 256> assembler(std::string assemblerCode);

template<std::size_t N>   
std::array<bool, N> decimalToBinary(int a){
    std::array<bool, N> c;
    for(int i = 0; i < N; i++){
        if((a & (1 << (N - i - 1))) >= 1){
            c[i] = 1;
        } else{
            c[i] = 0;
        }
    }
    return c;
}

