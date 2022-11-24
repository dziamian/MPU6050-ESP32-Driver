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
 * @file mpu6050.h
 * @author Damian Ślusarczyk
 * @brief Contains high-level functions to communicate with MPU6050 using I2C protocol.
 * 
 */
#ifndef MPU6050_H
#define MPU6050_H

#include <stdbool.h>

#include "mpu6050_low.h"
#include "mpu6050_types_res.h"
#include "mpu6050_error_codes.h"
#include "i2c.h"

/**
 * @brief Initializes MPU6050 device instance.
 * 
 * Prepares I2C communication for given port and configuration and wakes the device from the sleep mode.
 * This method need to be called before using any other high-level driver functions.
 * 
 * @param device Pointer to MPU6050 characteristics instance to initialize
 * @param buffer Pointer to data buffer of the device
 * @param bufferSize Size of the data buffer
 * @param port Port where I2C driver will be installed
 * @param i2cWaitMs Time allowed to perform the single read/write operation
 * @param config Configuration of the I2C driver
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__InitDevice(MPU6050_t * const device, uint8_t * const buffer, const MPU6050_buffer_size_t bufferSize, const i2c_port_t port, const uint16_t i2cWaitMs, const i2c_config_t * const config);

/**
 * @brief Configures full scale range of gyroscope for the given device.
 * 
 * Sets the specified range in appropriate MPU6050 register. 
 * It will be taken into account before next measurement.
 * 
 * @param device Pointer to MPU6050 characteristics instance
 * @param gyroRange Full scale range of gyroscope to set
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__ConfigureGyroscope(MPU6050_t * const device, const MPU6050_gyro_range_t gyroRange);

/**
 * @brief Configures full scale range of accelerometer for the given device.
 * 
 * Sets the specified range in appropriate MPU6050 register. 
 * It will be taken into account before next measurement.
 * 
 * @param device Pointer to MPU6050 characteristics instance
 * @param accelRange Full scale range of accelerometer to set
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__ConfigureAccelerometer(MPU6050_t * const device, const MPU6050_accel_range_t accelRange);

/**
 * @brief Reads last measured temperature by the given device (in Celsius).
 * 
 * Acquires the temperature from appriopriate MPU6050 register and converts it into human-readable value.
 * 
 * @param device Pointer to MPU6050 characteristics instance
 * @param temperatureOut Pointer to variable where received temperature will be saved eventually
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__ReadTemperature(const MPU6050_t * const device, MPU6050_temperature_t * const temperatureOut);

/**
 * @brief Reads last measured gyroscope values for all axes by the given device (in °/s).
 * 
 * Acquires the rotations for axes X, Y and Z from appropriate MPU6050 registers and converts them into human-readable values. 
 * 
 * @param device Pointer to MPU6050 characteristics instance
 * @param gyroscopeOut Pointer to variable where received gyroscope values will be saved eventually
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__ReadGyroscope(const MPU6050_t * const device, MPU6050_gyroscope_t * const gyroscopeOut);

/**
 * @brief Reads last measured accelerometer values for all axes by the given device (as gravitational acceleration).
 * 
 * Acquires the accelerations for axes X, Y and Z from appropriate MPU6050 registers and converts them into human-readable values. 
 * 
 * @param device Pointer to MPU6050 characteristics instance
 * @param accelerometerOut Pointer to variable where received accelerometer values will be saved eventually
 * @return mpu6050_error_t Status code of the operation
 */
mpu6050_error_t mpu6050__ReadAccelerometer(const MPU6050_t * const device, MPU6050_accelerometer_t * const accelerometerOut);

#endif /* MPU6050_H */
