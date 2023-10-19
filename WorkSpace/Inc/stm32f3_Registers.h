

#ifndef STM32F3_REGISTERS_H_
#define STM32F3_REGISTERS_H_

#include "stdint.h"
#define __IO volatile

#define PERIPHRAL_BASE 			(0x40000000UL)

#define AHB2_PERIPHRAL_OFFSET	(0x08000000UL)
#define AHB2_PERIPHRAL_BASE		(PERIPHRAL_BASE + AHB2_PERIPHRAL_OFFSET)

#define APB1_PERIPHRAL_OFFSET	(0x00002800UL)
#define APB1_PERIPHRAL_BASE		(PERIPHRAL_BASE + APB1_PERIPHRAL_OFFSET)

#define GPIOA_OFFSET 			(0x00000000UL)
#define GPIOA_BASE				(AHB2_PERIPHRAL_BASE + GPIOA_OFFSET)
#define GPIOB_OFFSET 			(0x00000400UL)
#define GPIOB_BASE				(AHB2_PERIPHRAL_BASE + GPIOB_OFFSET)

#define AHB1_PERIPHRAL_OFFSET	(0x00020000UL)
#define AHB1_PERIPHRAL_BASE		(PERIPHRAL_BASE + AHB1_PERIPHRAL_OFFSET)

#define RCC_OFFSET				(0x00001000UL)
#define RCC_BASE				(AHB1_PERIPHRAL_BASE + RCC_OFFSET)

#define USART2_OFFSET			(0x00004400UL)
#define USART2_BASE				(APB1_PERIPHRAL_BASE + USART2_OFFSET)

#define GPIOAEN					(1U<<17)
#define GPIOBEN					(1U<<18)

typedef struct {
	__IO uint32_t RCC_C_R; 			//0x00
	__IO uint32_t RCC_CFG_R;		//0x04
	__IO uint32_t RCC_CI_R;			//0x08
	__IO uint32_t RCC_APB2RST_R;	//0x0C
	__IO uint32_t RCC_APB1RST_R;	//0x10
	__IO uint32_t RCC_AHBEN_R;		//0x14
	__IO uint32_t RCC_APB2EN_R;		//0x18
	__IO uint32_t RCC_APB1EN_R;		//0x1C
	__IO uint32_t RCC_BDC_R;		//0x20
	__IO uint32_t RCC_CS_R;			//0x24
	__IO uint32_t RCC_AHBRST_R;		//0x28
	__IO uint32_t RCC_CFG_R2;		//0x2C
	__IO uint32_t RCC_CFG_R3;		//0x30
}RCCTypeDef;

#define RCC		((RCCTypeDef*) RCC_BASE)

typedef struct {
	__IO uint32_t MODE_R;
	__IO uint32_t OTYPE_R;
	__IO uint32_t OSPEED_R;
	__IO uint32_t PUPD_R;
	__IO uint32_t ID_R;
	__IO uint32_t OD_R;
	__IO uint32_t BSR_R;
	__IO uint32_t LCK_R;
	__IO uint32_t AF_R [2];
	__IO uint32_t BR_R;
}GPIOxTypeDef;

#define GPIOA ((GPIOxTypeDef*) GPIOA_BASE)
#define GPIOB ((GPIOxTypeDef*) GPIOB_BASE)



typedef struct {
	__IO uint32_t USART_CTR1_R; 			//0x00
	__IO uint32_t USART_CTR2_R;		//0x04
	__IO uint32_t USART_CTR3_R;			//0x08
	__IO uint32_t USART_BR_R;	//0x0C
	__IO uint32_t USART_GTP_R;	//0x10
	__IO uint32_t USART_RTO_R;		//0x14
	__IO uint32_t USART_RQ_R;		//0x18
	__IO uint32_t USART_ISR_R;		//0x1C
	__IO uint32_t USART_ICR_R;		//0x20
	__IO uint32_t USART_RD_R;			//0x24
	__IO uint32_t USART_TD_R;		//0x28
}USARTTypeDef;



#define UART2 ((USARTTypeDef*) USART2_BASE)


#endif /* STM32F3_REGISTERS_H_ */
