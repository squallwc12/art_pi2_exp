cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Compiler options
set(STM32_MCU_FLAGS  "-mcpu=cortex-m7 -mfpu=fpv5-d16 -mfloat-abi=hard " )

#Linker options
set(STM32_LINKER_SCRIPT stm32h7rsxx_RAMxspi1_ROMxspi2.ld)
set(STM32_LINKER_OPTION  )

# Include toolchain file
include("../gcc-arm-none-eabi.cmake")

# Set the project name
set(CMAKE_PROJECT_NAME art_pi2_exp_Appli)
project(${CMAKE_PROJECT_NAME})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Include mx-generated 
include("mx-generated.cmake")


# In order to use CMake for cross-compiling
set(CMAKE_CXX_COMPILER_FORCED "true") 

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE 
    # Add user defined symbols
)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    ${CMAKE_SOURCE_DIR}/User/bsp/inc
    ${CMAKE_SOURCE_DIR}/User/std/inc
    ${CMAKE_SOURCE_DIR}/User/third_party/perf_counter
    ${CMAKE_SOURCE_DIR}/User/third_party/perf_counter/example
    ${CMAKE_SOURCE_DIR}/applications/components/drivers/sd_card/inc
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    ${CMAKE_SOURCE_DIR}/applications/components/drivers/sd_card/src/sd_card.c
    ${CMAKE_SOURCE_DIR}/User/bsp/src/bsp_exception.c
    ${CMAKE_SOURCE_DIR}/User/bsp/src/bsp_flash.c
    ${CMAKE_SOURCE_DIR}/User/bsp/src/bsp_led.c
    ${CMAKE_SOURCE_DIR}/User/bsp/src/bsp_timer.c
    ${CMAKE_SOURCE_DIR}/User/std/src/std_cio.c
    ${CMAKE_SOURCE_DIR}/User/std/src/std_heap_stack.c
    ${CMAKE_SOURCE_DIR}/User/std/src/std_time.c
    ${CMAKE_SOURCE_DIR}/User/third_party/perf_counter/perf_counter.c
    ${CMAKE_SOURCE_DIR}/User/third_party/perf_counter/perfc_port_default.c
    ${CMAKE_SOURCE_DIR}/User/third_party/perf_counter/example/perf_counter_example_r7.c
)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined libraries
)

# Validate that STM32CubeMX code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()


# === 切换到 Standard C Runtime Library ===

# 1. 从链接标志中移除 nano.specs (如果存在)
string(REPLACE "--specs=nano.specs" "" CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS}")
string(REPLACE "--specs=nano.specs" "" CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")

# 2. 针对当前项目目标添加 Standard C 标志
# 使用 nosys.specs 是为了提供标准库所需的底层桩函数（如 _exit, _sbrk 等）
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "--specs=nosys.specs")

# 3. (可选) 如果你需要完整的 printf 浮点数支持，取消下面一行的注释
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "-Wl,-u,_printf_float")

# 4. 用 --wrap 拦截 SysTick_Handler，使 perfc_port_insert_to_system_timer_insert_ovf_handler()
#    能在 tx_initialize_low_level.S 定义的 SysTick_Handler 基础上被调用，
#    而无需修改汇编文件。
# target_link_options(${CMAKE_PROJECT_NAME} PRIVATE "-Wl,--wrap=SysTick_Handler")

# ========================================







