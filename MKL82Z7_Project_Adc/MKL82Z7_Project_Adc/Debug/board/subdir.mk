################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/peripherals.c \
../board/pin_mux.c 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/peripherals.d \
./board/pin_mux.d 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/peripherals.o \
./board/pin_mux.o 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c board/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL82Z128VLK7 -DCPU_MKL82Z128VLK7_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\board" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\source" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\CMSIS" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\drivers" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\device" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\component\uart" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\component\serial_manager" -I"D:\Embedded C\MKL82Z7_Project_Adc\MKL82Z7_Project_Adc\utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-board

clean-board:
	-$(RM) ./board/board.d ./board/board.o ./board/clock_config.d ./board/clock_config.o ./board/peripherals.d ./board/peripherals.o ./board/pin_mux.d ./board/pin_mux.o

.PHONY: clean-board

