################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f10x_it.c \
../src/system_stm32f10x.c 

OBJS += \
./src/main.o \
./src/stm32f10x_it.o \
./src/system_stm32f10x.o 

C_DEPS += \
./src/main.d \
./src/stm32f10x_it.d \
./src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Sourcery Linux GCC C Compiler'
	arm-none-eabi-gcc -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -I"/home/dragon/workspace/STM32F103C8T6_LibV3.5/STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/CMSIS/CM3/CoreSupport" -I"/home/dragon/workspace/STM32F103C8T6_LibV3.5/STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/STM32F10x_StdPeriph_Driver/inc" -I"/home/dragon/workspace/STM32F103C8T6_LibV3.5/inc" -I"/home/dragon/workspace/STM32F103C8T6_LibV3.5/STM32F10x_StdPeriph_Lib_V3.5.0/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x" -Os -ffunction-sections -fdata-sections -Wall -Wa,-adhlns="$@.lst" -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m3 -mthumb -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


