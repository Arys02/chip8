#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "cpu.h"
#include "screen.h"

int main()
{
  //setup CPU
  CPU *cpu = malloc(sizeof(CPU));
  cpu_init(cpu);
  //cpu_print(cpu);

  //SDL_Init(SDL_INIT_VIDEO);


  SCREEN *screen = malloc(sizeof(SCREEN));

  screen_init(screen);
  print_screen(screen);


  free(cpu);
  return 0;
}


