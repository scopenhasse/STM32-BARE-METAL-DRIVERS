/**
 *  @file : GPIO_DRIVER.h
 * 	@brief :header file for the driver
 */
#include "stm32f3_Registers.h"

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

enum GPIOx_MODE{
	INPUT,
	OUTPUT
};

enum PIN_STATE{
	HIGH = 1,
	LOW = 0
};


void InitGPIOx(GPIOxTypeDef* gpio, uint8_t pin, enum GPIOx_MODE mode);

void WriteGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin, enum PIN_STATE state);

enum PIN_STATE ReadGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin);

#endif /* GPIO_DRIVER_H_ */
