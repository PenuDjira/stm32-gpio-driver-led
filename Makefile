# Makefile for STM32L4xx Bare-Metal Project
# 1. Configurate Toolchain
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m4 -mthumb -std=gnu11 -O0 -g Iinc
LDFLAGS = -T scripts/stm32_ls.ld -nostdlib

# 2. The main target
all: final.bin

# 3. Compile src/main.c to main.o
main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

# 4. Compile src/startup.c to startup.o
startup.o: src/startup.c
	$(CC) $(CFLAGS) -c src/startup.c -o startup.o
	
# 5. Compile src/gpio.c to gpio.o
gpio.o: src/gpio.c
	$(CC) $(CFLAGS) -c src/gpio.c -o gpio.o

# 6. Link all object to .elf file
final.elf: main.o startup.o gpio.o
	$(CC) $(LDFLAGS) main.o startup.o gpio.o -o final.elf

# 7. Convert .elf to .bin (Ready to Flash)
final.bin: final.elf
	$(OBJCOPY) -O binary final.elf final.bin

# 8. Clean up build files
clean:
	rm -f *.o *.elf *.bin
