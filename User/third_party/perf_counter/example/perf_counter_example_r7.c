/**
  ******************************************************************************
  * @file           : perf_counter_example_r7.c
  * @brief          : Performance Counter Example for R7
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 Chadwick.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "perf_counter.h"
#include "perf_counter_example_r7.h"

/* Private includes ----------------------------------------------------------*/
#include "std_cio.h"

/* Private typedef -----------------------------------------------------------*/
typedef struct example_lv1_t {
    uint32_t wLV1A;
    uint16_t hwLV1B;
    uint8_t  chLV1C;
    uint8_t  chLV1D;
}example_lv1_t;

typedef struct example_lv0_t {

    uint32_t    wA;
    uint16_t    hwB;
    uint8_t     chC;
    uint8_t     chID;
    example_lv1_t tLV1;
} example_lv0_t;

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
static example_lv0_t s_tItem[8] = {
    {.chID = 0},
    {.chID = 1},
    {.chID = 2},
    {.chID = 3},
    {.chID = 4},
    {.chID = 5},
    {.chID = 6},
    {.chID = 7},
};

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

#if __IS_COMPILER_ARM_COMPILER__
#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#   pragma clang diagnostic ignored "-Wdouble-promotion"
#endif
uint32_t calculate_stack_usage_topdown(void)
{
    extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Limit[];
    extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Length;

    uint32_t *pwStack = Image$$ARM_LIB_STACK$$ZI$$Limit;
    uint32_t wStackSize = (uintptr_t)&Image$$ARM_LIB_STACK$$ZI$$Length / 4;
    uint32_t wStackUsed = 0;


    do {
        if (*--pwStack == 0xDEADBEEF) {
            break;
        }
        wStackUsed++;
    } while(--wStackSize);


    printf("\r\nStack Usage: [%d/%d] %2.2f%%\r\n",
            wStackUsed * 4,
            (uintptr_t)&Image$$ARM_LIB_STACK$$ZI$$Length,
            (   (float)wStackUsed * 400.0f
            /   (float)(uintptr_t)&Image$$ARM_LIB_STACK$$ZI$$Length));

    return wStackUsed * 4;
}

uint32_t calculate_stack_usage_bottomup(void)
{
    extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Base[];
    extern uint32_t Image$$ARM_LIB_STACK$$ZI$$Length;

    uint32_t *pwStack = Image$$ARM_LIB_STACK$$ZI$$Base;
    uint32_t wStackSize = (uintptr_t)&Image$$ARM_LIB_STACK$$ZI$$Length;
    uint32_t wStackUsed = wStackSize / 4;

    do {
        if (*pwStack++ != 0xDEADBEEF) {
            break;
        }
    } while(--wStackUsed);

    printf("\r\nStack Usage: [%d/%d] %2.2f%%\r\n",
            wStackUsed * 4,
            wStackSize,
            (   (float)wStackUsed * 400.0f / (float)wStackSize));

    return wStackUsed * 4;
}

#if defined(__clang__)
#   pragma clang diagnostic pop
#endif
#endif

/**
  * @brief  Performance Counter Example for R7
  * @param  None
  * @retval None
  */
void perf_counter_example_r7(void)
{
    int32_t iCycleResult = 0;

    __perf_counter_printf__("Performance Counter Example for R7 Start...\r\n");


    /*! demo of using() block */
    using(int a = 0,printf("========= On Enter =======\r\n"),
                    printf("========= On Leave =======\r\n")) {
        __perf_counter_printf__("\t In Body a=%d \r\n", ++a);
    }

    __cycleof__("Calibration") {}

    __perf_counter_printf__("\r\n\r\n\r\n\r\n");

    /* measure cycles and store it in a dedicated variable without printf */
    __cycleof__("delay_us(1000ul)",
        /* insert code to __cycleof__ body, "{}" can be omitted  */
        {
            iCycleResult = __cycle_count__;   /*< "__cycle_count__" stores the result */
        }) {
        perfc_delay_us(1000ul);
    }

    perfc_delay_ms(500);

    __perf_counter_printf__("\r\n delay_us(1000ul) takes %"PRIi32" cycles\r\n", (int32_t)iCycleResult);

    __perf_counter_printf__("Long Delay Test Start...Please wait for 10s...\r\n");
    //__IRQ_SAFE {
        perfc_delay_ms(1000);
    //}
    __perf_counter_printf__("Long Delay Test End...\r\n");

    /*! demo of with block */
    with(example_lv0_t, &s_tItem[0], pitem) {
        _->wA = 1;
        _->hwB = 2;
        _->chC = 3;

        with(&pitem->tLV1) {
            _->wLV1A = 4;
            _->hwLV1B = 5;
            _->chLV1C = 6;
        }
    }

    //! demo of using clock() in timer.h
    do {
        int64_t tStart = get_system_ticks();
        __IRQ_SAFE {
            printf("no interrupt \r\n");
        }
        __perf_counter_printf__("used clock cycle: %"PRIi32, (int32_t)(get_system_ticks() - tStart));
    } while(0);

#if __IS_COMPILER_ARM_COMPILER__
    calculate_stack_usage_topdown();
    calculate_stack_usage_bottomup();
#endif

#ifdef __PERF_COUNTER_COREMARK__
    coremark_main();
#endif

#if __IS_COMPILER_ARM_COMPILER__

    uintptr_t nStackLimit = (uintptr_t)Image$$ARM_LIB_STACK$$ZI$$Base;
#else
    //extern uintptr_t __StackLimit[];
    //uintptr_t nStackLimit = (uintptr_t)__StackLimit;
#endif
    /*
    __perf_counter_printf__("\t\tSystem Stack Remain: %"PRIu32 "\r\n",
                            perfc_stack_remain((uintptr_t)nStackLimit));

    if (perfc_is_time_out_ms(10000)) {
        __perf_counter_printf__("\r[%010"PRIi64"]\r\n", get_system_ticks());
    }
    */


    __perf_counter_printf__("Performance Counter Example for R7 End.\r\n");
}
