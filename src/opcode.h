#ifndef OPCODE_H
# define OPCODE_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#define NBOPCODE 35


#include "cpu.h"
#include "screen.h"
#include "instruction.h"

typedef struct
{
  Uint16 mask[NBOPCODE];
  Uint16 id[NBOPCODE];

} JUMP;

void init_jump(JUMP *jp);
int get_jump_id();

Uint16 get_opcode(CPU *cpu);
void decode_opcode(CPU *cpu);
Uint8 interpret_opcode(SCREEN *screen, CPU *cpu, JUMP *jp, Uint16 opcode);


void draw_screen(SCREEN *screen, CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3);

#endif /* !OPCODE_H */
