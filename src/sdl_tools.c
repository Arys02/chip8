#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "sdl_tools.h"

void sdl_init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
}

void sdl_quit()
{
  SDL_Quit();
}

void sdl_break()
{
  Uint8 continu = 1;

  do
  {
    SDL_WaitEvent(&event);

    switch(event.type)
    {
      case SDL_QUIT:
        continu = 0;
        break;
      case SDL_KEYDOWN:
        continu = 0;
        break;
      default : break;
    }
  }
  while(continu);
}
