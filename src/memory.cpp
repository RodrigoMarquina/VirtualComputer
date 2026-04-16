#include "memory.h"
#include "logic_gates.h"
#include <stdexcept>
#include <array>

bool SRLatch(bool s, bool r, bool q){ //Active-high
    if(AND(s, r)){
        throw std::runtime_error("Latch case invalid");
    }
    if(AND(NOT(s), NOT(r))){
        return q;
    }
    return s;
}

std::array<bool, 8> Register(std::array<bool, 8> d, bool we, bool reset, std::array<bool, 8> q){
    std::array<bool, 8> output;

    output[7] = SRLatch(AND(AND(d[7], we), NOT(reset)), OR(AND(NOT(d[7]), we), reset), q[7]);
    output[6] = SRLatch(AND(AND(d[6], we), NOT(reset)), OR(AND(NOT(d[6]), we), reset), q[6]);
    output[5] = SRLatch(AND(AND(d[5], we), NOT(reset)), OR(AND(NOT(d[5]), we), reset), q[5]);
    output[4] = SRLatch(AND(AND(d[4], we), NOT(reset)), OR(AND(NOT(d[4]), we), reset), q[4]);
    output[3] = SRLatch(AND(AND(d[3], we), NOT(reset)), OR(AND(NOT(d[3]), we), reset), q[3]);
    output[2] = SRLatch(AND(AND(d[2], we), NOT(reset)), OR(AND(NOT(d[2]), we), reset), q[2]);
    output[1] = SRLatch(AND(AND(d[1], we), NOT(reset)), OR(AND(NOT(d[1]), we), reset), q[1]);
    output[0] = SRLatch(AND(AND(d[0], we), NOT(reset)), OR(AND(NOT(d[0]), we), reset), q[0]);

    return output;
}
