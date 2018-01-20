#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "cpu.h"

static void init_digit(CPU *cpu);


void cpu_init(CPU *cpu)
{
  init_digit(cpu);
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

  mem_print(cpu);
}


static void init_digit(CPU *cpu)
{
    cpu->memory[0]  = 0xF0; cpu->memory[1]  = 0x90; cpu->memory[2]  = 0x90; cpu->memory[3]  = 0x90; cpu->memory[4]  = 0xF0;  // O
    cpu->memory[5]  = 0x20; cpu->memory[6]  = 0x60; cpu->memory[7]  = 0x20; cpu->memory[8]  = 0x20; cpu->memory[9]  = 0x70;  // 1
    cpu->memory[10] = 0xF0; cpu->memory[11] = 0x10; cpu->memory[12] = 0xF0; cpu->memory[13] = 0x80; cpu->memory[14] = 0xF0;  // 2
    cpu->memory[15] = 0xF0; cpu->memory[16] = 0x10; cpu->memory[17] = 0xF0; cpu->memory[18] = 0x10; cpu->memory[19] = 0xF0;  // 3
    cpu->memory[20] = 0x90; cpu->memory[21] = 0x90; cpu->memory[22] = 0xF0; cpu->memory[23] = 0x10; cpu->memory[24] = 0x10;  // 4
    cpu->memory[25] = 0xF0; cpu->memory[26] = 0x80; cpu->memory[27] = 0xF0; cpu->memory[28] = 0x10; cpu->memory[29] = 0xF0;  // 5
    cpu->memory[30] = 0xF0; cpu->memory[31] = 0x80; cpu->memory[32] = 0xF0; cpu->memory[33] = 0x90; cpu->memory[34] = 0xF0;  // 6
    cpu->memory[35] = 0xF0; cpu->memory[36] = 0x10; cpu->memory[37] = 0x20; cpu->memory[38] = 0x40; cpu->memory[39] = 0x40;  // 7
    cpu->memory[40] = 0xF0; cpu->memory[41] = 0x90; cpu->memory[42] = 0xF0; cpu->memory[43] = 0x90; cpu->memory[44] = 0xF0;  // 8
    cpu->memory[45] = 0xF0; cpu->memory[46] = 0x90; cpu->memory[47] = 0xF0; cpu->memory[48] = 0x10; cpu->memory[49] = 0xF0;  // 9
    cpu->memory[50] = 0xF0; cpu->memory[51] = 0x90; cpu->memory[52] = 0xF0; cpu->memory[53] = 0x90; cpu->memory[54] = 0x90;  // A
    cpu->memory[55] = 0xE0; cpu->memory[56] = 0x90; cpu->memory[57] = 0xE0; cpu->memory[58] = 0x90; cpu->memory[59] = 0xE0;  // B
    cpu->memory[60] = 0xF0; cpu->memory[61] = 0x80; cpu->memory[62] = 0x80; cpu->memory[63] = 0x80; cpu->memory[64] = 0xF0;  // C
    cpu->memory[65] = 0xE0; cpu->memory[66] = 0x90; cpu->memory[67] = 0x90; cpu->memory[68] = 0x90; cpu->memory[69] = 0xE0;  // D
    cpu->memory[70] = 0xF0; cpu->memory[71] = 0x80; cpu->memory[72] = 0xF0; cpu->memory[73] = 0x80; cpu->memory[74] = 0xF0;  // E
    cpu->memory[75] = 0xF0; cpu->memory[76] = 0x80; cpu->memory[77] = 0xF0; cpu->memory[78] = 0x80; cpu->memory[79] = 0x80;  // F

}


void mem_print(CPU *cpu)
{
  Uint8 *tmp = cpu->memory;
  for (int i = 0; i < MEMSIZE; i++)
  {
    if (i % 5 == 0 || i < 5)
      printf("\n%04d ", i);

    printf("%04x ",*tmp);
    tmp++;
  }
}

int load_rom(CPU *cpu, char *path)
{
  FILE *rom = NULL;
  rom = fopen(path, "rb");

  if (rom)
  {
    fread(cpu->memory + ADDRSTART, sizeof(Uint8) * (MEMSIZE - ADDRSTART), 1, rom);
    fclose(rom);
    printf("Rom correctly loaded\n");
    return 0;
  }

  fprintf(stderr, "error while trying to open the rom file");
  return 1;
}
