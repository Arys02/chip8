#include <stdio.h>
#include <stdlib.h>

#include "instruction.h"


void op_00EO(SCREEN *screen) // 1
{
  screen_clear(screen);
}


void op_00EE(CPU *cpu) // 2
{
  if (cpu->jump)
  {
    cpu->jump--;
    cpu->mem_pc = cpu->stack[cpu->jump];
  }
}

void op_1NNN(CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3) // 3
{
  cpu->mem_pc = (b3 << 8) + (b2 << 4) + b1;
  cpu->mem_pc -= 2;
}

void op_2NNN(CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3) // 4
{
  cpu->stack[cpu->jump] = cpu->mem_pc;

  if (cpu->jump < 15)
    cpu->jump++;

  cpu->mem_pc = (b3 << 8) + (b2 << 4) + b1;
  cpu->mem_pc -= 2;
}

void op_3XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1)// 5
{
  if (cpu->reg[b3] == ((b2 << 4) + b1) )
    cpu->mem_pc += 2;
}

void op_4XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1)// 6
{
  if (cpu->reg[b3] != ((b2 << 4) + b1) )
    cpu->mem_pc += 2;
}

void op_5XY0(CPU *cpu, Uint8 b3, Uint8 b2)// 7
{
  if (cpu->reg[b3] == cpu->reg[b2])
    cpu->mem_pc += 2;
}

void op_6XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1)// 8
{
  cpu->reg[b3] = (b2 << 4) + b1;
}

void op_7XNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1)// 9
{
  cpu->reg[b3] += (b2 << 4) + b1;
}

void op_8XY0(CPU *cpu, Uint8 b3, Uint8 b2) // 10
{
  cpu->reg[b3] = cpu->reg[b2];
}

void op_8XY1(CPU *cpu, Uint8 b3, Uint8 b2) // 11
{
  cpu->reg[b3] = cpu->reg[b3] | cpu->reg[b2];
}

void op_8XY2(CPU *cpu, Uint8 b3, Uint8 b2) // 12
{
  cpu->reg[b3] = cpu->reg[b3] & cpu->reg[b2];
}

void op_8XY3(CPU *cpu, Uint8 b3, Uint8 b2) // 13
{
  cpu->reg[b3] = cpu->reg[b3] ^ cpu->reg[b2];
}

void op_8XY4(CPU *cpu, Uint8 b3, Uint8 b2) // 14
{
  cpu->reg[0xF] = (cpu->reg[b3] + cpu->reg[b2] > 0xFF) ? 1 : 0;
  cpu->reg[b3] += cpu->reg[b2];
}

void op_8XY5(CPU *cpu, Uint8 b3, Uint8 b2) // 15
{
  cpu->reg[0xF] = (cpu->reg[b3] < cpu->reg[b2]) ? 0 : 1;
  cpu->reg[b3] -= cpu->reg[b2];
}

void op_8XY6(CPU *cpu, Uint8 b3, Uint8 b2) // 16
{
  //TODO
}
