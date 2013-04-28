################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/CDC.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/HID.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/HardwareSerial.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/IPAddress.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Print.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Stream.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Tone.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/USBCore.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WMath.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WString.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/main.cpp \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/new.cpp 

C_SRCS += \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WInterrupts.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/malloc.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_analog.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_digital.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_pulse.c \
/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_shift.c 

OBJS += \
./arduino/CDC.o \
./arduino/HID.o \
./arduino/HardwareSerial.o \
./arduino/IPAddress.o \
./arduino/Print.o \
./arduino/Stream.o \
./arduino/Tone.o \
./arduino/USBCore.o \
./arduino/WInterrupts.o \
./arduino/WMath.o \
./arduino/WString.o \
./arduino/main.o \
./arduino/malloc.o \
./arduino/new.o \
./arduino/wiring.o \
./arduino/wiring_analog.o \
./arduino/wiring_digital.o \
./arduino/wiring_pulse.o \
./arduino/wiring_shift.o 

C_DEPS += \
./arduino/WInterrupts.d \
./arduino/malloc.d \
./arduino/wiring.d \
./arduino/wiring_analog.d \
./arduino/wiring_digital.d \
./arduino/wiring_pulse.d \
./arduino/wiring_shift.d 

CPP_DEPS += \
./arduino/CDC.d \
./arduino/HID.d \
./arduino/HardwareSerial.d \
./arduino/IPAddress.d \
./arduino/Print.d \
./arduino/Stream.d \
./arduino/Tone.d \
./arduino/USBCore.d \
./arduino/WMath.d \
./arduino/WString.d \
./arduino/main.d \
./arduino/new.d 


# Each subdirectory must supply rules for building sources it contributes
arduino/CDC.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HID.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/HID.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/HardwareSerial.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/IPAddress.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Print.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Stream.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/Tone.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/USBCore.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WInterrupts.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WMath.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/WString.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/main.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/malloc.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/malloc.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/new.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_PID= -DUSB_VID= -DARDUINO=104 -Wall -Os -fno-exceptions -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_analog.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_digital.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_pulse.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

arduino/wiring_shift.o: /home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/cores/arduino" -I"/home/rcbpeixoto/IDE/arduino-1.0.4/hardware/arduino/variants/standard" -DUSB_VID= -DUSB_PID= -DARDUINO=104 -Wall -Os -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -g  -ffunction-sections  -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"  -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


