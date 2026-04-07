#pragma once

#include <iostream>
#include <utility>

//Header file with the declarations of the logic gates.

//NAND gate declaration
bool NAND(bool a, bool b); 

bool NOT(bool a);

bool AND(bool a, bool b);

bool XOR(bool a, bool b);

bool OR(bool a, bool b);

std::pair<bool, bool> HalfAdder(bool a, bool b);

std::pair<bool, bool> FullAdder(bool a, bool b, bool c);