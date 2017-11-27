#ifndef INSTRUCTION_H
# define INSTRUCTION_H

#include "opcode.h"
#include "screen.h"
#include "cpu.h"

void op_00EO(SCREEN *screen); // 1
void op_00EE(CPU *cpu); // 2

void op_1NNN(CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3); // 3
void op_2NNN(CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3); // 4

void op_3XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1); // 5
void op_4XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1); // 6

void op_5XY0(CPU *cpu, Uint8 b3, Uint8 b2); // 7

void op_6XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1); // 8
void op_7XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1);// 9


void op_8XY0(CPU *cpu, Uint8 b3, Uint8 b2); // 10
void op_8XY1(CPU *cpu, Uint8 b3, Uint8 b2); // 11
void op_8XY2(CPU *cpu, Uint8 b3, Uint8 b2); // 12
void op_8XY3(CPU *cpu, Uint8 b3, Uint8 b2); // 13
void op_8XY4(CPU *cpu, Uint8 b3, Uint8 b2); // 14
void op_8XY5(CPU *cpu, Uint8 b3, Uint8 b2); // 15
void op_8XY6(CPU *cpu, Uint8 b3, Uint8 b2); // 16
void op_8XY7(CPU *cpu, Uint8 b3, Uint8 b2); // 17
void op_8XYE(CPU *cpu, Uint8 b3, Uint8 b2); // 18

void op_9XY0(SCREEN *screen, CPU *cpu); // 19
void op_ANNN(SCREEN *screen, CPU *cpu); // 20
void op_BNNN(SCREEN *screen, CPU *cpu); // 21
void op_CXNN(SCREEN *screen, CPU *cpu); // 22


void op_DXYN(SCREEN *screen, CPU *cpu); // 23
void op_EX9E(SCREEN *screen, CPU *cpu); // 24
void op_EXA1(SCREEN *screen, CPU *cpu); // 25

void op_FX07(SCREEN *screen, CPU *cpu); // 26
void op_FX0A(SCREEN *screen, CPU *cpu); // 27
void op_FX15(SCREEN *screen, CPU *cpu); // 28
void op_FX18(SCREEN *screen, CPU *cpu); // 29
void op_FX1E(SCREEN *screen, CPU *cpu); // 30
void op_FX29(SCREEN *screen, CPU *cpu); // 31
void op_FX33(SCREEN *screen, CPU *cpu); // 32
void op_FX55(SCREEN *screen, CPU *cpu); // 33
void op_FX65(SCREEN *screen, CPU *cpu); // 34

#endif /* !INSTRUCTION_H */
