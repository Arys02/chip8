#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

static void init_px_array(SCREEN *screen);

void screen_init(SCREEN *screen)
{
  init_px_array(screen);

  screen->physical_screen = NULL;
  screen->square[0] = NULL;
  screen->square[1] = NULL;

  screen->physical_screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("Chip8", NULL);

  screen->square[0] = SDL_CreateRGBSurface(0,DIMPIXEL,DIMPIXEL,32,0,0,0,0);
  SDL_FillRect(screen->square[0], NULL, SDL_MapRGB(screen->square[0]->format, 0x00, 0x00, 0x00));

  screen->square[1] = SDL_CreateRGBSurface(0,DIMPIXEL,DIMPIXEL,32,0,0,0,0);
  SDL_FillRect(screen->square[1], NULL, SDL_MapRGB(screen->square[1]->format, 0xFF, 0xFF, 0xFF));

}

void draw_pixel(SCREEN *screen, PIXEL pixel)
{
  SDL_BlitSurface(screen->square[pixel.color], NULL, screen->physical_screen, &pixel.pos);
}

void screen_clear(SCREEN *screen)
{
  for (int x = 0; x < w; ++x)
    for (int y = 0; y < h; ++y)
      screen->px_array[x][y].color = BLACK;

  SDL_FillRect(screen->physical_screen, NULL, BLACK);
}

void screen_update(SCREEN *screen)
{
  for (int x = 0; x < w; ++x)
    for (int y = 0; y < h; ++y)
      draw_pixel(screen, screen->px_array[x][y]);

  SDL_Flip(screen->physical_screen);
}

static void init_px_array(SCREEN *screen)
{
  for (int x = 0; x < w; ++x)
    for (int y = 0; y < h; ++y)
    {
      screen->px_array[x][y].pos.x = x * DIMPIXEL;
      screen->px_array[x][y].pos.y = y * DIMPIXEL;
      screen->px_array[x][y].color = BLACK;
    }
}
