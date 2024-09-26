An emulator of the popular Chip-8 interpreter from the mid 1970s
It is made using the C programming language and the SDL2 graphics library
It supports all games made for it.
It was compiled and tested using the 32-bit mingw32 compiler on a windows 10 machine 
### How to compile and run

To compile the code, go to the Chip8 directory and run the command:

`mingw32-make`

Then to start the emulator, change into the  directory and start the main.exe file by also specifying the ROM you want to play, for example:

`main.exe .\INVADERS`

This emulator works with every Chip-8 game, and there is a Space Invaders ROM included with the repository for testing

### Controls and mapping
On the original Chip-8 the keys were mapped as follows:

<table border="1" cellpadding="3" cellspacing="0" align="center">
			<tbody><tr><td><tt>1</tt></td><td><tt>2</tt></td><td><tt>3</tt></td><td><tt>C</tt></td></tr>
			<tr><td><tt>4</tt></td><td><tt>5</tt></td><td><tt>6</tt></td><td><tt>D</tt></td></tr>
			<tr><td><tt>7</tt></td><td><tt>8</tt></td><td><tt>9</tt></td><td><tt>E</tt></td></tr>
			<tr><td><tt>A</tt></td><td><tt>0</tt></td><td><tt>B</tt></td><td><tt>F</tt></td></tr>
		</tbody></table>
  
In the emulator, the keys are mapped as:

<table border="1" cellpadding="3" cellspacing="0" align="center">
			<tbody><tr><td><tt>1</tt></td><td><tt>2</tt></td><td><tt>3</tt></td><td><tt>4</tt></td></tr>
			<tr><td><tt>Q</tt></td><td><tt>W</tt></td><td><tt>E</tt></td><td><tt>R</tt></td></tr>
			<tr><td><tt>A</tt></td><td><tt>S</tt></td><td><tt>D</tt></td><td><tt>F</tt></td></tr>
			<tr><td><tt>Y</tt></td><td><tt>X</tt></td><td><tt>C</tt></td><td><tt>V</tt></td></tr>
		</tbody></table>
  
The keys can be remapped by changing the values of the `keyboard_map` array located at the start of the `src\main.c` file

### Emulation speed control
As the Chip-8 does not define any clock cycles, the emulation speed is defined by the user/hardware.
Use the key `O` to increase the delay and the key `P` to decrease it.
By default, the delay is set to 0ms. The current delay is shown in the command prompt.

### Screenshots

<div align="center">
    <img src="https://github.com/JosipKuci/Chip8-emulator/blob/main/example1.png?raw=true" width="400px"</img> 
</div>
<br><br>
<div align="center">
    <img src="https://github.com/JosipKuci/Chip8-emulator/blob/main/example2.png?raw=true" width="400px"</img> 
</div>

