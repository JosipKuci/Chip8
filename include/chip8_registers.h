#include "config.h"
#ifndef CHIP8_REGISTERS_H
#define CHIP8_REGISTERS_H
struct chip8_registers
{
    unsigned char V[CHIP8_NUMBER_OF_DATA_REGISTERS];
    unsigned short I;
    unsigned char delay_timer;
    unsigned char sound_timer;

    //Pseudo-registers
    unsigned short PC;
    unsigned char SP;
};
#endif
