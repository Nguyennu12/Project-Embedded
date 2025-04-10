################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mke16z4.c 

C_DEPS += \
./startup/startup_mke16z4.d 

OBJS += \
./startup/startup_mke16z4.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c startup/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKE16Z64VLF4 -DCPU_MKE16Z64VLF4_cm0plus -DSDK_OS_BAREMETAL -DSERIAL_PORT_TYPE_UART=1 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\board" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\source" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\drivers" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\device" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\CMSIS" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\component\uart" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\component\serial_manager" -I"D:\Embedded C\MKE16Z4_Project_PWM\MKE16Z4_Project\utilities" -O0 -fno-common -g3 -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_mke16z4.d ./startup/startup_mke16z4.o

.PHONY: clean-startup

