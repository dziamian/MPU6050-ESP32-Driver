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
 * @file mpu6050_types_req.h
 * @author Damian Ślusarczyk
 * @brief Contains all input types required to communicate with MPU6050 driver.
 * 
 */
#ifndef MPU6050_TYPES_REQ_H
#define MPU6050_TYPES_REQ_H

typedef enum MPU6050_buffer_size_t      MPU6050_buffer_size_t;
typedef enum MPU6050_gyro_range_t       MPU6050_gyro_range_t;
typedef enum MPU6050_accel_range_t      MPU6050_accel_range_t;

/**
 * @brief Specifies the internal buffer size for the MPU6050 characteristics instance.
 * 
 */
enum MPU6050_buffer_size_t
{
    MPU6050_BUFF_MINIMAL = 6,   /**< Minimal size of the buffer sufficient to perform all basic operations like configuring and reading values from sensors */
};

/**
 * @brief Specifies the full scale range of the gyroscope outputs.
 * 
 */
enum MPU6050_gyro_range_t
{
    MPU6050_GYRO_250 = 0,   /**< Full scale range of gyroscope is +- 250°/s */
    MPU6050_GYRO_500,       /**< Full scale range of gyroscope is +- 500°/s */
    MPU6050_GYRO_1000,      /**< Full scale range of gyroscope is +- 1000°/s */
    MPU6050_GYRO_2000,      /**< Full scale range of gyroscope is +- 2000°/s */
    MPU6050_GYRO_COUNT      /**< Number of full scale ranges of gyroscope to choose */
};

/**
 * @brief Specifies the full scale range of the accelerometer outputs.
 * 
 */
enum MPU6050_accel_range_t
{
    MPU6050_ACCEL_2G = 0,   /**< Full scale range of accelerometer is +- 2g */
    MPU6050_ACCEL_4G,       /**< Full scale range of accelerometer is +- 4g */
    MPU6050_ACCEL_8G,       /**< Full scale range of accelerometer is +- 8g */
    MPU6050_ACCEL_16G,      /**< Full scale range of accelerometer is +- 16g */
    MPU6050_ACCEL_COUNT     /**< Number of full scale ranges of accelerometer to choose */
};

#endif /* MPU6050_TYPES_REQ_H */
