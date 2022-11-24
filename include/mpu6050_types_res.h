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
 * @file mpu6050_types_res.h
 * @author Damian Ślusarczyk
 * @brief Contains all output types required to communicate with MPU6050 driver.
 * 
 */
#ifndef MPU6050_TYPES_RES_H
#define MPU6050_TYPES_RES_H

typedef struct MPU6050_gyroscope_t      MPU6050_gyroscope_t;
typedef struct MPU6050_accelerometer_t  MPU6050_accelerometer_t;

/** Rotation measured by the device */
typedef double                          MPU6050_rotate_t;
/** Acceleration measured by the device */
typedef double                          MPU6050_acceleration_t;
/** Temperature measured by the device */
typedef double                          MPU6050_temperature_t;

/**
 * @brief Contains measured rotations for all axes by the MPU6050 device.
 * 
 */
struct MPU6050_gyroscope_t
{
    MPU6050_rotate_t                    x;  /**< Rotation measured by the gyroscope for the X axis */
    MPU6050_rotate_t                    y;  /**< Rotation measured by the gyroscope for the Y axis */
    MPU6050_rotate_t                    z;  /**< Rotation measured by the gyroscope for the Z axis */
};

/**
 * @brief Contains measured accelerations for all axes by the MPU6050 device.
 * 
 */
struct MPU6050_accelerometer_t
{
    MPU6050_acceleration_t              x;  /**< Acceleration measured by the accelerometer for the X axis */
    MPU6050_acceleration_t              y;  /**< Acceleration measured by the accelerometer for the Y axis */
    MPU6050_acceleration_t              z;  /**< Acceleration measured by the accelerometer for the Z axis */
};

#endif /* MPU6050_TYPES_RES_H */
