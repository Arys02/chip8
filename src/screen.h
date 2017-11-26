#ifndef PIXEL_H
# define PIXEL_H
#include <SDL2/SDL.h>

#define BLACK 0
#define WHITE 1

#define w 64
#define h 32

#define DIMPIXEL 8

#define WIDTH DIMPIXEL*w
#define HEIGHT DIMPIXEL*h

typedef struct
{
  SDL_Rect pos;
  Uint8 color;
} PIXEL;


typedef struct
{
  PIXEL px_array[w][h];
  SDL_Window *physical_screen;
  SDL_Surface *square[2];
} SCREEN;



void screen_init(SCREEN *screen);

void print_screen(SCREEN *screen);

#endif /* !PIXEL_H */
