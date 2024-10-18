################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Inc/DrumMachine/DrumMachine.cpp \
../Core/Inc/DrumMachine/Sequencer.cpp 

OBJS += \
./Core/Inc/DrumMachine/DrumMachine.o \
./Core/Inc/DrumMachine/Sequencer.o 

CPP_DEPS += \
./Core/Inc/DrumMachine/DrumMachine.d \
./Core/Inc/DrumMachine/Sequencer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Inc/DrumMachine/%.o Core/Inc/DrumMachine/%.su Core/Inc/DrumMachine/%.cyclo: ../Core/Inc/DrumMachine/%.cpp Core/Inc/DrumMachine/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Inc-2f-DrumMachine

clean-Core-2f-Inc-2f-DrumMachine:
	-$(RM) ./Core/Inc/DrumMachine/DrumMachine.cyclo ./Core/Inc/DrumMachine/DrumMachine.d ./Core/Inc/DrumMachine/DrumMachine.o ./Core/Inc/DrumMachine/DrumMachine.su ./Core/Inc/DrumMachine/Sequencer.cyclo ./Core/Inc/DrumMachine/Sequencer.d ./Core/Inc/DrumMachine/Sequencer.o ./Core/Inc/DrumMachine/Sequencer.su

.PHONY: clean-Core-2f-Inc-2f-DrumMachine

