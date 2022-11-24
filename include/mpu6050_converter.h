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
 * @file mpu6050_converter.h
 * @author Damian Ślusarczyk
 * @brief Contains all convertion methods used for proper communication between the user and MPU6050.
 * 
 */
#ifndef MPU6050_CONVERTER_H
#define MPU6050_CONVERTER_H

#include "mpu6050_low.h"
#include "mpu6050_types_res.h"

/**
 * @brief Converts temperature bytes received from memory of MPU6050 into human-readable result.
 * 
 * @param msb The most significant byte of temperature
 * @param lsb The least significant byte of temperature
 * @return MPU6050_temperature_t Human-readable temperature
 */
MPU6050_temperature_t mpu6050_convert_temperature_bytes(const uint8_t msb, const uint8_t lsb);

/**
 * @brief Converts gyroscope bytes received from memory of MPU6050 for specified range into human-readable result.
 * 
 * @param msb The most significant byte of gyroscope measurement value
 * @param lsb The least significant byte of gyroscope measurement value
 * @param gyroRange Full scale range of gyroscope measurement set on the device
 * @return MPU6050_rotate_t Human-readable rotation value
 */
MPU6050_rotate_t mpu6050_convert_gyroscope_bytes(const uint8_t msb, const uint8_t lsb, const MPU6050_gyro_range_t gyroRange);

/**
 * @brief Converts accelerometer bytes received from memory of MPU6050 for specified range into human-readable result.
 * 
 * @param msb The most significant byte of accelerometer
 * @param lsb The least significant byte of accelerometer
 * @param accelRange Full scale range of accelerometer measurement set on the device
 * @return MPU6050_acceleration_t Human-readable acceleration value
 */
MPU6050_acceleration_t mpu6050_convert_accelerometer_bytes(const uint8_t msb, const uint8_t lsb, const MPU6050_accel_range_t accelRange);

#endif /* MPU6050_CONVERTER_H */
