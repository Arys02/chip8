#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "cpu.h"
#include "screen.h"
#include "sdl_tools.h"

#define CPUSPEED 4
#define FRAMERATE 16

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


  do
  {

    //op 1
    //op 2
    //op 3
    //op 4
    screen_update(screen);
    SDL_Delay(FRAMERATE);
  } while(1);


  sdl_break();
  sdl_quit(screen);


  free(cpu);
  free(screen);
  return 0;
}


