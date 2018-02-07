#ifndef SDL_TOOLS_H
# define SDL_TOOLS_H

#include <SDL/SDL.h>
#include "screen.h"

void sdl_init();
void sdl_quit();
void sdl_break();
Uint8 listen(SCREEN *screen, CPU *cpu);
Uint8 waitkey(CPU *cpu, Uint8 b3);
void reset(SCREEN *screen, CPU *cpu);

SDL_Event event;

#endif /* !SDL_TOOLS_H */
