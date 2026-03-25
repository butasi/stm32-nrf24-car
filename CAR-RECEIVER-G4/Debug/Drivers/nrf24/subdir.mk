################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/nrf24/NRF24.c 

OBJS += \
./Drivers/nrf24/NRF24.o 

C_DEPS += \
./Drivers/nrf24/NRF24.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/nrf24/%.o Drivers/nrf24/%.su Drivers/nrf24/%.cyclo: ../Drivers/nrf24/%.c Drivers/nrf24/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../USB_Device/App -I"/home/rodgers/STM32CubeIDE/workspace_2.1.0/CAR-RECEIVER-G4/Drivers/nrf24" -I../USB_Device/Target -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-nrf24

clean-Drivers-2f-nrf24:
	-$(RM) ./Drivers/nrf24/NRF24.cyclo ./Drivers/nrf24/NRF24.d ./Drivers/nrf24/NRF24.o ./Drivers/nrf24/NRF24.su

.PHONY: clean-Drivers-2f-nrf24

