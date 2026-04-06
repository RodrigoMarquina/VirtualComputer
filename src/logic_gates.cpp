//Implementations of the logic gates

//NAND gate definition
bool NAND(bool a, bool b){
    return !(a&&b);
}

bool NOT(bool a){
    return NAND(a, a);
}