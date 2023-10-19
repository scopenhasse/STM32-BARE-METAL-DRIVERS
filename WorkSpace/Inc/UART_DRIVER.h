/**
 *  @file : UART_DRIVER.h
 * 	@brief :header file for the UART driver
 */

#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "stm32f3_Registers.h"
// UART 2 is connecter to APB1 bit 17

void InitUSART2();
void TransmitDataUART2(uint8_t data);

#endif /* UART_DRIVER_H_ */
