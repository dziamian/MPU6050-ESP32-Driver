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
 * @file mpu6050_registers_values.h
 * @author Damian Ślusarczyk
 * @brief Contains MPU6050 information about register values as a set of macros.
 * 
 * They are mainly used for appropriate reading/writing values from/into memory of MPU6050.
 */
#ifndef MPU6050_REGISTERS_VALUES_H
#define MPU6050_REGISTERS_VALUES_H

/** Index of the MPU6050 internal buffer for the most significant byte of temperature */
#define MPU6050_TEMP_MSB                0
/** Index of the MPU6050 internal buffer for the least significant byte of temperature */
#define MPU6050_TEMP_LSB                1
/** Number of bytes of measured temperature */
#define MPU6050_TEMP_BYTES              2

/** Index of the MPU6050 internal buffer for the most significant byte of rotation in X axis */
#define MPU6050_GYRO_X_MSB              0
/** Index of the MPU6050 internal buffer for the least significant byte of rotation in X axis */
#define MPU6050_GYRO_X_LSB              1
/** Index of the MPU6050 internal buffer for the most significant byte of rotation in Y axis */
#define MPU6050_GYRO_Y_MSB              2
/** Index of the MPU6050 internal buffer for the least significant byte of rotation in Y axis */
#define MPU6050_GYRO_Y_LSB              3
/** Index of the MPU6050 internal buffer for the most significant byte of rotation in Z axis */
#define MPU6050_GYRO_Z_MSB              4
/** Index of the MPU6050 internal buffer for the least significant byte of rotation in Z axis */
#define MPU6050_GYRO_Z_LSB              5
/** Number of bytes of measured gyroscope values */
#define MPU6050_GYRO_BYTES              6

/** Index of the MPU6050 internal buffer for the most significant byte of acceleration in X axis */
#define MPU6050_ACCEL_X_MSB             0
/** Index of the MPU6050 internal buffer for the least significant byte of acceleration in X axis */
#define MPU6050_ACCEL_X_LSB             1
/** Index of the MPU6050 internal buffer for the most significant byte of acceleration in Y axis */
#define MPU6050_ACCEL_Y_MSB             2
/** Index of the MPU6050 internal buffer for the least significant byte of acceleration in Y axis */
#define MPU6050_ACCEL_Y_LSB             3
/** Index of the MPU6050 internal buffer for the most significant byte of acceleration in Z axis */
#define MPU6050_ACCEL_Z_MSB             4
/** Index of the MPU6050 internal buffer for the least significant byte of acceleration in Z axis */
#define MPU6050_ACCEL_Z_LSB             5
/** Number of bytes of measured accelerometer values */
#define MPU6050_ACCEL_BYTES             6

/** Value for shifting gyroscope configuration bits to get or set the full scale range */
#define MPU6050_GYRO_CONFIG_SHIFT       3
/** Value for shifting accelerometer configuration bits to get or set the full scale range */
#define MPU6050_ACCEL_CONFIG_SHIFT      3

/** Flag value for PWR_MGMT_1 register to reset device */
#define MPU6050_PWR_MGMT_1_RESET        0x80
/** Flag value for PWR_MGMT_1 register to enable low power sleep mode */
#define MPU6050_PWR_MGMT_1_SLEEP        0x40
/** Flag value for PWR_MGMT_1 register to enable the Cycle Mode */
#define MPU6050_PWR_MGMT_1_CYCLE        0x20
/** Flag value for PWR_MGMT_1 register to disable temperature sensor */
#define MPU6050_PWR_MGMT_1_TEMP_DIS     0x08

#endif /* MPU6050_REGISTERS_VALUES_H */
