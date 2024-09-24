An emulator of the popular Chip-8 interpreter from the mid 1970s
It is made using the C programming language and the SDL2 graphics library
It supports all games made for it.
It was compiled and tested using the 32-bit mingw32 compiler on a windows 10 machine 
###How to compile and run
To compile the code, go to the Chip8 directory and run the command:
`mingw32-make`
Then to start the emulator, change into the `bin` directory and start the main.exe file by also specifying the ROM you want to play, for example:
`main.exe .\INVADERS`
This emulator works with every Chip-8 game, and there is a Space Invaders ROM included with the repository for testing
