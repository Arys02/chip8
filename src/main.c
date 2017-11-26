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
  //cpu_print(cpu);



  SCREEN *screen = malloc(sizeof(SCREEN));

  screen_init(screen);

  screen_clear(screen);
  //screen_print(screen);
  //
  sdl_break();


  free(cpu);
  free(screen);
  return 0;
}


