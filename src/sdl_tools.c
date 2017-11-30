#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "sdl_tools.h"

void sdl_init()
{
  SDL_Init(SDL_INIT_VIDEO);
}

void sdl_quit(SCREEN *screen)
{
  SDL_FreeSurface(screen->square[0]);
  SDL_FreeSurface(screen->square[1]);
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

Uint8 listen()
{
  Uint8 continu = 1;

  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT :
        {
          continu = 0;
          break;
        }
      case SDL_KEYDOWN : 
        {
          continu = 0;
          break;
        }
      default:
        break;
    }
  }
  return continu;
}
