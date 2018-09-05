################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: sensor_timer.elf

dependents:
	-cd C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/Debug && $(MAKE) all

# Tool invocations
sensor_timer.elf: $(OBJS) $(USER_OBJS) C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/Debug/libsensortime911_hal_lib.a C:\Users\Craig\workspace\sensor_node\sensor_timer\LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft -L"C:\Users\Craig\workspace\sensor_node\sensortime911_hal_lib\Debug" -T"C:\Users\Craig\workspace\sensor_node\sensor_timer\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "sensor_timer.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "sensor_timer.elf" "sensor_timer.bin"
	arm-none-eabi-size "sensor_timer.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
C:/Users/Craig/workspace/sensor_node/sensortime911_hal_lib/Debug/libsensortime911_hal_lib.a:

-include ../makefile.targets
