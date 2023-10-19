

#include "UART_DRIVER.h"

void InitUSART2(){
	RCC->RCC_APB1EN_R |= (1U<<17);
	RCC->RCC_AHBEN_R  |= GPIOAEN;
	GPIOA->AF_R[0] = 0x0700;
	GPIOA->MODE_R |= 0x0020;

	UART2->USART_BR_R = 0x0683;
	UART2->USART_CTR1_R = 0x0008;
	UART2->USART_CTR1_R |= 0x0001;
}

void TransmitDataUART2(uint8_t data){
	UART2->USART_TD_R = (data & 0xFF);
}
