################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_exception.c \
D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_flash.c \
D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_timer.c \
D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_xspi.c 

OBJS += \
./User/bsp/bsp_exception.o \
./User/bsp/bsp_flash.o \
./User/bsp/bsp_timer.o \
./User/bsp/bsp_xspi.o 

C_DEPS += \
./User/bsp/bsp_exception.d \
./User/bsp/bsp_flash.d \
./User/bsp/bsp_timer.d \
./User/bsp/bsp_xspi.d 


# Each subdirectory must supply rules for building sources it contributes
User/bsp/bsp_exception.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_exception.c User/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/bsp/bsp_flash.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_flash.c User/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/bsp/bsp_timer.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_timer.c User/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/bsp/bsp_xspi.o: D:/Embedded_Software/GitHub/art_pi2_exp/User/bsp/src/bsp_xspi.c User/bsp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_APPLI -DTX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../applications/components/drivers/sd_card/inc -I../../User/third_party/perf_counter -I../User/third_party/perf_counter -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-bsp

clean-User-2f-bsp:
	-$(RM) ./User/bsp/bsp_exception.cyclo ./User/bsp/bsp_exception.d ./User/bsp/bsp_exception.o ./User/bsp/bsp_exception.su ./User/bsp/bsp_flash.cyclo ./User/bsp/bsp_flash.d ./User/bsp/bsp_flash.o ./User/bsp/bsp_flash.su ./User/bsp/bsp_timer.cyclo ./User/bsp/bsp_timer.d ./User/bsp/bsp_timer.o ./User/bsp/bsp_timer.su ./User/bsp/bsp_xspi.cyclo ./User/bsp/bsp_xspi.d ./User/bsp/bsp_xspi.o ./User/bsp/bsp_xspi.su

.PHONY: clean-User-2f-bsp

