#include <stdio.h>
#include <stdlib.h>

#include "game_engine.h"

int load_rom(CPU *cpu, char *path)
{
  FILE *rom = NULL;
  rom = fopen(path, "rb");

  if (rom)
  {
    fread(&cpu->memory[ADDRSTART], sizeof(Uint8) * (MEMSIZE - ADDRSTART), 1, rom);
    fclose(rom);
    return 0;
  }

  fprintf(stderr, "error while trying to open the rom file");
  return 1;
}
