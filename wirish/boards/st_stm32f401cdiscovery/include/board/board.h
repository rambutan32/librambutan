/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
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
 * @file   wirish/boards/maple/include/board/board.h
 * @author Perry Huang <iperry@leaflabs.com>, Bryan Newbold <bnewbold@robocracy.org
 * @brief  STM32F401C Discovery board file.
 */

#ifndef _BOARD_STM32F401_DISCOVERY_H_
#define _BOARD_STM32F401_DISCOVERY_H_

/* 84 MHz -> 84 cycles per microsecond. */
#define CYCLES_PER_MICROSECOND  84

// PLL config for 8 MHz external crystal
// --> 84 MHz SYSCLK, with 48 MHz PLL48CK.
//
// Additional constraints:
//    ASSERT_FAULT((data->pllq >= 4) && (data->pllq <= 15));
//    ASSERT_FAULT((data->pllp >= 2) && (data->pllp <= 8));
//    ASSERT_FAULT(!(data->pllp & 1));
//    ASSERT_FAULT((data->plln >= 192) && (data->plln <= 432));
//    ASSERT_FAULT((data->pllm >= 2) && (data->pllm <= 63));
//
// f_VCO = (INPUT) X (PLL_N / PLL_M)
#define BOARD_PLL_N 336
#define BOARD_PLL_M 8
// SYSCLK = f_PLL = f_VCO / PLL_P;   PLL_P = {2, 4, 6, 8}
#define BOARD_PLL_P 4
// PLL48CK = f_USBETC = f_VCO / PLL_Q;   2 <= PLL_Q <= 15
#define BOARD_PLL_Q 7   // should be 2?

/* Pin number for the built-in button (USER button on STM32F401DISCOVERY) */
#define BOARD_BUTTON_PIN        PA0

/* Pin number for the built-in LED (blue LED on STM32F401DISCOVERY) */
#define BOARD_LED_PIN           PD15

/* Number of USARTs/UARTs whose pins are broken out to headers. */
#define BOARD_NR_USARTS         3

/* USART pin numbers. */
#define BOARD_USART1_TX_PIN     PA9
#define BOARD_USART1_RX_PIN     PA10
#define BOARD_USART2_TX_PIN     PA2
#define BOARD_USART2_RX_PIN     PA3
#define BOARD_USART3_TX_PIN     PB10
#define BOARD_USART3_RX_PIN     PB11

/* Number of SPI ports broken out to headers. */
#define BOARD_NR_SPI            2

/* SPI pin numbers. */
#define BOARD_SPI1_NSS_PIN      PA4
#define BOARD_SPI1_MOSI_PIN     PA7
#define BOARD_SPI1_MISO_PIN     PA6
#define BOARD_SPI1_SCK_PIN      PA5

#define BOARD_SPI2_NSS_PIN      28
#define BOARD_SPI2_MOSI_PIN     31
#define BOARD_SPI2_MISO_PIN     30
#define BOARD_SPI2_SCK_PIN      29

/* Total number of GPIO pins that are broken out to headers and
 * intended for use. This includes pins like the LED, button, and
 * debug port (JTAG/SWD) pins. */
#define BOARD_NR_GPIO_PINS      80

/* Number of pins capable of PWM output. */
#define BOARD_NR_PWM_PINS       5

/* Number of pins capable of ADC conversion. */
#define BOARD_NR_ADC_PINS       1

/* Number of pins already connected to external hardware.  For Maple,
 * these are just BOARD_LED_PIN, BOARD_BUTTON_PIN, and the debug port
 * pins (see below). */
#define BOARD_NR_USED_PINS       7

/* Debug port pins. */
#define BOARD_JTMS_SWDIO_PIN    39
#define BOARD_JTCK_SWCLK_PIN    40
#define BOARD_JTDI_PIN          41
#define BOARD_JTDO_PIN          42
#define BOARD_NJTRST_PIN        43

/* USB configuration.  BOARD_USB_DISC_DEV is the GPIO port containing
 * the USB_DISC pin, and BOARD_USB_DISC_BIT is that pin's bit. */
#define BOARD_USB_DISC_DEV      GPIOC
#define BOARD_USB_DISC_BIT      12

/* Pin aliases: these give the GPIO port/bit for each pin as an
 * enum. These are optional, but recommended. They make it easier to
 * write code using low-level GPIO functionality. */
enum {
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7, PA8, PA9, PA10, PA11, PA12, PA13, PA14, PA15,
    PB0, PB1, PB2, PB3, PB4, PB5, PB6, PB7, PB8, PB9, PB10, PB11, PB12, PB13, PB14, PB15,
    PC0, PC1, PC2, PC3, PC4, PC5, PC6, PC7, PC8, PC9, PC10, PC11, PC12, PC13, PC14, PC15,
    PD0, PD1, PD2, PD3, PD4, PD5, PD6, PD7, PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15,
    PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7, PE8, PE9, PE10, PE11, PE12, PE13, PE14, PE15,
};

#endif
