/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010 Perry Hung.
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
 * @file wirish/include/wirish/HardwareSPI.h
 * @brief High-level SPI interface
 *
 * This is a "bare essentials" polling driver for now.
 */

/* TODO [0.1.0] Remove deprecated methods. */

#include <libmaple/libmaple_types.h>
#include <libmaple/spi.h>

#include <wirish/boards.h>

#ifndef _WIRISH_HARDWARESPI_H_
#define _WIRISH_HARDWARESPI_H_

/**
 * @brief Defines the possible SPI communication speeds.
 */
// FIXME: this double-definition, board-specific enum doesn't seem like best
// practice for a header file.
typedef enum SPIFrequency {
    SPI_PCLK_DIV_2   = 0,
    SPI_PCLK_DIV_4   = 1,
    SPI_PCLK_DIV_8   = 2,
    SPI_PCLK_DIV_16  = 3,
    SPI_PCLK_DIV_32  = 4,
    SPI_PCLK_DIV_64  = 5,
    SPI_PCLK_DIV_128 = 6,
    SPI_PCLK_DIV_256 = 7,
#if CYCLES_PER_MICROSECOND == 72
    SPI_18MHZ       = SPI_PCLK_DIV_2,   /**< 18 MHz */
    SPI_9MHZ        = SPI_PCLK_DIV_4,   /**< 9 MHz */
    SPI_4_5MHZ      = SPI_PCLK_DIV_8,   /**< 4.5 MHz */
    SPI_2_25MHZ     = SPI_PCLK_DIV_16,  /**< 2.25 MHz */
    SPI_1_125MHZ    = SPI_PCLK_DIV_32,  /**< 1.125 MHz */
    SPI_562_500KHZ  = SPI_PCLK_DIV_64,  /**< 562.500 KHz */
    SPI_281_250KHZ  = SPI_PCLK_DIV_128, /**< 281.250 KHz */
    SPI_140_625KHZ  = SPI_PCLK_DIV_256, /**< 140.625 KHz */
#elif CYCLES_PER_MICROSECOND == 84
// FIXME: review these 84 MHz values
    SPI_21MHZ       = SPI_PCLK_DIV_2,   /**< 21 MHz */
    SPI_10_5MHZ     = SPI_PCLK_DIV_4,   /**< 10.5 MHz */
    SPI_5_25MHZ     = SPI_PCLK_DIV_8,   /**< 5.25 MHz */
    SPI_2_625MHZ    = SPI_PCLK_DIV_16,  /**< 2.625 MHz */
    SPI_1_3125MHZ   = SPI_PCLK_DIV_32,  /**< 1.3125 MHz */
    SPI_656_250KHZ  = SPI_PCLK_DIV_64,  /**< 656.25 KHz */
    SPI_328_125KHZ  = SPI_PCLK_DIV_128, /**< 328.125 KHz */
    SPI_164_0625KHZ = SPI_PCLK_DIV_256, /**< 164.0625 KHz */
#endif  // If adding new clock entries, also update HardwareSPI.cpp

} SPIFrequency;

#define MAX_SPI_FREQS 8

/**
 * @brief Wirish SPI interface.
 *
 * This implementation uses software slave management, so the caller
 * is responsible for controlling the slave select line.
 */
class HardwareSPI {
public:
    /**
     * @param spiPortNumber Number of the SPI port to manage.
     */
    HardwareSPI(uint32 spiPortNumber);

    /*
     * Set up/tear down
     */

    /**
     * @brief Turn on a SPI port and set its GPIO pin modes for use as master.
     *
     * SPI port is enabled in full duplex mode, with software slave management.
     *
     * @param frequency Communication frequency
     * @param bitOrder Either LSBFIRST (little-endian) or MSBFIRST (big-endian)
     * @param mode SPI mode to use, one of SPI_MODE_0, SPI_MODE_1,
     *             SPI_MODE_2, and SPI_MODE_3.
     */
    void begin(SPIFrequency frequency, uint32 bitOrder, uint32 mode);

    /**
     * @brief Equivalent to begin(SPI_1_125MHZ, MSBFIRST, 0).
     */
    void begin(void);

    /**
     * @brief Turn on a SPI port and set its GPIO pin modes for use as a slave.
     *
     * SPI port is enabled in full duplex mode, with software slave management.
     *
     * @param bitOrder Either LSBFIRST (little-endian) or MSBFIRST(big-endian)
     * @param mode SPI mode to use
     */
    void beginSlave(uint32 bitOrder, uint32 mode);

    /**
     * @brief Equivalent to beginSlave(MSBFIRST, 0).
     */
    void beginSlave(void);

    /**
     * @brief Disables the SPI port, but leaves its GPIO pin modes unchanged.
     */
    void end(void);

    /*
     * I/O
     */

    /**
     * @brief Return the next unread byte.
     *
     * If there is no unread byte waiting, this function will block
     * until one is received.
     */
    uint8 read(void);

    /**
     * @brief Read length bytes, storing them into buffer.
     * @param buffer Buffer to store received bytes into.
     * @param length Number of bytes to store in buffer.  This
     *               function will block until the desired number of
     *               bytes have been read.
     */
    void read(uint8 *buffer, uint32 length);

    /**
     * @brief Transmit a byte.
     * @param data Byte to transmit.
     */
    void write(uint8 data);

    /**
     * @brief Transmit multiple bytes.
     * @param buffer Bytes to transmit.
     * @param length Number of bytes in buffer to transmit.
     */
    void write(const uint8 *buffer, uint32 length);

    /**
     * @brief Transmit a byte, then return the next unread byte.
     *
     * This function transmits before receiving.
     *
     * @param data Byte to transmit.
     * @return Next unread byte.
     */
    uint8 transfer(uint8 data);

    /*
     * Pin accessors
     */

    /**
     * @brief Return the number of the MISO (master in, slave out) pin
     */
    uint8 misoPin(void);

    /**
     * @brief Return the number of the MOSI (master out, slave in) pin
     */
    uint8 mosiPin(void);

    /**
     * @brief Return the number of the SCK (serial clock) pin
     */
    uint8 sckPin(void);

    /**
     * @brief Return the number of the NSS (slave select) pin
     */
    uint8 nssPin(void);

    /* Escape hatch */

    /**
     * @brief Get a pointer to the underlying libmaple spi_dev for
     *        this HardwareSPI instance.
     */
    spi_dev* c_dev(void) { return this->spi_d; }

    /* -- The following methods are deprecated --------------------------- */

    /**
     * @brief Deprecated.
     *
     * Use HardwareSPI::transfer() instead.
     *
     * @see HardwareSPI::transfer()
     */
    uint8 send(uint8 data);

    /**
     * @brief Deprecated.
     *
     * Use HardwareSPI::write() in combination with
     * HardwareSPI::read() (or HardwareSPI::transfer()) instead.
     *
     * @see HardwareSPI::write()
     * @see HardwareSPI::read()
     * @see HardwareSPI::transfer()
     */
    uint8 send(uint8 *data, uint32 length);

    /**
     * @brief Deprecated.
     *
     * Use HardwareSPI::read() instead.
     *
     * @see HardwareSPI::read()
     */
    uint8 recv(void);
private:
    spi_dev *spi_d;
};

#endif
