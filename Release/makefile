################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/STM32F10x_StdPeriph_Driver/src/subdir.mk
-include STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/TrueSTUDIO/subdir.mk
-include STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/CMSIS/CM3/CoreSupport/subdir.mk
-include STM32F10x_StdPeriph_Lib_V3.5.0/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
STM32F103C8T6_LibV3.5.hex \

SECONDARY_LIST += \
STM32F103C8T6_LibV3.5.lst \

SECONDARY_SIZE += \
STM32F103C8T6_LibV3.5.siz \


# All Target
all: STM32F103C8T6_LibV3.5.elf secondary-outputs

# Tool invocations
STM32F103C8T6_LibV3.5.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Sourcery Linux GCC C Linker'
	arm-none-eabi-gcc -T"/home/dragon/workspace/STM32F103C8T6_LibV3.5/STM32F10x_StdPeriph_Lib_V3.5.0/STM32F10X_MD.ld" -Xlinker --gc-sections -Wl,-Map,STM32F103C8T6_LibV3.5.map -mcpu=cortex-m3 -mthumb -o "STM32F103C8T6_LibV3.5.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STM32F103C8T6_LibV3.5.hex: STM32F103C8T6_LibV3.5.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary STM32F103C8T6_LibV3.5.elf  "STM32F103C8T6_LibV3.5.hex"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C8T6_LibV3.5.lst: STM32F103C8T6_LibV3.5.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Create Listing'
	arm-none-eabi-objdump -h -S STM32F103C8T6_LibV3.5.elf > "STM32F103C8T6_LibV3.5.lst"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C8T6_LibV3.5.siz: STM32F103C8T6_LibV3.5.elf
	@echo 'Invoking: ARM Sourcery Linux GNU Print Size'
	arm-none-eabi-size  --format=berkeley STM32F103C8T6_LibV3.5.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(EXECUTABLES)$(SECONDARY_LIST)$(S_UPPER_DEPS) STM32F103C8T6_LibV3.5.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
