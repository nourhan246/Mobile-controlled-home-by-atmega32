################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Program.c \
../EEPROM_program.c \
../IIC_program.c \
../LCD_prgram.c \
../UART_program.c \
../main.c \
../menue.c 

OBJS += \
./DIO_Program.o \
./EEPROM_program.o \
./IIC_program.o \
./LCD_prgram.o \
./UART_program.o \
./main.o \
./menue.o 

C_DEPS += \
./DIO_Program.d \
./EEPROM_program.d \
./IIC_program.d \
./LCD_prgram.d \
./UART_program.d \
./main.d \
./menue.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


