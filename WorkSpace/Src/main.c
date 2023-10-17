/**
 ******************************************************************************
 * @file           : main.c
 * @author         : ILYAS NHASSE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 ILYAS NHASSE.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided MIT License.
 *
 ******************************************************************************
 */

#include"GPIO_DRIVER.h"


int main(void)
{
	InitGPIOx(GPIOB, 3, OUTPUT);

	while(1){
		WriteGPIOxPINx(GPIOB,3,HIGH);
		for(int i=0;i<1000000;i++){}
		WriteGPIOxPINx(GPIOB,3,LOW);
		for(int i=0;i<1000000;i++){}
	}
}
