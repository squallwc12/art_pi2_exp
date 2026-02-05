################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Github_cpy/art_pi2_exp/User/bsp_components/aps256xx/aps256xx.c 

OBJS += \
./User/bsp_components/aps256xx/aps256xx.o 

C_DEPS += \
./User/bsp_components/aps256xx/aps256xx.d 


# Each subdirectory must supply rules for building sources it contributes
User/bsp_components/aps256xx/aps256xx.o: D:/Github_cpy/art_pi2_exp/User/bsp_components/aps256xx/aps256xx.c User/bsp_components/aps256xx/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-bsp_components-2f-aps256xx

clean-User-2f-bsp_components-2f-aps256xx:
	-$(RM) ./User/bsp_components/aps256xx/aps256xx.cyclo ./User/bsp_components/aps256xx/aps256xx.d ./User/bsp_components/aps256xx/aps256xx.o ./User/bsp_components/aps256xx/aps256xx.su

.PHONY: clean-User-2f-bsp_components-2f-aps256xx

