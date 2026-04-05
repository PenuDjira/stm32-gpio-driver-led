# STM32 GPIO Driver with LED blink
This a project that i learn to build everything from scratch. I used no IDE Like STM32CubeIDE/CubeMX to generate project.
I only use Makefile and i create this project at VS Code.
In this project we build Blinki LED with simple GPIO Driver that i build by myself.

### How to run this project?
1. Clone the project or the simple way you can download zip.
2. Extract the zip file.
3. Open your terminal the go to the project directory.
4. If you use different board, make sure to change the address and the size of the MEMORY at stm32_ls.ld file.
```c 
MEMORY
{
    /* Nama(Atribut) : ORIGIN = Alamat Start, LENGTH = Ukuran */
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 512K
    SRAM(rwx) : ORIGIN = 0x20000000, LENGTH = 128K
}
```
5. Then changes the SRAM size at startup.c file
```c
 #define SRAM_SIZE (128U * 1024U) /* 128 KB */ 
 ```
6. Change the address of register in gpio.h file.
6. Use: make (to build your project) in your terminal.


Subscribe my YouTube channel[https://youtube.com/@PenuDjira]