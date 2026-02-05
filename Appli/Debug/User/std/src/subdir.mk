################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/GitHub/art_pi2_exp/User/std/src/std_cio.c \
D:/GitHub/art_pi2_exp/User/std/src/std_time.c 

OBJS += \
./User/std/src/std_cio.o \
./User/std/src/std_time.o 

C_DEPS += \
./User/std/src/std_cio.d \
./User/std/src/std_time.d 


# Each subdirectory must supply rules for building sources it contributes
User/std/src/std_cio.o: D:/GitHub/art_pi2_exp/User/std/src/std_cio.c User/std/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/std/src/std_time.o: D:/GitHub/art_pi2_exp/User/std/src/std_time.c User/std/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-std-2f-src

clean-User-2f-std-2f-src:
	-$(RM) ./User/std/src/std_cio.cyclo ./User/std/src/std_cio.d ./User/std/src/std_cio.o ./User/std/src/std_cio.su ./User/std/src/std_time.cyclo ./User/std/src/std_time.d ./User/std/src/std_time.o ./User/std/src/std_time.su

.PHONY: clean-User-2f-std-2f-src

