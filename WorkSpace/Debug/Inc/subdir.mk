################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/GPIO_DRIVER.c \
../Inc/UART_DRIVER.c 

OBJS += \
./Inc/GPIO_DRIVER.o \
./Inc/UART_DRIVER.o 

C_DEPS += \
./Inc/GPIO_DRIVER.d \
./Inc/UART_DRIVER.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su Inc/%.cyclo: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F303K8Tx -DSTM32F3 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/GPIO_DRIVER.cyclo ./Inc/GPIO_DRIVER.d ./Inc/GPIO_DRIVER.o ./Inc/GPIO_DRIVER.su ./Inc/UART_DRIVER.cyclo ./Inc/UART_DRIVER.d ./Inc/UART_DRIVER.o ./Inc/UART_DRIVER.su

.PHONY: clean-Inc

