#include <iostream>
#include <limits>
#include "logic_gates.h" //angle brackets <> tell the compiler to look in the system include directories (where standard library headers like iostream live). Quotes "" tell it to look relative to your own project.
#include "cpu.h"
#include "minesweeper.h"

int main() {
    int input = 0;
    bool gameOver = false;
    bool running = true;
    std::array<std::array<bool, 16>, 256> assemblerMemory = assembler("Minesweeper.txt");
    CPU cpu;
    cpu.instructionMemory = assemblerMemory;
    cpu.setRegister({1, 0, 0, 0, 0, 0, 0, 0}, 18); //Revealed mask
    cpu.setRegister({0, 1, 0, 0, 0, 0, 0, 0}, 19); //Bomb mask
    cpu.setRegister({0, 0, 0, 0, 0, 0, 0, 0}, 20); //GameOver mask
    cpu.setRegister({0, 0, 0, 0, 0, 0, 0, 1}, 22);
    cpu.setRegister({0, 1, 1, 1, 0, 1, 0, 0}, 23);
    initializeGrid(cpu);
    displayGrid(cpu);

    while(!gameOver){
        running = true;
        input = decodeInput();
        cpu.setRegister(decimalToBinary<8>(input), 16);
        cpu.setRegister(cpu.getRegister(input), 17);
        while(running){
            running = cpu.iterateCPU();
        }
        if(cpu.getRegister(20)[0] == 1){
            gameOver = true;
            std::cout << "You hit a bomb! Game Over!\n";
        }
        if(cpu.getRegister(20)[1] == 1){
            gameOver = true;
            std::cout << "You've won! Party time!\n";
        }
        //std::cout << binaryToDecimal<8>(cpu.getRegister(21)); Check unrevealed counter
        cpu.setRegister(cpu.getRegister(17), binaryToDecimal<8>(cpu.getRegister(16)));
        displayGrid(cpu);
        cpu.resetCounter();
    }

    return 0;
}

