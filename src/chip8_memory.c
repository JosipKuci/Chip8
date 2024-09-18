#include "chip8_memory.h"
#include <stdio.h>


static int array_index_within_bounds(int index)
{
    return (index>=0 && index<CHIP8_MEMORY_SIZE);
}
void chip8_memory_set(struct chip8_memory* memory,int index, unsigned char value)
{
    if(array_index_within_bounds(index))
    {
        memory->memory[index]=value;
    }
    else
    {
        printf("ERROR:Attempted to set memory outside of bounds\n");
    }
    
}
unsigned char chip8_memory_get(struct chip8_memory* memory, int index)
{
    if(array_index_within_bounds(index))
    {
        return memory->memory[index];
    }
    else
    {
        printf("ERROR:Attempted to access memory outside of bounds\n");
    }
    
}

unsigned short chip8_memory_get_short(struct chip8_memory* memory, int index)
{
    unsigned char first_byte = chip8_memory_get(memory, index);
    unsigned char second_byte = chip8_memory_get(memory, index+1);
    return first_byte << 8 | second_byte;

}