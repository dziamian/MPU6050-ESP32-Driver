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
#include "mpu6050_converter.h"

/** The most significant byte multiplier value for temperature convertion to get human-readable result */
#define MPU6050_TEMP_CONVERTER_MSB_MULTIPLIER   256
/** Divider value for temperature convertion to get human-readable result */
#define MPU6050_TEMP_CONVERTER_VALUE_DIVIDER    340.0
/** Base temperature value that must be added to get human-readable result */
#define MPU6050_TEMP_CONVERTER_BASE             36.53

/** The most significant byte multiplier value for gyroscope measurement convertion to get human-readable result */
#define MPU6050_GYRO_CONVERTER_MSB_MULTIPLIER   256
/** The most significant byte multiplier value for accelerometer measurement convertion to get human-readable result */
#define MPU6050_ACCEL_CONVERTER_MSB_MULTIPLIER  256

/** LSB sensitivity of gyroscope for full scale range of 250 */
#define MPU6050_GYRO_CONFIG_FS_SENS_250         131.0
/** LSB sensitivity of gyroscope for full scale range of 500 */
#define MPU6050_GYRO_CONFIG_FS_SENS_500         65.5
/** LSB sensitivity of gyroscope for full scale range of 1000 */
#define MPU6050_GYRO_CONFIG_FS_SENS_1000        32.8
/** LSB sensitivity of gyroscope for full scale range of 2000 */
#define MPU6050_GYRO_CONFIG_FS_SENS_2000        16.4

/** LSB sensitivity of accelerometer for full scale range of 2G */
#define MPU6050_ACCEL_CONFIG_AFS_SENS_2G        16384.0
/** LSB sensitivity of accelerometer for full scale range of 4G */
#define MPU6050_ACCEL_CONFIG_AFS_SENS_4G        8192.0
/** LSB sensitivity of accelerometer for full scale range of 8G */
#define MPU6050_ACCEL_CONFIG_AFS_SENS_8G        4096.0
/** LSB sensitivity of accelerometer for full scale range of 16G */
#define MPU6050_ACCEL_CONFIG_AFS_SENS_16G       2048.0

/** Look-up table for sensitivities and full scale ranges of gyroscope */
static const MPU6050_rotate_t gyroscopeSensitivities[MPU6050_GYRO_COUNT] =
{
    [MPU6050_GYRO_250] MPU6050_GYRO_CONFIG_FS_SENS_250,
    [MPU6050_GYRO_500] MPU6050_GYRO_CONFIG_FS_SENS_500,
    [MPU6050_GYRO_1000] MPU6050_GYRO_CONFIG_FS_SENS_1000,
    [MPU6050_GYRO_2000] MPU6050_GYRO_CONFIG_FS_SENS_2000
};
/** Look-up table for sensititvities and full scale ranges of accelerometer */
static const MPU6050_acceleration_t accelerometerSensitivities[MPU6050_ACCEL_COUNT] =
{
    [MPU6050_ACCEL_2G] MPU6050_ACCEL_CONFIG_AFS_SENS_2G,
    [MPU6050_ACCEL_4G] MPU6050_ACCEL_CONFIG_AFS_SENS_4G,
    [MPU6050_ACCEL_8G] MPU6050_ACCEL_CONFIG_AFS_SENS_8G,
    [MPU6050_ACCEL_16G] MPU6050_ACCEL_CONFIG_AFS_SENS_16G
};

MPU6050_temperature_t mpu6050_convert_temperature_bytes(const uint8_t msb, const uint8_t lsb)
{
    return (MPU6050_temperature_t)
                ((int16_t) (lsb + (msb * MPU6050_TEMP_CONVERTER_MSB_MULTIPLIER)))
                    / MPU6050_TEMP_CONVERTER_VALUE_DIVIDER + MPU6050_TEMP_CONVERTER_BASE;
}

MPU6050_rotate_t mpu6050_convert_gyroscope_bytes(const uint8_t msb, const uint8_t lsb, const MPU6050_gyro_range_t gyroRange)
{
    return (MPU6050_rotate_t)
                ((int16_t) (lsb + (msb * MPU6050_GYRO_CONVERTER_MSB_MULTIPLIER)))
                    / gyroscopeSensitivities[gyroRange];
}

MPU6050_acceleration_t mpu6050_convert_accelerometer_bytes(const uint8_t msb, const uint8_t lsb, const MPU6050_accel_range_t accelRange)
{
    return (MPU6050_acceleration_t)
                ((int16_t) -(lsb + (msb * MPU6050_ACCEL_CONVERTER_MSB_MULTIPLIER)))
                    / accelerometerSensitivities[accelRange];
}