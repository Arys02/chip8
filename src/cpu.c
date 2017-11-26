#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "cpu.h"

void cpu_init(CPU *cpu)
{
  for (Uint16 i = 0; i < MEMSIZE; ++i)
    cpu->memory[i] = 0;

  cpu->mem_pc = ADDRSTART;

  for (Uint8 i = 0; i < 16; ++i)
  {
    cpu->reg[i] = 0;
    cpu->stack[i] = 0;
  }

  cpu->reg_I = 0;
  cpu->reg_index = 0;
  cpu->jump = 0;

  cpu->timer_game = 0;
  cpu->timer_sound = 0;

  printf("cpu_init\n");
}

void cpu_decompter(CPU *cpu)
{
  if (cpu->timer_game)
    cpu->timer_game--;
  if (cpu->timer_sound)
    cpu->timer_sound--;
}

Uint16 get_opcode(CPU *cpu)
{
  return (cpu->memory[cpu->mem_pc] << 8) + cpu->memory[cpu->mem_pc + 1];
}

void init_jump(JUMP *jp)
{
  jp->mask[0]= 0x0000; jp->id[0]=0x0FFF;          /* 0NNN */
  jp->mask[1]= 0xFFFF; jp->id[1]=0x00E0;          /* 00E0 */
  jp->mask[2]= 0xFFFF; jp->id[2]=0x00EE;          /* 00EE */
  jp->mask[3]= 0xF000; jp->id[3]=0x1000;          /* 1NNN */
  jp->mask[4]= 0xF000; jp->id[4]=0x2000;          /* 2NNN */
  jp->mask[5]= 0xF000; jp->id[5]=0x3000;          /* 3XNN */
  jp->mask[6]= 0xF000; jp->id[6]=0x4000;          /* 4XNN */
  jp->mask[7]= 0xF00F; jp->id[7]=0x5000;          /* 5XY0 */
  jp->mask[8]= 0xF000; jp->id[8]=0x6000;          /* 6XNN */
  jp->mask[9]= 0xF000; jp->id[9]=0x7000;          /* 7XNN */
  jp->mask[10]= 0xF00F; jp->id[10]=0x8000;          /* 8XY0 */
  jp->mask[11]= 0xF00F; jp->id[11]=0x8001;          /* 8XY1 */
  jp->mask[12]= 0xF00F; jp->id[12]=0x8002;          /* 8XY2 */
  jp->mask[13]= 0xF00F; jp->id[13]=0x8003;          /* BXY3 */
  jp->mask[14]= 0xF00F; jp->id[14]=0x8004;          /* 8XY4 */
  jp->mask[15]= 0xF00F; jp->id[15]=0x8005;          /* 8XY5 */
  jp->mask[16]= 0xF00F; jp->id[16]=0x8006;          /* 8XY6 */
  jp->mask[17]= 0xF00F; jp->id[17]=0x8007;          /* 8XY7 */
  jp->mask[18]= 0xF00F; jp->id[18]=0x800E;          /* 8XYE */
  jp->mask[19]= 0xF00F; jp->id[19]=0x9000;          /* 9XY0 */
  jp->mask[20]= 0xF000; jp->id[20]=0xA000;          /* ANNN */
  jp->mask[21]= 0xF000; jp->id[21]=0xB000;          /* BNNN */
  jp->mask[22]= 0xF000; jp->id[22]=0xC000;          /* CXNN */
  jp->mask[23]= 0xF000; jp->id[23]=0xD000;          /* DXYN */
  jp->mask[24]= 0xF0FF; jp->id[24]=0xE09E;          /* EX9E */
  jp->mask[25]= 0xF0FF; jp->id[25]=0xE0A1;          /* EXA1 */
  jp->mask[26]= 0xF0FF; jp->id[26]=0xF007;          /* FX07 */
  jp->mask[27]= 0xF0FF; jp->id[27]=0xF00A;          /* FX0A */
  jp->mask[28]= 0xF0FF; jp->id[28]=0xF015;          /* FX15 */
  jp->mask[29]= 0xF0FF; jp->id[29]=0xF018;          /* FX18 */
  jp->mask[30]= 0xF0FF; jp->id[30]=0xF01E;          /* FX1E */
  jp->mask[31]= 0xF0FF; jp->id[31]=0xF029;          /* FX29 */
  jp->mask[32]= 0xF0FF; jp->id[32]=0xF033;          /* FX33 */
  jp->mask[33]= 0xF0FF; jp->id[33]=0xF055;          /* FX55 */
  jp->mask[34]= 0xF0FF; jp->id[34]=0xF065;          /* FX65 */
}

void cpu_print(CPU *cpu)
{
  printf("mem_index = %d\n", cpu->mem_pc);

  printf("reg_addr = %d\n", cpu->reg_I);
  printf("reg_index = %d\n", cpu->reg_index);

  printf("printf REGISTER : \n");
  for (Uint8 i = 0; i < 16; ++i)
    printf("i : %d -> %d\n", i, cpu->reg[i]);

  printf("printf STACK: \n");
  for (Uint8 i = 0; i < 16; ++i)
    printf("i : %d -> %d\n", i, cpu->stack[i]);

  printf("jump = %d\n", cpu->jump);

  printf("timer_game = %d\n", cpu->timer_game);
  printf("timer_sound = %d\n", cpu->timer_sound);
}
