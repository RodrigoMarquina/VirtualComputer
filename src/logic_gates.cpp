#include "logic_gates.h"

//Implementations of the logic gates

//NAND gate definition
bool NAND(bool a, bool b){
    return !(a&&b);
}

bool NOT(bool a){
    return NAND(a, a);
}

bool AND(bool a, bool b){
    return NOT(NAND(a, b));
}

bool XOR(bool a, bool b){
    return AND(NAND(a,b), NAND(NOT(a), NOT(b)));
}

std::pair<bool, bool> HalfAdder(bool a, bool b){
    return std::make_pair(XOR(a, b), AND(a, b));
}