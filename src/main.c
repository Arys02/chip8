#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "cpu.h"

int main()
{
  CPU *cpu = malloc(sizeof(CPU));
  cpu_init(cpu);
  cpu_print(cpu);

  SDL_Init(SDL_INIT_VIDEO);
  return 0;
}


