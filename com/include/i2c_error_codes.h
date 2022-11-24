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
 * @file i2c_error_codes.h
 * @author Damian Ślusarczyk
 * @brief Contains error codes as an enumeration.
 * 
 * They describe the status of performed operations on the I2C bus.
 */
#ifndef I2C_ERROR_CODES_H
#define I2C_ERROR_CODES_H

typedef enum i2c_error_t    i2c_error_t;

/**
 * @brief Describes the status of performed operation on the I2C bus.
 * 
 */
enum i2c_error_t
{
    I2C_OK = 0,     /**< No error occurred - everything went fine */
    I2C_INV_ARG,    /**< An invalid argument has been passed into the function */
    I2C_INV_CONF,   /**< An invalid I2C configuration has been specified */
    I2C_CONF_FAIL,  /**< I2C bus configuration has failed */
    I2C_OP_FAIL     /**< I2C read/write operation has failed */
};

#endif /* I2C_ERROR_CODES_H */
