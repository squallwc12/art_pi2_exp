################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Github_cpy/art_pi2_exp/User/bsp_components/mx25uw25645g/mx25uw25645g.c 

OBJS += \
./User/bsp_components/mx25uw25645g/mx25uw25645g.o 

C_DEPS += \
./User/bsp_components/mx25uw25645g/mx25uw25645g.d 


# Each subdirectory must supply rules for building sources it contributes
User/bsp_components/mx25uw25645g/mx25uw25645g.o: D:/Github_cpy/art_pi2_exp/User/bsp_components/mx25uw25645g/mx25uw25645g.c User/bsp_components/mx25uw25645g/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-bsp_components-2f-mx25uw25645g

clean-User-2f-bsp_components-2f-mx25uw25645g:
	-$(RM) ./User/bsp_components/mx25uw25645g/mx25uw25645g.cyclo ./User/bsp_components/mx25uw25645g/mx25uw25645g.d ./User/bsp_components/mx25uw25645g/mx25uw25645g.o ./User/bsp_components/mx25uw25645g/mx25uw25645g.su

.PHONY: clean-User-2f-bsp_components-2f-mx25uw25645g

