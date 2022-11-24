/*
 * MIT License
 *
 * Copyright (c) 2022 Damian Ślusarczyk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
/**
 * @file i2c.h
 * @author Damian Ślusarczyk
 * @brief Contains functions required to communicate with device using I2C protocol.
 * 
 */
#ifndef I2C_H
#define I2C_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "driver/i2c.h"

#include "i2c_error_codes.h"

/**
 * @brief Initializes default configuration for I2C bus in master mode.
 * 
 * @param sda GPIO for I2C data line (SDA) 
 * @param scl GPIO for I2C clock line (SCL)
 * @param clkSpeed I2C clock speed frequency in Hz
 * @param config Pointer to I2C configuration instance to initialize
 * @return i2c_error_t Status code of the operation
 */
i2c_error_t i2c__MasterInitConfigDefault(const int sda, const int scl, const uint32_t clkSpeed, i2c_config_t * const config);

/**
 * @brief Initializes I2C bus in master mode.
 * 
 * Prepares I2C bus by installing the driver using specified configuration. 
 * 
 * @param port Selected I2C port number for driver installation
 * @param config Pointer to configuration instance for driver installation
 * @return i2c_error_t Status code of the operation
 */
i2c_error_t i2c__MasterInit(const i2c_port_t port, const i2c_config_t * const config);

/**
 * @brief Reads the data from specified I2C bus.
 * 
 * Reads specified number of bytes from the selected slave and stores them in the specified buffer.
 * 
 * @param port I2C port where driver has been installed
 * @param data Buffer where read bytes will be stored
 * @param dataSize Number of bytes to read
 * @param slaveAddress Address of the selected I2C slave
 * @param waitMs Time allowed to perform the read operation
 * @return i2c_error_t Status code of the operation
 */
i2c_error_t i2c__MasterRead(const i2c_port_t port, uint8_t * const data, const size_t dataSize, const uint8_t slaveAddress, const uint16_t waitMs);

/**
 * @brief Writes the data to specified I2C bus.
 * 
 * Writes specified number of bytes to the selected slave from the specified buffer.
 * 
 * @param port I2C port where driver has been installed
 * @param data Buffer from where bytes will be written
 * @param dataSize Number of bytes to write
 * @param slaveAddress Address of the selected I2C slave
 * @param waitMs Time allowed to perform the write operation
 * @return i2c_error_t Status code of the operation
 */
i2c_error_t i2c__MasterWrite(const i2c_port_t port, const uint8_t * const data, const size_t dataSize, const uint8_t slaveAddress, const uint16_t waitMs);

#endif /* I2C_H */
