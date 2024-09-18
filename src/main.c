#include <stdio.h>
#include "SDL2/SDL.h"
#include <windows.h>
#include "chip8.h"
#include "config.h"
#include "chip8_keyboard.h"

const char keyboard_map[CHIP8_NUMBER_OF_KEYS] =
    {
        SDLK_1, SDLK_2, SDLK_3, SDLK_4,
        SDLK_q, SDLK_w, SDLK_e, SDLK_r,
        SDLK_a, SDLK_s, SDLK_d, SDLK_f,
        SDLK_y, SDLK_x, SDLK_c, SDLK_v};
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("ERROR: A file must be provided to load into Chip8");
        return -1;
    }
    const char* filename = argv[1];
    printf("Filename: %s", filename);

    FILE* file = fopen(filename, "rb");
    if(!file)
    {
        printf("ERROR:unable to open given file:%s\n", filename);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long file_size=ftell(file);
    fseek(file, 0, SEEK_SET);

    char buffer[file_size];
    int res = fread(buffer, file_size, 1, file);
    if(res != 1)
    {
        printf("ERROR:unable to read from given file:%s\n", filename);
        return -1;
    }


    struct chip8 chip8;
    chip8_init(&chip8);
    chip8_load(&chip8, buffer, file_size);
    chip8_keyboard_set_keyboard_map(&chip8.keyboard,keyboard_map);
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * EMULATOR_WINDOW_SCALER,
        CHIP8_HEIGHT * EMULATOR_WINDOW_SCALER,
        SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_TEXTUREACCESS_TARGET);
    while (1)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                goto out;
                break;
            case SDL_KEYDOWN:
            {
                char key = event.key.keysym.sym;
                char vkey = chip8_keyboard_map(&chip8.keyboard, key);
                if (vkey != -1)
                {
                    chip8_keyboard_hold_key_down(&chip8.keyboard, vkey);
                }
            }
            break;
            case SDL_KEYUP:
            {
                char key = event.key.keysym.sym;
                char vkey = chip8_keyboard_map(&chip8.keyboard, key);
                if (vkey != -1)
                {
                    chip8_keyboard_key_up(&chip8.keyboard, vkey);
                }
            }
            break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        for (int x = 0; x < CHIP8_WIDTH; x++)
        {
            for (int y = 0; y < CHIP8_HEIGHT; y++)
            {
                if (chip8_screen_is_set(&chip8.screen, x, y))
                {
                    SDL_Rect r;
                    r.x = x * EMULATOR_WINDOW_SCALER;
                    r.y = y * EMULATOR_WINDOW_SCALER;
                    r.w = EMULATOR_WINDOW_SCALER;
                    r.h = EMULATOR_WINDOW_SCALER;
                    SDL_RenderFillRect(renderer, &r);
                }
            }
        }

        SDL_RenderPresent(renderer);
        if (chip8.registers.delay_timer > 0)
        {
            Sleep(3); // 60Hz
            chip8.registers.delay_timer--;
        }

        if (chip8.registers.sound_timer > 0)
        {
            Beep(15000,3*chip8.registers.sound_timer);
            chip8.registers.sound_timer=0;
        }
        unsigned short opcode = chip8_memory_get_short(&chip8.memory, chip8.registers.PC);
        chip8.registers.PC+=2;
        chip8_exec(&chip8, opcode);
        //Sleep(1);
    }
out:
    SDL_DestroyWindow(window);

    return 0;
}