#include "chip8_keyboard.h"
static bool chip8_ensure_key_is_in_bounds(int key)
{
    return (key>=0 && key<CHIP8_NUMBER_OF_KEYS);
}
void chip8_keyboard_set_keyboard_map(struct chip8_keyboard* keyboard, const char* map)
{
    keyboard->keyboard_map=map;
}
char chip8_keyboard_map(struct chip8_keyboard* keyboard, char key)
{
    for (int i=0;i<CHIP8_NUMBER_OF_KEYS;i++)
    {
        if(keyboard->keyboard_map[i]==key)
            return i;
    }
    return -1;
}
void chip8_keyboard_hold_key_down(struct chip8_keyboard* keyboard, int key)
{
    keyboard->keyboard[key]=true;
}
void chip8_keyboard_key_up(struct chip8_keyboard* keyboard, int key)
{
    keyboard->keyboard[key]=false;
}

bool chip8_keyboard_is_pressed(struct chip8_keyboard* keyboard, int key)
{
    return keyboard->keyboard[key];
}