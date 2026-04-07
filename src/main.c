#include "gpio.h"

const uint8_t pin = 13;
const uint8_t pin2 = 14;
uint32_t delay_value = 1000000;

void delay(uint32_t value)
{
	for (volatile uint32_t i = 0; i < value; i++);
}

void LED_On(void){
	GPIO_SetPin(pin);
	GPIO_SetPin(pin2);
}

void LED_Off(void){
	GPIO_ClearPin(pin);
	GPIO_ClearPin(pin2);
}

int main(void)
{

	GPIO_ClockEnable();
	GPIO_SetOutput(pin);
	GPIO_SetOutput(pin2);

	while (1)
	{
		LED_On();
		delay(delay_value);
		LED_Off();
		delay(delay_value);
	}
}
