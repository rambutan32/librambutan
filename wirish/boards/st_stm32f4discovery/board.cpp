/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2015 Bryan Newbold
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

/**
 * @file   wirish/boards/st_stm32f4discovery/board.cpp
 * @author Bryan Newbold <bnewbold@robocracy.org>
 * @brief  st_stm32f4discovery board file (based on Maple Native)
 */

#include <board/board.h>

#include <libmaple/fsmc.h>
#include <libmaple/gpio.h>
#include <libmaple/rcc.h>
#include <libmaple/timer.h>

#include <wirish/wirish_types.h>

static void initSRAMChip(void);

void boardInit(void) {
    initSRAMChip();
}

extern const stm32_pin_info PIN_MAP[BOARD_NR_GPIO_PINS] = {

    /* {gpio_dev, timer_dev, adc_dev, gpio_bit, timer_channel, adc_channel} */
    /* XXX: haven't filled in timer or ADC info here */
    {GPIOA, ADC123, TIM5,  0, 1,    0},
    {GPIOA,   NULL, NULL,  1, 0, ADCx},
    {GPIOA,   NULL, NULL,  2, 0, ADCx},
    {GPIOA,   NULL, NULL,  3, 0, ADCx},
    {GPIOA,   NULL, NULL,  4, 0, ADCx},
    {GPIOA,   NULL, NULL,  5, 0, ADCx},
    {GPIOA,   NULL, NULL,  6, 0, ADCx},
    {GPIOA,   NULL, NULL,  7, 0, ADCx},
    {GPIOA,   NULL, NULL,  8, 0, ADCx},
    {GPIOA,   NULL, NULL,  9, 0, ADCx},
    {GPIOA,   NULL, NULL, 10, 0, ADCx},
    {GPIOA,   NULL, NULL, 11, 0, ADCx},
    {GPIOA,   NULL, NULL, 12, 0, ADCx},
    {GPIOA,   NULL, NULL, 13, 0, ADCx},
    {GPIOA,   NULL, NULL, 14, 0, ADCx},
    {GPIOA,   NULL, NULL, 15, 0, ADCx},

    {GPIOB,   NULL, NULL,  0, 0, ADCx},
    {GPIOB,   NULL, NULL,  1, 0, ADCx},
    {GPIOB,   NULL, NULL,  2, 0, ADCx},
    {GPIOB,   NULL, NULL,  3, 0, ADCx},
    {GPIOB,   NULL, NULL,  4, 0, ADCx},
    {GPIOB,   NULL, NULL,  5, 0, ADCx},
    {GPIOB,   NULL, NULL,  6, 0, ADCx},
    {GPIOB,   NULL, NULL,  7, 0, ADCx},
    {GPIOB,   NULL, NULL,  8, 0, ADCx},
    {GPIOB,   NULL, NULL,  9, 0, ADCx},
    {GPIOB,   NULL, NULL, 10, 0, ADCx},
    {GPIOB,   NULL, NULL, 11, 0, ADCx},
    {GPIOB,   NULL, NULL, 12, 0, ADCx},
    {GPIOB,   NULL, NULL, 13, 0, ADCx},
    {GPIOB,   NULL, NULL, 14, 0, ADCx},
    {GPIOB,   NULL, NULL, 15, 0, ADCx},

    {GPIOC,   NULL, NULL,  0, 0, ADCx},
    {GPIOC,   NULL, NULL,  1, 0, ADCx},
    {GPIOC,   NULL, NULL,  2, 0, ADCx},
    {GPIOC,   NULL, NULL,  3, 0, ADCx},
    {GPIOC,   NULL, NULL,  4, 0, ADCx},
    {GPIOC,   NULL, NULL,  5, 0, ADCx},
    {GPIOC,   NULL, NULL,  6, 0, ADCx},
    {GPIOC,   NULL, NULL,  7, 0, ADCx},
    {GPIOC,   NULL, NULL,  8, 0, ADCx},
    {GPIOC,   NULL, NULL,  9, 0, ADCx},
    {GPIOC,   NULL, NULL, 10, 0, ADCx},
    {GPIOC,   NULL, NULL, 11, 0, ADCx},
    {GPIOC,   NULL, NULL, 12, 0, ADCx},
    {GPIOC,   NULL, NULL, 13, 0, ADCx},
    {GPIOC,   NULL, NULL, 14, 0, ADCx},
    {GPIOC,   NULL, NULL, 15, 0, ADCx},

    {GPIOD,   NULL, NULL,  0, 0, ADCx},
    {GPIOD,   NULL, NULL,  1, 0, ADCx},
    {GPIOD,   NULL, NULL,  2, 0, ADCx},
    {GPIOD,   NULL, NULL,  3, 0, ADCx},
    {GPIOD,   NULL, NULL,  4, 0, ADCx},
    {GPIOD,   NULL, NULL,  5, 0, ADCx},
    {GPIOD,   NULL, NULL,  6, 0, ADCx},
    {GPIOD,   NULL, NULL,  7, 0, ADCx},
    {GPIOD,   NULL, NULL,  8, 0, ADCx},
    {GPIOD,   NULL, NULL,  9, 0, ADCx},
    {GPIOD,   NULL, NULL, 10, 0, ADCx},
    {GPIOD,   NULL, NULL, 11, 0, ADCx},
    {GPIOD,   NULL, NULL, 12, 0, ADCx},
    {GPIOD,   NULL, NULL, 13, 0, ADCx},
    {GPIOD,   NULL, NULL, 14, 0, ADCx},
    {GPIOD,   NULL, NULL, 15, 0, ADCx},

    {GPIOE,   NULL, NULL,  0, 0, ADCx},
    {GPIOE,   NULL, NULL,  1, 0, ADCx},
    {GPIOE,   NULL, NULL,  2, 0, ADCx},
    {GPIOE,   NULL, NULL,  3, 0, ADCx},
    {GPIOE,   NULL, NULL,  4, 0, ADCx},
    {GPIOE,   NULL, NULL,  5, 0, ADCx},
    {GPIOE,   NULL, NULL,  6, 0, ADCx},
    {GPIOE,   NULL, NULL,  7, 0, ADCx},
    {GPIOE,   NULL, NULL,  8, 0, ADCx},
    {GPIOE,   NULL, NULL,  9, 0, ADCx},
    {GPIOE,   NULL, NULL, 10, 0, ADCx},
    {GPIOE,   NULL, NULL, 11, 0, ADCx},
    {GPIOE,   NULL, NULL, 12, 0, ADCx},
    {GPIOE,   NULL, NULL, 13, 0, ADCx},
    {GPIOE,   NULL, NULL, 14, 0, ADCx},
    {GPIOE,   NULL, NULL, 15, 0, ADCx},
};

extern const uint8 boardPWMPins[BOARD_NR_PWM_PINS] __FLASH__ = {
    /* XXX: haven't filled in timer or ADC info here */
};

extern const uint8 boardADCPins[BOARD_NR_ADC_PINS] __FLASH__ = {
    /* XXX: haven't filled in timer or ADC info here */
};

extern const uint8 boardUsedPins[BOARD_NR_USED_PINS] __FLASH__ = {
    BOARD_LED_PIN, BOARD_BUTTON_PIN, BOARD_JTMS_SWDIO_PIN,
    BOARD_JTCK_SWCLK_PIN, BOARD_JTDI_PIN, BOARD_JTDO_PIN, BOARD_NJTRST_PIN,
    /* XXX: haven't filled in timer or ADC info here */
};

