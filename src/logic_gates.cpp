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
