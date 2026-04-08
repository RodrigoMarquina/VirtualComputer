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
    bool G1 = NAND(a, b);
    return NAND(NAND(a, G1), NAND(G1, b));
}

bool OR(bool a, bool b){
    return NAND(NOT(a), NOT(b));
}

std::pair<bool, bool> HalfAdder(bool a, bool b){
    return std::make_pair(XOR(a, b), AND(a, b));
}

std::pair<bool, bool> FullAdder(bool a, bool b, bool c){
    std::pair<bool, bool> HA1 = HalfAdder(a, b);
    std::pair<bool, bool> HA2 = HalfAdder(HA1.first, c);
    return std::make_pair(HA2.first, OR(HA1.second, HA2.second));
}

//bool OverFlow()

bool MUX(bool sel, bool a, bool b){
    return OR(AND(a, NOT(sel)), AND(b, sel));
}