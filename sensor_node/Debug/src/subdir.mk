################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f0xx_it.c \
../src/syscalls.c \
../src/system_stm32f0xx.c 

OBJS += \
./src/main.o \
./src/stm32f0xx_it.o \
./src/syscalls.o \
./src/system_stm32f0xx.o 

C_DEPS += \
./src/main.d \
./src/stm32f0xx_it.d \
./src/syscalls.d \
./src/system_stm32f0xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -DSTM32F0 -DSTM32F042K6Tx -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F042x6 -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib" -I"C:/Users/Craig/workspace/sensor_node/sensor_node/inc" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/CMSIS/core" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/CMSIS/device" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/HAL_Driver/Inc/Legacy" -I"C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/HAL_Driver/Inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


