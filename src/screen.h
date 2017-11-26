#ifndef PIXEL_H
# define PIXEL_H
#include <SDL/SDL.h>

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
  SDL_Surface *physical_screen;
  SDL_Surface *square[2];
} SCREEN;



void screen_init(SCREEN *screen);
void draw_pixel(SCREEN *screen, PIXEL pixel);
void screen_clear(SCREEN *screen);
void screen_update(SCREEN *screen);
void screen_print(SCREEN *screen);

static void init_px_array(SCREEN *screen);
static void init_px_array_TEST_(SCREEN *screen);

#endif /* !PIXEL_H */
