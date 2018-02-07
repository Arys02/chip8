#include <stdio.h>
#include <stdlib.h>

#include "instruction.h"


void op_00EO(SCREEN *screen) // 1
{
  screen_clear(screen);
}

void op_00EE(CPU *cpu) // 2
{
  if (cpu->jump > 0)
  {
    cpu->jump--;
    cpu->mem_pc = cpu->stack[cpu->jump];
  }
}

void op_1NNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 3
{
  cpu->mem_pc = (b3 << 8) + (b2 << 4) + b1;
  cpu->mem_pc -= 2;
}

void op_2NNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 4
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
  cpu->reg[0xF] = ((cpu->reg[b3] + cpu->reg[b2]) > 255) ? 1 : 0;
  cpu->reg[b3] += cpu->reg[b2];
}

void op_8XY5(CPU *cpu, Uint8 b3, Uint8 b2) // 15
{
  cpu->reg[0xF] = (cpu->reg[b3] < cpu->reg[b2]) ? 0 : 1;
  cpu->reg[b3] -= cpu->reg[b2];
}

void op_8XY6(CPU *cpu, Uint8 b3) // 16
{
  cpu->reg[0xF] = cpu->reg[b3] & 0x01;
  cpu->reg[b3] = cpu->reg[b3] >> 1;
}

void op_8XY7(CPU *cpu, Uint8 b3, Uint8 b2) // 17
{
  cpu->reg[0xF] = (cpu->reg[b3] > cpu->reg[b2]) ? 0 : 1;
  cpu->reg[b3] = cpu->reg[b2] - cpu->reg[b3];
}

void op_8XYE(CPU *cpu, Uint8 b3) // 18
{
  cpu->reg[0xF] = cpu->reg[b3] >> 7;
  cpu->reg[b3] = cpu->reg[b3] << 1;
}

void op_9XY0(CPU *cpu, Uint8 b3, Uint8 b2) // 19
{
  if (cpu->reg[b3] != cpu->reg[b2])
    cpu->mem_pc += 2;
}


void op_ANNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 20
{
  cpu->reg_I = (b3 << 8) + (b2 << 4) + b1;
}

void op_BNNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 21
{
  cpu->mem_pc = (b3 << 8) + (b2 << 4) + b1 + cpu->reg[0];
  cpu->mem_pc -= 2;
}

void op_CXNN(CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 22
{
  cpu->reg[b3] = rand() % ((b2 << 4) + b1 + 1);
}

void op_DXYN(SCREEN *screen, CPU *cpu, Uint8 b3, Uint8 b2, Uint8 b1) // 23
{
  draw_screen(screen, cpu, b1, b2, b3);
}

void op_EX9E(CPU *cpu, Uint8 b3)// 24
{
  printf("%x\n",cpu->key[cpu->reg[b3]]);
  printf("%x\n",cpu->reg[b3]);
  if (cpu->key[cpu->reg[b3]] == 1)
    cpu += 2;
}

void op_EXA1(CPU *cpu, Uint8 b3)// 25
{
  if (cpu->key[cpu->reg[b3]] == 0)
    cpu += 2;
}

void op_FX07(CPU *cpu, Uint8 b3)// 26
{
  cpu->reg[b3] = cpu->timer_game;
}

Uint8 op_FX0A(CPU *cpu, Uint8 b3)// 27
{
  return waitkey(cpu, b3);
}

void op_FX15(CPU *cpu, Uint8 b3)// 28
{
  cpu->timer_game = cpu->reg[b3];
}

void op_FX18(CPU *cpu, Uint8 b3)// 29
{
  cpu->timer_sound = cpu->reg[b3];
}

void op_FX1E(CPU *cpu, Uint8 b3)// 30
{
  cpu->reg[0xF] = (cpu->reg[b3] + cpu->reg_I) > 0xFFF ? 1 : 0;
  cpu->reg_I += cpu->reg[b3];
}

void op_FX29(CPU *cpu, Uint8 b3)// 31
{
  cpu->reg_I = 5 * cpu->reg[b3];
}

void op_FX33(CPU *cpu, Uint8 b3)// 32
{
  cpu->memory[cpu->reg_I] = (cpu->reg[b3] - cpu->reg[b3] % 100) / 100; //stocke les centaines 
  cpu->memory[cpu->reg_I + 1] = (((cpu->reg[b3] - cpu->reg[b3] % 10) / 10) % 10);//les dizaines 
  cpu->memory[cpu->reg_I + 2] = cpu->reg[b3] - cpu->memory[cpu->reg_I] * 100 - cpu->memory[cpu->reg_I + 1] * 10;//les unités
}

void op_FX55(CPU *cpu, Uint8 b3)// 33
{
  for (int i = 0; i <= b3; i++)
    cpu->memory[cpu->reg_I + i] = cpu->reg[i];
}

void op_FX65(CPU *cpu, Uint8 b3)// 34
{
  for (int i = 0; i <= b3; i++)
    cpu->reg[i] = cpu->memory[cpu->reg_I + i];
}
