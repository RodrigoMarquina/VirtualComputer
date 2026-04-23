#include "minesweeper.h"
#include <cstdlib>

int gridSize = 16;

void fillRegisters(CPU& cpu, int val){
    for(int i = 0; i < gridSize; i++){
        cpu.setRegister(decimalToBinary<8>(val), i);
    }
}

void displayGrid(CPU& cpu){
    int num;
    std::cout << "┌——————————————┐\n";
    for(int i = 0; i < gridSize; i++){
        if((i % 4) == 0){
            std::cout << "| ";
        }
        if(cpu.getRegister(i)[0] == 0){
            std::cout << "[ ]";
        } else{
            if(cpu.getRegister(i)[1] == 1){
                std::cout << " X ";
            } else{
                num = binaryToDecimal<4>(std::array<bool, 4> {cpu.getRegister(i)[4], cpu.getRegister(i)[5], cpu.getRegister(i)[6], cpu.getRegister(i)[7]});
                if(num == 0){
                    std::cout << "   ";
                } else{
                    std::cout << " " + std::to_string(num) + " ";
                }
            }
        }
        if((i % 4) == 3){
            std::cout << " |";
            std::cout << "\n";
        } 
    }
    std::cout << "└——————————————┘\n";
}

void initializeGrid(CPU& cpu){
    std::array<int, 8> deltaR = {-1, -1, -1, 0, 0, 1, 1, 1};
    std::array<int, 8> deltaC = {-1, 0, 1, -1, 1, -1, 0, 1};
    std::array<int, 4> mines = {-1, -1, -1, -1};

    srand(time(0));
    for(int i = 0; i < 4; i++){
        int randomNum = rand() % 16; 
        do{
            randomNum = rand() % 16; 
        }
        while((randomNum == mines[0]) || (randomNum == mines[1]) || (randomNum == mines[2]) || (randomNum == mines[3]));
        mines[i] = randomNum;
        cpu.setRegister({0, 1, 0, 0, 0, 0, 0, 0}, mines[i]);
        
    }

    //std::cout << std::to_string(mines[0]) + "|" + std::to_string(mines[1]) + "|" + std::to_string(mines[2]) + "|" + std::to_string(mines[3]) + "\n";

    for(int i = 0; i < gridSize; i++){ 
        int mineCount = 0;
        if(cpu.getRegister(i)[1] != 1){
            for(int j = 0; j < 8; j++){
                if((((i / 4) + deltaR[j] >= 0) && (((i / 4)) + deltaR[j] <= 3)) && (((i % 4) + deltaC[j] >= 0) && ((i % 4) + deltaC[j] <= 3))){
                    if(cpu.getRegister(((i / 4) + deltaR[j]) * 4 + ((i % 4) + deltaC[j]))[1] == 1){
                        mineCount++;
                    }
                }
            }
            cpu.setRegister(decimalToBinary<8>(mineCount), i);
        }
    }
}

int decodeInput(){
    std::string input;
    std::cout << "Enter coordinate; row is A to D and column is 0 to 3. \n";
    std::cin >> input;
    while(std::cin.fail() || input.size() < 2 || !(input[0] == 'A' || input[0] == 'B' || input[0] == 'C' || input[0] == 'D') || !(input[1] == '0' || input[1] == '1' || input[1] == '2' || input[1] == '3')){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter coordinate; row is A to D and column is 0 to 3. \n";
        std::cin >> input;
    }
    return (input[0] - 'A') * 4 + (input[1] - '0');
}
