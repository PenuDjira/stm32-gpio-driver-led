#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Register base address
#define RCC_BASE 0x40023800U
#define GPIOC_BASE 0x40020800U

// Register Definitions
#define RCC_AHB1ENR (*(volatile uint32_t *)(RCC_BASE + 0x30U))
#define GPIOC_MODER (*(volatile uint32_t *)(GPIOC_BASE + 0x00U))
#define GPIOC_ODR	(*(volatile uint32_t *)(GPIOC_BASE + 0x14U))

// Function declarations
void GPIO_ClockEnable(void);
void GPIO_SetOutput(uint8_t pin);
void GPIO_Toggle(uint8_t pin);

#endif
