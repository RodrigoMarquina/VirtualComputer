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

std::pair<bool, bool> HalfAdder(bool a, bool b){
    return std::make_pair(XOR(a, b), AND(a, b));
}

std::pair<bool, bool> FullAdder(bool a, bool b, bool c){
    std::pair<bool, bool> HA1 = HalfAdder(a, b);
    std::pair<bool, bool> HA2 = HalfAdder(HA1.first, c);
    return std::make_pair(HA2.first, OR(HA1.second, HA2.second));
}

bool MUX(bool sel, bool a, bool b){
    return OR(AND(a, NOT(sel)), AND(b, sel));
}

ALUStructure MUXFields(bool sel, ALUStructure field1, ALUStructure field2){
    ALUStructure outputField;
    //MUX c
    outputField.c[0] = MUX(sel, field1.c[0], field2.c[0]);
    outputField.c[1] = MUX(sel, field1.c[1], field2.c[1]);
    outputField.c[2] = MUX(sel, field1.c[2], field2.c[2]);
    outputField.c[3] = MUX(sel, field1.c[3], field2.c[3]);
    outputField.c[4] = MUX(sel, field1.c[4], field2.c[4]);
    outputField.c[5] = MUX(sel, field1.c[5], field2.c[5]);
    outputField.c[6] = MUX(sel, field1.c[6], field2.c[6]);
    outputField.c[7] = MUX(sel, field1.c[7], field2.c[7]);

    //MUX signFlag
    outputField.signFlag = MUX(sel, field1.signFlag, field2.signFlag);

    //MUX zeroFlag
    outputField.zeroFlag = MUX(sel, field1.zeroFlag, field2.zeroFlag);

    //MUX overflowFlag
    outputField.overflowFlag = MUX(sel, field1.overflowFlag, field2.overflowFlag);

    return outputField;
}

ALUStructure ALU(std::array<bool, 8> a, std::array<bool, 8> b, std::array<bool, 3> upcode){
    //ADD | Upcode 000
    std::pair<bool, bool> SUMOP1 = FullAdder(a[7], b[7], 0);
    std::pair<bool, bool> SUMOP2 = FullAdder(a[6], b[6], SUMOP1.second);
    std::pair<bool, bool> SUMOP3 = FullAdder(a[5], b[5], SUMOP2.second);
    std::pair<bool, bool> SUMOP4 = FullAdder(a[4], b[4], SUMOP3.second);
    std::pair<bool, bool> SUMOP5 = FullAdder(a[3], b[3], SUMOP4.second);
    std::pair<bool, bool> SUMOP6 = FullAdder(a[2], b[2], SUMOP5.second);
    std::pair<bool, bool> SUMOP7 = FullAdder(a[1], b[1], SUMOP6.second);
    std::pair<bool, bool> SUMOP8 = FullAdder(a[0], b[0], SUMOP7.second);

    ALUStructure SUMOutput;
    SUMOutput.c = {SUMOP8.first, SUMOP7.first, SUMOP6.first, SUMOP5.first, SUMOP4.first, SUMOP3.first, SUMOP2.first, SUMOP1.first};
    SUMOutput.signFlag = SUMOutput.c[0];
    SUMOutput.zeroFlag = NOT(OR(OR(OR(SUMOutput.c[0], SUMOutput.c[1]), OR(SUMOutput.c[2], SUMOutput.c[3])), OR(OR(SUMOutput.c[4], SUMOutput.c[5]), OR(SUMOutput.c[6], SUMOutput.c[7]))));
    SUMOutput.overflowFlag = AND(NOT(XOR(a[0], b[0])), XOR(b[0], SUMOutput.c[0]));

    //SUB | Upcode 001
    std::pair<bool, bool> SUBOP1 = FullAdder(a[7], NOT(b[7]), 1);
    std::pair<bool, bool> SUBOP2 = FullAdder(a[6], NOT(b[6]), SUBOP1.second);
    std::pair<bool, bool> SUBOP3 = FullAdder(a[5], NOT(b[5]), SUBOP2.second);
    std::pair<bool, bool> SUBOP4 = FullAdder(a[4], NOT(b[4]), SUBOP3.second);
    std::pair<bool, bool> SUBOP5 = FullAdder(a[3], NOT(b[3]), SUBOP4.second);
    std::pair<bool, bool> SUBOP6 = FullAdder(a[2], NOT(b[2]), SUBOP5.second);
    std::pair<bool, bool> SUBOP7 = FullAdder(a[1], NOT(b[1]), SUBOP6.second);
    std::pair<bool, bool> SUBOP8 = FullAdder(a[0], NOT(b[0]), SUBOP7.second);

    ALUStructure SUBOutput;
    SUBOutput.c = {SUBOP8.first, SUBOP7.first, SUBOP6.first, SUBOP5.first, SUBOP4.first, SUBOP3.first, SUBOP2.first, SUBOP1.first};
    SUBOutput.signFlag = SUBOutput.c[0];
    SUBOutput.zeroFlag = NOT(OR(OR(OR(SUBOutput.c[0], SUBOutput.c[1]), OR(SUBOutput.c[2], SUBOutput.c[3])), OR(OR(SUBOutput.c[4], SUBOutput.c[5]), OR(SUBOutput.c[6], SUBOutput.c[7]))));
    SUBOutput.overflowFlag = AND(NOT(XOR(a[0], NOT(b[0]))), XOR(NOT(b[0]), SUBOutput.c[0]));

    //NOT | Upcode 010
    ALUStructure NOTOutput;
    NOTOutput.c = {NOT(a[0]), NOT(a[1]), NOT(a[2]), NOT(a[3]), NOT(a[4]), NOT(a[5]), NOT(a[6]), NOT(a[7])};
    NOTOutput.signFlag = NOTOutput.c[0];
    NOTOutput.zeroFlag = NOT(OR(OR(OR(NOTOutput.c[0], NOTOutput.c[1]), OR(NOTOutput.c[2], NOTOutput.c[3])), OR(OR(NOTOutput.c[4], NOTOutput.c[5]), OR(NOTOutput.c[6], NOTOutput.c[7]))));
    NOTOutput.overflowFlag = 0;

    //AND | Upcode 011
    ALUStructure ANDOutput;
    ANDOutput.c = {AND(a[0], b[0]), AND(a[1], b[1]), AND(a[2], b[2]), AND(a[3], b[3]), AND(a[4], b[4]), AND(a[5], b[5]), AND(a[6], b[6]), AND(a[7], b[7])};
    ANDOutput.signFlag = ANDOutput.c[0];
    ANDOutput.zeroFlag = NOT(OR(OR(OR(ANDOutput.c[0], ANDOutput.c[1]), OR(ANDOutput.c[2], ANDOutput.c[3])), OR(OR(ANDOutput.c[4], ANDOutput.c[5]), OR(ANDOutput.c[6], ANDOutput.c[7]))));
    ANDOutput.overflowFlag = 0;

    //OR | Upcode 100
    ALUStructure OROutput;
    OROutput.c = {OR(a[0], b[0]), OR(a[1], b[1]), OR(a[2], b[2]), OR(a[3], b[3]), OR(a[4], b[4]), OR(a[5], b[5]), OR(a[6], b[6]), OR(a[7], b[7])};
    OROutput.signFlag = OROutput.c[0];
    OROutput.zeroFlag = NOT(OR(OR(OR(OROutput.c[0], OROutput.c[1]), OR(OROutput.c[2], OROutput.c[3])), OR(OR(OROutput.c[4], OROutput.c[5]), OR(OROutput.c[6], OROutput.c[7]))));
    OROutput.overflowFlag = 0;

    //NAND | Upcode 101
    ALUStructure NANDOutput;
    NANDOutput.c = {NAND(a[0], b[0]), NAND(a[1], b[1]), NAND(a[2], b[2]), NAND(a[3], b[3]), NAND(a[4], b[4]), NAND(a[5], b[5]), NAND(a[6], b[6]), NAND(a[7], b[7])};
    NANDOutput.signFlag = NANDOutput.c[0];
    NANDOutput.zeroFlag = NOT(OR(OR(OR(NANDOutput.c[0], NANDOutput.c[1]), OR(NANDOutput.c[2], NANDOutput.c[3])), OR(OR(NANDOutput.c[4], NANDOutput.c[5]), OR(NANDOutput.c[6], NANDOutput.c[7]))));
    NANDOutput.overflowFlag = 0;

    //XOR | Upcode 110
    ALUStructure XOROutput;
    XOROutput.c = {XOR(a[0], b[0]), XOR(a[1], b[1]), XOR(a[2], b[2]), XOR(a[3], b[3]), XOR(a[4], b[4]), XOR(a[5], b[5]), XOR(a[6], b[6]), XOR(a[7], b[7])};
    XOROutput.signFlag = XOROutput.c[0];
    XOROutput.zeroFlag = NOT(OR(OR(OR(XOROutput.c[0], XOROutput.c[1]), OR(XOROutput.c[2], XOROutput.c[3])), OR(OR(XOROutput.c[4], XOROutput.c[5]), OR(XOROutput.c[6], XOROutput.c[7]))));
    XOROutput.overflowFlag = 0;

    //Multiplexer
    return MUXFields(upcode[0], MUXFields(upcode[1], MUXFields(upcode[2], SUMOutput, SUBOutput), MUXFields(upcode[2], NOTOutput, ANDOutput)), MUXFields(upcode[1], MUXFields(upcode[2], OROutput, NANDOutput), MUXFields(upcode[2], XOROutput, XOROutput)));
}

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