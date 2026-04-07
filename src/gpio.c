#include "gpio.h"

void GPIO_ClockEnable(void)
{
	RCC_AHB1ENR |= (1U << 2);
}

void GPIO_SetOutput(uint8_t pin)
{
	GPIOC_MODER &= ~(3U << (pin * 2));
	GPIOC_MODER |=  (1U << (pin * 2));
}

void GPIO_Toggle(uint8_t pin)
{
	GPIOC_ODR ^= (1U << pin);
}

void GPIO_SetPin(uint8_t pin){
	GPIOC_ODR |= (1U << pin);
}

void GPIO_ClearPin(uint8_t pin){
	GPIOC_ODR &= ~(1U << pin);
}