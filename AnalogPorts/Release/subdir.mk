################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../AnalogPorts.cpp 

OBJS += \
./AnalogPorts.o 

CPP_DEPS += \
./AnalogPorts.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbop/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbop/arduino-1.0.4/hardware/arduino/variants/standard" -I"/home/rcbop/workspaceArduino/AnalogPorts" -D__IN_ECLIPSE__=1 -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


