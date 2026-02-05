################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/perf_counter.c \
D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/perfc_port_default.c 

S_UPPER_SRCS += \
D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/systick_wrapper_gcc.S 

OBJS += \
./User/third_party/perf_cpunter/perf_counter.o \
./User/third_party/perf_cpunter/perfc_port_default.o \
./User/third_party/perf_cpunter/systick_wrapper_gcc.o 

S_UPPER_DEPS += \
./User/third_party/perf_cpunter/systick_wrapper_gcc.d 

C_DEPS += \
./User/third_party/perf_cpunter/perf_counter.d \
./User/third_party/perf_cpunter/perfc_port_default.d 


# Each subdirectory must supply rules for building sources it contributes
User/third_party/perf_cpunter/perf_counter.o: D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/perf_counter.c User/third_party/perf_cpunter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/third_party/perf_cpunter/perfc_port_default.o: D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/perfc_port_default.c User/third_party/perf_cpunter/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H7R7xx -DUSER_BOOT -c -I../Core/Inc -I../applications/boot/inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc -I../../Drivers/STM32H7RSxx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7RSxx/Include -I../../Drivers/CMSIS/Include -I../../User/std/inc -I../../User/bsp/inc -I../../User/bsp_components/w35t51nwtbie -I../../User/bsp_components/aps256xx -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
User/third_party/perf_cpunter/systick_wrapper_gcc.o: D:/Github_cpy/art_pi2_exp/User/third_party/perf_cpunter/systick_wrapper_gcc.S User/third_party/perf_cpunter/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@"  -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-User-2f-third_party-2f-perf_cpunter

clean-User-2f-third_party-2f-perf_cpunter:
	-$(RM) ./User/third_party/perf_cpunter/perf_counter.cyclo ./User/third_party/perf_cpunter/perf_counter.d ./User/third_party/perf_cpunter/perf_counter.o ./User/third_party/perf_cpunter/perf_counter.su ./User/third_party/perf_cpunter/perfc_port_default.cyclo ./User/third_party/perf_cpunter/perfc_port_default.d ./User/third_party/perf_cpunter/perfc_port_default.o ./User/third_party/perf_cpunter/perfc_port_default.su ./User/third_party/perf_cpunter/systick_wrapper_gcc.d ./User/third_party/perf_cpunter/systick_wrapper_gcc.o

.PHONY: clean-User-2f-third_party-2f-perf_cpunter

