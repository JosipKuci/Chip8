#include "config.h"
#ifndef CHIP8_MEMORY_H
#define CHIP8_MEMORY_H
struct chip8_memory
{
    unsigned char memory[CHIP8_MEMORY_SIZE]; //TODO: Los naziv, kasnije promjeniti
};

void chip8_memory_set(struct chip8_memory* memory,int index, unsigned char value);
unsigned char chip8_memory_get(struct chip8_memory* memory, int index);
unsigned short chip8_memory_get_short(struct chip8_memory* memory, int index);

#endif