#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "cpu.h"
#include "screen.h"
#include "sdl_tools.h"
#include "opcode.h"

#define CPUSPEED 4
#define FRAMERATE 16

int main(int argc, char** argv)
{
  //setup CPU
  CPU *cpu = malloc(sizeof(CPU));
  cpu_init(cpu);

  //setup Jump
  JUMP *jp = malloc(sizeof(JUMP));
  init_jump(jp);

  //setup sdl
  //sdl_init();

  //setup screen
  SCREEN *screen = malloc(sizeof(SCREEN));
  screen_init(screen);

  Uint8 continu = 1;

  int rom = load_rom(cpu, argv[1]);

  mem_print(cpu);

  if (!rom)
  {
    do
    {
      continu = listen(screen, cpu);
      printf("%d \n", continu);
      for (int i = 0; i < CPUSPEED && continu; ++i)
        continu = interpret_opcode(screen, cpu, jp, get_opcode(cpu));

      screen_update(screen);
      SDL_Delay(FRAMERATE);
    } while(continu == 1);

  }

  sdl_break();
  sdl_quit(screen);


  free(cpu);
  free(screen);
  return 0;
}



