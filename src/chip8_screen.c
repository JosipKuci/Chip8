#include "chip8_screen.h"
#include <assert.h>
#include <stdio.h>

static void chip8_screen_insure_bounds(int x ,int y)
{
    assert(x >= 0 && x < CHIP8_WIDTH);
    assert(y >= 0 && y < CHIP8_HEIGHT);
}

void chip8_screen_set(struct chip8_screen* screen, int x, int y)
{
    chip8_screen_insure_bounds(x,y);
    screen->pixels[y][x]=true;
}
bool chip8_screen_is_set(struct chip8_screen* screen, int x, int y)
{
    chip8_screen_insure_bounds(x,y);
    return screen->pixels[y][x];
}

bool chip8_screen_draw_sprite(struct chip8_screen* screen, int x, int y, const char* sprite, int num_of_bytes)
{
    bool sprite_changed = false;
    for(int ly=0;ly<num_of_bytes;ly++)
    {
        char c=sprite[ly];
        for(int lx=0;lx<8;lx++)
        {
            if((c&(0b10000000>>lx))==0)
            {
                continue;
            }
            if(screen->pixels[(ly+y)% CHIP8_HEIGHT][(lx+x)%CHIP8_WIDTH])
            {
                sprite_changed=true;
            }
            screen->pixels[(ly+y)% CHIP8_HEIGHT][(lx+x)%CHIP8_WIDTH] ^= true;
        }
    }
    return sprite_changed;
}

void chip8_screen_clear(struct chip8_screen* screen)
{
    for(int y=0;y<CHIP8_HEIGHT;y++)
    {
        for (int x = 0; x < CHIP8_WIDTH; x++)
        {
            chip8_screen_insure_bounds(x,y);
            screen->pixels[y][x]=false;
        }
        
    }
}