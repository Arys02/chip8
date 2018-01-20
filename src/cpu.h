#ifndef CPU_H
# define CPU_H

#define MEMSIZE 4096
#define ADDRSTART 512

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

void cpu_init(CPU *cpu);
void cpu_decompter(CPU *cpu);
void cpu_print(CPU *cpu);
void mem_print(CPU *cpu);

int load_rom(CPU *cpu, char *path);



#endif /* !CPU_H */
