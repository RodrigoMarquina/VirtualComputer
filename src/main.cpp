#include <iostream>
#include <limits>
#include "logic_gates.h" //angle brackets <> tell the compiler to look in the system include directories (where standard library headers like iostream live). Quotes "" tell it to look relative to your own project.

int main() {
    bool a, b;
    //Check a
    std::cout << "Enter value of a (0 or 1): \n";
    std::cin >> a;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter value of a (0 or 1): \n";
        std::cin >> a;
    }
    //Check b   
    std::cout << "Enter value of b (0 or 1): \n";
    std::cin >> b;
    while(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter value of b (0 or 1): \n";
        std::cin >> b;
    }
    //NAND output
    std::cout << "The answer of the NAND is: " << NAND(a,b) << '\n';
    return 0;
}
