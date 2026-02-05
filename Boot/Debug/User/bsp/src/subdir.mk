################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_exception.c \
D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_flash.c \
D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_xspi.c 

OBJS += \
./User/bsp/src/bsp_exception.o \
./User/bsp/src/bsp_flash.o \
./User/bsp/src/bsp_xspi.o 

C_DEPS += \
./User/bsp/src/bsp_exception.d \
./User/bsp/src/bsp_flash.d \
./User/bsp/src/bsp_xspi.d 


# Each subdirectory must supply rules for building sources it contributes
User/bsp/src/bsp_exception.o: D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_exception.c User/bsp/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/bsp/src/bsp_flash.o: D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_flash.c User/bsp/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/bsp/src/bsp_xspi.o: D:/Github_cpy/art_pi2_exp/User/bsp/src/bsp_xspi.c User/bsp/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-bsp-2f-src

clean-User-2f-bsp-2f-src:
	-$(RM) ./User/bsp/src/bsp_exception.cyclo ./User/bsp/src/bsp_exception.d ./User/bsp/src/bsp_exception.o ./User/bsp/src/bsp_exception.su ./User/bsp/src/bsp_flash.cyclo ./User/bsp/src/bsp_flash.d ./User/bsp/src/bsp_flash.o ./User/bsp/src/bsp_flash.su ./User/bsp/src/bsp_xspi.cyclo ./User/bsp/src/bsp_xspi.d ./User/bsp/src/bsp_xspi.o ./User/bsp/src/bsp_xspi.su

.PHONY: clean-User-2f-bsp-2f-src

