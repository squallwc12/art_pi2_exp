################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_cio.c \
D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_heap_stack.c \
D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_time.c 

OBJS += \
./User/std/std_cio.o \
./User/std/std_heap_stack.o \
./User/std/std_time.o 

C_DEPS += \
./User/std/std_cio.d \
./User/std/std_heap_stack.d \
./User/std/std_time.d 


# Each subdirectory must supply rules for building sources it contributes
User/std/std_cio.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_cio.c User/std/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/std/std_heap_stack.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_heap_stack.c User/std/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/std/std_time.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/std/src/std_time.c User/std/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-std

clean-User-2f-std:
	-$(RM) ./User/std/std_cio.cyclo ./User/std/std_cio.d ./User/std/std_cio.o ./User/std/std_cio.su ./User/std/std_heap_stack.cyclo ./User/std/std_heap_stack.d ./User/std/std_heap_stack.o ./User/std/std_heap_stack.su ./User/std/std_time.cyclo ./User/std/std_time.d ./User/std/std_time.o ./User/std/std_time.su

.PHONY: clean-User-2f-std

