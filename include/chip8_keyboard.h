#ifndef CHIP8_KEYBOARD_H
#define CHIP8_KEYBOARD_H
#include "config.h"
#include <stdbool.h>
struct chip8_keyboard
{
    bool keyboard[CHIP8_NUMBER_OF_KEYS];
    const char* keyboard_map;
};
void chip8_keyboard_set_keyboard_map(struct chip8_keyboard* keyboard, const char* map);
char chip8_keyboard_map(struct chip8_keyboard* keyboard, char key);
void chip8_keyboard_hold_key_down(struct chip8_keyboard* keyboard, int key);
void chip8_keyboard_key_up(struct chip8_keyboard* keyboard, int key);

bool chip8_keyboard_is_pressed(struct chip8_keyboard* keyboard, int key);
#endif