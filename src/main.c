#include "gpio.h"

const uint8_t pin = 14;
const uint8_t pin2 = 13;
uint32_t delay_value = 1000000;

void delay(uint32_t value){
    for(volatile uint32_t i = 0; i < value; i++);
}


int main(void){

	GPIO_ClockEnable();
	GPIO_SetOutput(pin);
    GPIO_SetOutput(pin2);
	
	while(1){
		GPIO_Toggle(pin);
		delay(delay_value);
        GPIO_Toggle(pin2);
        delay(delay_value);
	}
}	
