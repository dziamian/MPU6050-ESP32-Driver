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
 * @file mpu6050_low.h
 * @author Damian Ślusarczyk
 * @brief Contains low-level function to communicate with MPU6050 using I2C protocol.
 * 
 */
#ifndef MPU6050_LOW_H
#define MPU6050_LOW_H

#include "driver/i2c.h"

#include "mpu6050_types_req.h"

#define MPU6050_SLAVE_ADDRESS           0x68

typedef struct MPU6050_t                MPU6050_t;

/**
 * @brief Describes characteristics of single MPU6050.
 * 
 * @note Structure will be initialized using mpu6050__InitDevice() method.
 * 
 */
struct MPU6050_t
{
    uint8_t                             *buffer;    /**< Pointer to buffer for data to read and write */
    MPU6050_buffer_size_t               bufferSize; /**< Size of the data buffer */
    i2c_port_t                          port;       /**< Port of I2C bus to communicate with the device */
    uint16_t                            i2cWaitMs;  /**< Time allowed to perform the read/write operation */
    MPU6050_gyro_range_t                gyroRange;  /**< Full scale range of gyroscope measurement */
    MPU6050_accel_range_t               accelRange; /**< Full scale range of accelerometer measurement */
};

/**
 * @brief Writes command address and data to the buffer of the device.
 * 
 * @param device Pointer to specified MPU6050 characteristics instance
 * @param cmd Command address to be written
 * @param data Data bytes to be written
 * @param dataSize Number of data bytes to be written
 * @return size_t Number of written bytes
 */
size_t mpu6050_buffer_write(const MPU6050_t * const device, const uint8_t cmd, const uint8_t * const data, const size_t dataSize);

#endif /* MPU6050_LOW_H */
