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
 * @file   wirish/boards/st_stm32f4discovery/include/board/board.h
 * @author Bryan Newbold <bnewbold@robocracy.org>
 * @brief  st_stm32f4discovery board file (based on Maple Native)
 *
 * See wirish/boards/maple/include/board/board.h for more information
 * on these definitions.
 */

#ifndef _BOARD_ST_STM32F4DISCOVERY_H_
#define _BOARD_ST_STM32F4DISCOVERY_H_

// OSC as MCO from ST-LINK microcontroller at 8 MHz
#define CYCLES_PER_MICROSECOND  168
#define SYSTICK_RELOAD_VAL      167999

#define BOARD_LED_PIN           PA9
#define BOARD_BUTTON_PIN        PA0

// TODO: Check this
#define BOARD_NR_USARTS         5
#define BOARD_USART1_TX_PIN     PA9
#define BOARD_USART1_RX_PIN     PA10
#define BOARD_USART2_TX_PIN     PD5
#define BOARD_USART2_RX_PIN     PD6
#define BOARD_USART3_TX_PIN     PD8
#define BOARD_USART3_RX_PIN     PD9
#define BOARD_UART4_TX_PIN      PC10
#define BOARD_UART4_RX_PIN      PC11
#define BOARD_UART5_TX_PIN      PC12
#define BOARD_UART5_RX_PIN      PD2

#define BOARD_NR_SPI            5
#define BOARD_SPI1_NSS_PIN      PA4
#define BOARD_SPI1_SCK_PIN      PA5
#define BOARD_SPI1_MISO_PIN     PA6
#define BOARD_SPI1_MOSI_PIN     PA7
#define BOARD_SPI2_NSS_PIN      PB12
#define BOARD_SPI2_SCK_PIN      PB13
#define BOARD_SPI2_MISO_PIN     PB14
#define BOARD_SPI2_MOSI_PIN     PB15
#define BOARD_SPI3_NSS_PIN      PA15
#define BOARD_SPI3_MOSI_PIN     PB3
#define BOARD_SPI3_MISO_PIN     PB4
#define BOARD_SPI3_SCK_PIN      PB5

#define BOARD_NR_GPIO_PINS      (5*16)
#define BOARD_NR_PWM_PINS       0
#define BOARD_NR_ADC_PINS       0
#define BOARD_NR_USED_PINS      (5*16)
#define BOARD_JTMS_SWDIO_PIN    PA13
#define BOARD_JTCK_SWCLK_PIN    PA14
#define BOARD_JTDI_PIN          PA15
#define BOARD_JTDO_PIN          PB3
#define BOARD_NJTRST_PIN        PB4

// XXX: is BOARD_USB_DISC PowerOn?
#define BOARD_USB_DISC_DEV      GPIOC
#define BOARD_USB_DISC_BIT      0

enum {
    PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PA8,PA9,PA10,PA11,PA12,PA13,PA14,PA15,
    PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,PB8,PB9,PB10,PB11,PB12,PB13,PB14,PB15,
    PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,PC8,PC9,PC10,PC11,PC12,PC13,PC14,PC15,
    PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,PD8,PD9,PD10,PD11,PD12,PD13,PD14,PD15,
    PE0,PE1,PE2,PE3,PE4,PE5,PE6,PE7,PE8,PE9,PE10,PE11,PE12,PE13,PE14,PE15,
};

#endif
