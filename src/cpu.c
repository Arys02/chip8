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


