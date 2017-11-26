#ifndef CPU_H
# define CPU_H
#define MEMSIZE 4092
#define ADDRSTART 512
#define NBOPCODE 35

typedef struct
{
  Uint8 memory[MEMSIZE];
  Uint16 mem_pc;

  Uint8 reg[16];
  Uint16 reg_I;
  Uint8 reg_index;

  Uint16 stack[16];
  Uint8 jump;


  Uint8 timer_game;
  Uint8 timer_sound;

} CPU;

typedef struct
{
  Uint16 mask[NBOPCODE];
  Uint16 id[NBOPCODE];

} JUMP;

void cpu_init(CPU *cpu);
void cpu_decompter(CPU *cpu);
void cpu_print(CPU *cpu);


void init_jump(JUMP *jp);
Uint16 get_opcode(CPU *cpu);
void decode_opcode(CPU *cpu);


#endif /* !CPU_H */
