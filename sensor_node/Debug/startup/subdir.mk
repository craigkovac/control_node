################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo %cd%
	arm-none-eabi-as -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib" -I"C:/Users/Craig/workspace/sensor_node/sensor_node/inc" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/CMSIS/core" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/CMSIS/device" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/HAL_Driver/Inc" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


