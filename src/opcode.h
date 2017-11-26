#ifndef OPCODE_H
# define OPCODE_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#define NBOPCODE 35


#include "cpu.h"

typedef struct
{
  Uint16 mask[NBOPCODE];
  Uint16 id[NBOPCODE];

} JUMP;

void init_jump(JUMP *jp);
int get_jump_id();

Uint16 get_opcode(CPU *cpu);
void decode_opcode(CPU *cpu);
void interpret_opcode(CPU *cpu, JUMP *jp, Uint16 opcode);


#endif /* !OPCODE_H */
