#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

void screen_init(SCREEN *screen)
{

  for (int x = 0; x < w; ++x)
    for (int y = 0; y < h; ++y)
    {
      screen->px_array[x][y].pos.x = x * DIMPIXEL;
      screen->px_array[x][y].pos.y = y * DIMPIXEL;
      screen->px_array[x][y].color = BLACK;
    }

  screen->physical_screen = NULL;
  screen->square[0] = NULL;
  screen->square[1] = NULL;
  screen->physical_screen = SDL_CreateWindow("chip8",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      WIDTH, HEIGHT, SDL_WINDOW_OPENGL);

  screen->square[0] = SDL_CreateRGBSurface(0,DIMPIXEL,DIMPIXEL,32,0,0,0,0);
  SDL_FillRect(screen->square[0], NULL, SDL_MapRGB(screen->square[0]->format, 0x00, 0x00, 0x00));

  screen->square[1] = SDL_CreateRGBSurface(0,DIMPIXEL,DIMPIXEL,32,0,0,0,0);
  SDL_FillRect(screen->square[1], NULL, SDL_MapRGB(screen->square[1]->format, 0xFF, 0xFF, 0xFF));

  // add a test to check if physical_screen is ok

}

void print_screen(SCREEN *screen)
{
  printf("w : %d ", w);
  printf("h : %d", h);
  for (int i = 0; i < w; ++i)
  {
    printf("\n");
    for (int j = 0; j < h; ++j)
      printf("%d ", screen->px_array[i][j].color);
  }

}

