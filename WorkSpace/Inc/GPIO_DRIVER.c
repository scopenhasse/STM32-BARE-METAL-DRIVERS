/**
 *  @file : GPIO_DRIVER.c
 * 	@brief :source file for the driver
 */
#include "GPIO_DRIVER.h"

void InitGPIOx(GPIOxTypeDef* gpio, uint8_t pin, enum GPIOx_MODE mode){

	if(gpio == GPIOA){
		RCC->RCC_AHBEN_R |= GPIOAEN;
		switch(mode){
			case INPUT:
				GPIOA->MODE_R &= ~(1U<<(pin*2));
				GPIOA->MODE_R &= ~(1U<<((pin*2)+1));
				break;
			case OUTPUT:
				GPIOA->MODE_R |= (1U<<(pin*2));
				GPIOA->MODE_R &= ~(1U<<((pin*2)+1));
				break;
			default:
				break;
			}
	}
	else if(gpio == GPIOB){
		RCC->RCC_AHBEN_R |= GPIOBEN;
		switch(mode){
			case INPUT:
				GPIOB->MODE_R &= ~(1U<<(pin*2));
				GPIOB->MODE_R &= ~(1U<<((pin*2)+1));
				break;
			case OUTPUT:
				GPIOB->MODE_R |= (1U<<(pin*2));
				GPIOB->MODE_R &= ~(1U<<((pin*2)+1));
				break;
			default:
				break;
		}
	}
	else{
	}
}

void WriteGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin, enum PIN_STATE state){

	switch(state){
		case HIGH:
			GPIO->OD_R |= (1U<<pin);
			break;
		case LOW:
			GPIO->OD_R &= ~(1U<<pin);
			break;
		default:
			break;
	}
}

enum PIN_STATE ReadGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin){
	int r;
	if(GPIO->ID_R & (1U<<pin)){
		r = 1;
	}
	else if(GPIO->ID_R & ~(1U<<pin)){
		r = 0;
	}
	else{
	}

	return r;
}
