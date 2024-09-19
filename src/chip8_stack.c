#include "chip8_stack.h"
#include "chip8.h"
#include <stdio.h>

static int chip8_stack_in_bounds(struct chip8* chip8)
{
    if(chip8->registers.SP>CHIP8_STACK_SIZE || chip8->registers.SP<0)
    {
        printf("STACK OVERFLOW");
        return 0;
    }
    return 1;
}

void chip8_stack_push(struct chip8* chip8, unsigned short val)
{
    if(chip8_stack_in_bounds(chip8))
    {
    chip8->stack.stack[chip8->registers.SP]=val;
    chip8->registers.SP++;
    }
}

unsigned short chip8_stack_pop(struct chip8* chip8)
{
    chip8->registers.SP--;
    if(chip8_stack_in_bounds(chip8))
    {
            return chip8->stack.stack[chip8->registers.SP];
    }
    return NULL;
}