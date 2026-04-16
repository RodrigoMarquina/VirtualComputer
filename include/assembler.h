#pragma once

#include <array>
#include <fstream>
#include <string>

std::array<std::array<bool, 8>, 256> assembler(std::string assemblerCode);

std::array<bool, 8> decimalToByte(int a);

