#pragma once

#include <array>
#include "logic_gates.h"
#include "alu.h"

class CPU{
    public:
        std::array<std::array<bool, 8>, 256> instructionMemory = {};
        void iterateCPU();
        std::array<bool, 8> getAccumulator();
        void setRegister(std::array<bool, 8> a, int index);
    private:
        std::array<std::array<bool, 8>, 16> dataMemory = {};
        std::array<bool, 8> accumulator = {};
        std::array<bool, 8> instructionCounter = {};
};