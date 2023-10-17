/**
 *  @file : GPIO_DRIVER.h
 * 	@brief :header file for the driver
 */
#include "stdint.h"

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#define __IO volatile

#define PERIPHRAL_BASE 			(0x40000000UL)

#define AHB2_PERIPHRAL_OFFSET	(0x08000000UL)
#define AHB2_PERIPHRAL_BASE		(PERIPHRAL_BASE + AHB2_PERIPHRAL_OFFSET)

#define GPIOA_OFFSET 			(0x00000000UL)
#define GPIOA_BASE				(AHB2_PERIPHRAL_BASE + GPIOA_OFFSET)
#define GPIOB_OFFSET 			(0x00000400UL)
#define GPIOB_BASE				(AHB2_PERIPHRAL_BASE + GPIOB_OFFSET)

#define AHB1_PERIPHRAL_OFFSET	(0x00020000UL)
#define AHB1_PERIPHRAL_BASE		(PERIPHRAL_BASE + AHB1_PERIPHRAL_OFFSET)

#define RCC_OFFSET				(0x00001000UL)
#define RCC_BASE				(AHB1_PERIPHRAL_BASE + RCC_OFFSET)

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

enum GPIOx_MODE{
	INPUT,
	OUTPUT
};

enum PIN_STATE{
	HIGH = 1,
	LOW = 0
};

#define GPIOA ((GPIOxTypeDef*) GPIOA_BASE)
#define GPIOB ((GPIOxTypeDef*) GPIOB_BASE)

void InitGPIOx(GPIOxTypeDef* gpio, uint8_t pin, enum GPIOx_MODE mode);

void WriteGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin, enum PIN_STATE state);

enum PIN_STATE ReadGPIOxPINx(GPIOxTypeDef * GPIO, uint8_t pin);

#endif /* GPIO_DRIVER_H_ */
