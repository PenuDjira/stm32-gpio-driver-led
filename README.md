# Project Overview
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
    /* Name(Atribut) : ORIGIN = Start Address, LENGTH = Size */
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

### Whats New?
1. I was upgraded the DRIVER with 2 new functions:
    ```c 
        GPIO_SetPin(); // To set the state of the Pin.
        GPIO_ClearPin(); // To clear the state of the Pin
    ```
2. How to use these functions?
    If you want to use these function without any other abstractions like i do in my main code, you can write the code like this:
```c
    while(1)
    {
        GPIO_SetPin(PINx); // Set the Pin. Use the pin you define in your project
        delay(delay_value);
        GPIO_ClearPin(PINx); // Clear the Pin
        delay(delay_value);
    }
```

    This simple code will help you build your own led Blink with pure bare metal and use the GPIO Driver.

3. WARNING!!! 
    In some board, the BUILT IN led is ACTIVE LOW, so it means, when you clear the BIT of the PIN, the PIN will get 0 BIT and the LED will TURN ON. ACTIVE LOW LED --> CLEAR BIT --> THE STATE OF THE BIT BECOME 0 --> PIN GET LOW VOLTAGE --> LED TURN ON.


Subscribe my YouTube channel [Penu Djira](https://www.youtube.com/@PenuDjira)
