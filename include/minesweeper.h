#include "cpu.h"
#include "assembler.h"
#include <string>
#include <limits>

void fillRegisters(CPU& cpu, int val);

void displayGrid(CPU& cpu);

void initializeGrid(CPU& cpu);

int decodeInput();