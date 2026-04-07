#ifndef GPIO_H // Include guard so that the header file is not included multiple times
#define GPIO_H // Define the macro GPIO_H to indicate that this header has been included

#include <stdint.h> // Include standard integer types for fixed width integers like uint8_t and uint32_t

// Register base address
#define RCC_BASE 0x40023800U // Base address for Reset and Clock Control (RCC) registers. Please refer to yoown manual reference for the correct address.
#define GPIOC_BASE 0x40020800U // Base address for GPIOC registers. Please refer to your manual reference for the correct address.

// Register Definitions
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30U))
#define GPIOC_MODER (*(volatile uint32_t *)(GPIOC_BASE + 0x00U))
#define GPIOC_ODR	(*(volatile uint32_t *)(GPIOC_BASE + 0x14U))

// Function declarations
void GPIO_ClockEnable(void); // Function to enable the clock for GPIOC peripheral
void GPIO_SetOutput(uint8_t pin); // Function to set a specific pin as output. The pin number is passed as an argument.
void GPIO_Toggle(uint8_t pin); // Function to toggle the state of a specific pin. The pin number is passed as an argument.
void GPIO_SetPin(uint8_t pin); // Function to set a specific pin to high. The pin number is passed as an argument.
void GPIO_ClearPin(uint8_t pin); // Function to clear the state of a specific pin (set it to low). The pin number is passed as an argument.

#endif // End of include guard

