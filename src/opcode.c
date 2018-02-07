#include "opcode.h"

static Uint8 get_opcode_id(JUMP *jp, Uint16 opcode);
static void print_opcode(Uint16 opcode);

void init_jump(JUMP *jp)
{
  jp->mask[0]= 0x0000; jp->id[0]=0x0FFF;          /* 0NNN */
  jp->mask[1]= 0xFFFF; jp->id[1]=0x00E0;          /* 00E0 */
  jp->mask[2]= 0xFFFF; jp->id[2]=0x00EE;          /* 00EE */
  jp->mask[3]= 0xF000; jp->id[3]=0x1000;          /* 1NNN */
  jp->mask[4]= 0xF000; jp->id[4]=0x2000;          /* 2NNN */
  jp->mask[5]= 0xF000; jp->id[5]=0x3000;          /* 3XNN */
  jp->mask[6]= 0xF000; jp->id[6]=0x4000;          /* 4XNN */
  jp->mask[7]= 0xF00F; jp->id[7]=0x5000;          /* 5XY0 */
  jp->mask[8]= 0xF000; jp->id[8]=0x6000;          /* 6XNN */
  jp->mask[9]= 0xF000; jp->id[9]=0x7000;          /* 7XNN */
  jp->mask[10]= 0xF00F; jp->id[10]=0x8000;          /* 8XY0 */
  jp->mask[11]= 0xF00F; jp->id[11]=0x8001;          /* 8XY1 */
  jp->mask[12]= 0xF00F; jp->id[12]=0x8002;          /* 8XY2 */
  jp->mask[13]= 0xF00F; jp->id[13]=0x8003;          /* BXY3 */
  jp->mask[14]= 0xF00F; jp->id[14]=0x8004;          /* 8XY4 */
  jp->mask[15]= 0xF00F; jp->id[15]=0x8005;          /* 8XY5 */
  jp->mask[16]= 0xF00F; jp->id[16]=0x8006;          /* 8XY6 */
  jp->mask[17]= 0xF00F; jp->id[17]=0x8007;          /* 8XY7 */
  jp->mask[18]= 0xF00F; jp->id[18]=0x800E;          /* 8XYE */
  jp->mask[19]= 0xF00F; jp->id[19]=0x9000;          /* 9XY0 */
  jp->mask[20]= 0xF000; jp->id[20]=0xA000;          /* ANNN */
  jp->mask[21]= 0xF000; jp->id[21]=0xB000;          /* BNNN */
  jp->mask[22]= 0xF000; jp->id[22]=0xC000;          /* CXNN */
  jp->mask[23]= 0xF000; jp->id[23]=0xD000;          /* DXYN */
  jp->mask[24]= 0xF0FF; jp->id[24]=0xE09E;          /* EX9E */
  jp->mask[25]= 0xF0FF; jp->id[25]=0xE0A1;          /* EXA1 */
  jp->mask[26]= 0xF0FF; jp->id[26]=0xF007;          /* FX07 */
  jp->mask[27]= 0xF0FF; jp->id[27]=0xF00A;          /* FX0A */
  jp->mask[28]= 0xF0FF; jp->id[28]=0xF015;          /* FX15 */
  jp->mask[29]= 0xF0FF; jp->id[29]=0xF018;          /* FX18 */
  jp->mask[30]= 0xF0FF; jp->id[30]=0xF01E;          /* FX1E */
  jp->mask[31]= 0xF0FF; jp->id[31]=0xF029;          /* FX29 */
  jp->mask[32]= 0xF0FF; jp->id[32]=0xF033;          /* FX33 */
  jp->mask[33]= 0xF0FF; jp->id[33]=0xF055;          /* FX55 */
  jp->mask[34]= 0xF0FF; jp->id[34]=0xF065;          /* FX65 */
}

Uint16 get_opcode(CPU *cpu)
{
  return (cpu->memory[cpu->mem_pc] << 8) + cpu->memory[cpu->mem_pc + 1];
}

Uint8 interpret_opcode(SCREEN *screen, CPU *cpu, JUMP *jp, Uint16 opcode)
{
  Uint8 op_id;
  Uint8 b3, b2, b1;
  Uint8 continu = 1;


  op_id = get_opcode_id(jp, opcode);

  b3 = (opcode & (0x0F00)) >> 8;
  b2 = (opcode & (0x00F0)) >> 4;
  b1 = opcode & (0x000F);

  printf("%x\n", opcode);


  switch(op_id)
  {
    case 0:
      {
        break;
      }
    case 1:
      {
        op_00EO(screen);
        break;
      }
    case 2:
      {
        op_00EE(cpu);
        break;
      }
    case 3:
      {
        op_1NNN(cpu, b3, b2, b1);
        break;
      }
    case 4:
      {
        op_2NNN(cpu, b3, b2, b1);
        break;
      }
    case 5:
      {
        op_3XNN(cpu, b3, b2, b1);
        break;
      }
    case 6:
      {
        op_4XNN(cpu, b3, b2, b1);
        break;
      }
    case 7:
      {
        op_5XY0(cpu, b3, b2);
        break;
      }
    case 8:
      {
        op_6XNN(cpu, b3, b2, b1);
        break;
      }
    case 9:
      {
        op_7XNN(cpu, b3, b2, b1);
        break;
      }
    case 10:
      {
        op_8XY0(cpu, b3, b2);
        break;
      }
    case 11:
      {
        op_8XY1(cpu, b3, b2);
        break;
      }
    case 12:
      {
        op_8XY2(cpu, b3, b2);
        break;
      }
    case 13:
      {
        op_8XY3(cpu, b3, b2);
        break;
      }
    case 14:
      {
        op_8XY4(cpu, b3, b2);
        break;
      }
    case 15:
      {
        op_8XY5(cpu, b3, b2);
        break;
      }
    case 16:
      {
        op_8XY6(cpu, b3);
        break;
      }
    case 17:
      {
        op_8XY7(cpu, b3, b2);
        break;
      }
    case 18:
      {
        op_8XYE(cpu, b3);
        break;
      }
    case 19:
      {
        op_9XY0(cpu, b3, b2);
        break;
      }
    case 20:
      {

        op_ANNN(cpu, b3, b2, b1);
        break;
      }
    case 21:
      {
        op_BNNN(cpu, b3, b2, b1);
        break;
      }
    case 22:
      {
        op_CXNN(cpu, b3, b2, b1);
        break;
      }
    case 23:
      {
        op_DXYN(screen, cpu, b3, b2, b1);
        break;
      }
    case 24:
      {
        op_EX9E(cpu, b3);
        break;
      }
    case 25:
      {

        op_EXA1(cpu, b3);
        break;
      }
    case 26:
      {
        op_FX07(cpu, b3);
        break;
      }
    case 27:
      {
        printf("---waitkeeeeeeeeeyyyyyyy ---- \n");
        continu = op_FX0A(cpu, b3);
        break;
      }
    case 28:
      {
        op_FX15(cpu, b3);
        break;
      }
    case 29:
      {
        op_FX18(cpu, b3);
        break;
      }
    case 30:
      {
        op_FX1E(cpu, b3);
        break;
      }
    case 31:
      {
        op_FX29(cpu, b3);
        break;
      }
    case 32:
      {
        op_FX33(cpu, b3);
        break;
      }
    case 33:
      {
        op_FX55(cpu, b3);
        break;
      }
    case 34:
      {
        op_FX65(cpu, b3);
        break;
      }
    default:
      {
        exit(1);
        break;
      }

  }
  cpu->mem_pc += 2;
  return continu;
}

void draw_screen(SCREEN *screen, CPU *cpu, Uint8 b1, Uint8 b2, Uint8 b3)
{
  Uint8 x = 0;
  Uint8 y = 0;

  Uint8 codage = 0;

  for (int i = 0; i < b1; ++i)
  {
    codage = cpu->memory[cpu->reg_I + i];
    y = (cpu->reg[b2] + i) % 32;

    for (int j = 0, d = 7; j < 8; ++j, d--)
    {
      x = (cpu->reg[b3] + j) % 64;
      if (codage & (0x1 << d))
      {
        if (screen->px_array[x][y].color == WHITE)
        {
          screen->px_array[x][y].color = BLACK;
          cpu->reg[0xF] = 1;
        }
        else
          screen->px_array[x][y].color = WHITE;
      }
    }
  }

}

static Uint8 get_opcode_id(JUMP *jp, Uint16 opcode)
{
  Uint16 calcul_id;

  for (int i = 0; i < NBOPCODE; ++i)
  {

    calcul_id = jp->mask[i] & opcode;
    if (calcul_id == jp->id[i])
      return i;
  }
  printf("get_opcode_id failed\n");
  return 0;
}

static void print_opcode(Uint16 opcode)
{
  printf("%04x \n", opcode);
}
