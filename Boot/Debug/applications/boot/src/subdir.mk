################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../applications/boot/src/app_boot.c 

OBJS += \
./applications/boot/src/app_boot.o 

C_DEPS += \
./applications/boot/src/app_boot.d 


# Each subdirectory must supply rules for building sources it contributes
applications/boot/src/%.o applications/boot/src/%.su applications/boot/src/%.cyclo: ../applications/boot/src/%.c applications/boot/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-applications-2f-boot-2f-src

clean-applications-2f-boot-2f-src:
	-$(RM) ./applications/boot/src/app_boot.cyclo ./applications/boot/src/app_boot.d ./applications/boot/src/app_boot.o ./applications/boot/src/app_boot.su

.PHONY: clean-applications-2f-boot-2f-src

