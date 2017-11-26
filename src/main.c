#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "cpu.h"
#include "screen.h"
#include "sdl_tools.h"

int main()
{
  //setup CPU
  CPU *cpu = malloc(sizeof(CPU));
  cpu_init(cpu);

  //setup sdl
  sdl_init();

  //setup screen
  SCREEN *screen = malloc(sizeof(SCREEN));
  screen_init(screen);

  screen_update(screen);

  sdl_break();
  sdl_quit(screen);


  free(cpu);
  free(screen);
  return 0;
}


