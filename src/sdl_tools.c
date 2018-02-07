#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "sdl_tools.h"


void sdl_init()
{
  atexit(sdl_quit);
  SDL_Init(SDL_INIT_VIDEO);
}

void sdl_quit(SCREEN *screen)
{
  if (screen->square[0])
    SDL_FreeSurface(screen->square[0]);

  if (screen->square[1])
  SDL_FreeSurface(screen->square[1]);
  SDL_Quit();
}

void sdl_break()
{
  Uint8 continu = 1;

  do
  {
    SDL_WaitEvent(&event);

    switch(event.type)
    {
      case SDL_QUIT:
        continu = 0;
        break;
      case SDL_KEYDOWN:
        continu = 0;
        break;
      default : break;
    }
  }
  while(continu);
}

Uint8 listen(SCREEN *screen, CPU *cpu) 
{
  Uint8 continuer=1;

  while(SDL_PollEvent(&event)) 
  { 
    switch(event.type) 
    { 
      case SDL_QUIT: {continuer = 0;break;} 
      case SDL_KEYDOWN:{ 
                         switch(event.key.keysym.sym) 
                         { 
                           case SDLK_q:{printf("------------q \n"); cpu->key[0x0]=1;break;} 
                           case SDLK_PLUS:{ cpu->key[0x1]=1;break;} 
                           case SDLK_MINUS:{ cpu->key[0x2]=1;break;} 
                           case SDLK_SLASH:{ cpu->key[0x3]=1;break;} 
                           case SDLK_v:{ cpu->key[0x4]=1;break;} 
                           case SDLK_d:{ cpu->key[0x5]=1;break;} 
                           case SDLK_l:{ cpu->key[0x6]=1;break;} 
                           case SDLK_t:{ cpu->key[0x7]=1;break;} 
                           case SDLK_s:{ cpu->key[0x8]=1;break;} 
                           case SDLK_r:{ cpu->key[0x9]=1;break;} 
                           case SDLK_g:{ cpu->key[0xA]=1;break;} 
                           case SDLK_h:{cpu->key[0xB]=1;break;} 
                           case SDLK_ASTERISK:{cpu->key[0xC]=1;break;} 
                           case SDLK_j:{cpu->key[0xD]=1;break;} 
                           case SDLK_n:{cpu->key[0xE]=1;break;} 
                           case SDLK_f:{cpu->key[0xF]=1;break;} 
                           case SDLK_p:{printf("p ");sdl_break();break;} 
                           case SDLK_o:{printf("r ");reset(screen, cpu);break;} 
                           case SDLK_ESCAPE:{printf("escape \n ");continuer = 0; break;} 
                           default:{ printf("failed pushed");break;} 
                         }                                      
                         break;}         
      case SDL_KEYUP:{ 
                       switch(event.key.keysym.sym) 
                       { 
                         case SDLK_q:{ cpu->key[0x0]=0;break;} 
                         case SDLK_PLUS:{ cpu->key[0x1]=0;break;} 
                         case SDLK_MINUS:{ cpu->key[0x2]=0;break;} 
                         case SDLK_SLASH:{ cpu->key[0x3]=0;break;} 
                         case SDLK_v:{ cpu->key[0x4]=0;break;} 
                         case SDLK_d:{ cpu->key[0x5]=0;break;} 
                         case SDLK_l:{ cpu->key[0x6]=0;break;} 
                         case SDLK_t:{ cpu->key[0x7]=0;break;} 
                         case SDLK_s:{ cpu->key[0x8]=0;break;} 
                         case SDLK_r:{ cpu->key[0x9]=0;break;} 
                         case SDLK_g:{ cpu->key[0xA]=0;break;} 
                         case SDLK_h:{cpu->key[0xB]=0;break;} 
                         case SDLK_ASTERISK:{cpu->key[0xC]=0;break;} 
                         case SDLK_j:{cpu->key[0xD]=0;break;} 
                         case SDLK_n:{cpu->key[0xE]=0;break;} 
                         case SDLK_f:{cpu->key[0xF]=0;break;} 
                         default:{ printf("keyup\n");break;} 
                       } 
                       break;} 

      default:{ break;} 
    } 
  } 

  return continuer; 
} 


void reset(SCREEN *screen, CPU *cpu)
{
  cpu->mem_pc = ADDRSTART;

  for (Uint8 i = 0; i < 16; ++i)
  {
    cpu->reg[i] = 0;
    cpu->stack[i] = 0;
    cpu->key[i] = 0;
  }

  cpu->reg_I = 0;
  cpu->reg_index = 0;
  cpu->jump = 0;

  cpu->timer_game = 0;
  cpu->timer_sound = 0;
  screen_clear(screen);
}


Uint8 waitkey(CPU *cpu, Uint8 b3)
{
  Uint8 attend = 1;
  Uint8 continuer = 1;

  while(attend)
  {
    SDL_WaitEvent(&event);

    switch(event.type) 
    {
      case SDL_QUIT:{ continuer=0;attend=0; break;} 

      case SDL_KEYDOWN:{ 

                         switch(event.key.keysym.sym) 
                         {
                           case SDLK_q:{ printf("--------q \n");cpu->reg[b3]=0x0; cpu->key[0x0]=1; attend=0;break;} 
                           case SDLK_PLUS:{ cpu->reg[b3]=0x1; cpu->key[0x1]=1; attend=0;break;} 
                           case SDLK_MINUS:{ cpu->reg[b3]=0x2; cpu->key[0x2]=1; attend=0;break;} 
                           case SDLK_SLASH:{ cpu->reg[b3]=0x3; cpu->key[0x3]=1; attend=0;break;} 
                           case SDLK_u:{ cpu->reg[b3]=0x4; cpu->key[0x4]=1; attend=0;break;} 
                           case SDLK_d:{ cpu->reg[b3]=0x5; cpu->key[0x5]=1; attend=0;break;} 
                           case SDLK_l:{ cpu->reg[b3]=0x6; cpu->key[0x6]=1; attend=0;break;} 
                           case SDLK_t:{ cpu->reg[b3]=0x7; cpu->key[0x7]=1; attend=0;break;} 
                           case SDLK_s:{ cpu->reg[b3]=0x8; cpu->key[0x8]=1; attend=0;break;} 
                           case SDLK_r:{ cpu->reg[b3]=0x9; cpu->key[0x9]=1; attend=0;break;} 
                           case SDLK_g:{    printf("right \n");   cpu->reg[b3]=0xA;       cpu->key[0xA]=1;  attend=0;break;} 
                           case SDLK_h:{    cpu->reg[b3]=0xB;     cpu->key[0xB]=1;  attend=0;break;} 
                           case SDLK_ASTERISK:{  cpu->reg[b3]=0xC;     cpu->key[0xC]=1;  attend=0;break;} 
                           case SDLK_j:{     cpu->reg[b3]=0xD;     cpu->key[0xD]=1;  attend=0;break;} 
                           case SDLK_n:{      cpu->reg[b3]=0xE;     cpu->key[0xE]=1;  attend=0;break;} 
                           case SDLK_f:{     cpu->reg[b3]=0xF;     cpu->key[0xF]=1;  attend=0;break;} 
                           default:{ printf("-- failed \n");break;} 
                         } break;} 

      default:{ break;} 
    } 
  } 


  return continuer; 
}


