#ifndef GAME_ENGINE_H
# define GAME_ENGINE_H

#include <SDL/SDL.h>
#include "cpu.h"

int load_rom(CPU *cpu, char *path);

#endif /* !GAME_ENGINE_H */
