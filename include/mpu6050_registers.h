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
 * @file mpu6050_registers.h
 * @author Damian Ślusarczyk
 * @brief Contains MPU6050 information about register addresses as a set of macros.
 * 
 * They are mainly used for appropriate locating specific values in memory of MPU6050.
 */
#ifndef MPU6050_REGISTERS_H
#define MPU6050_REGISTERS_H

#define MPU6050_SELF_TEST_X         0x0D    /**< Memory address for SELF_TEST_X register */
#define MPU6050_SELF_TEST_Y         0x0E    /**< Memory address for SELF_TEST_Y register */
#define MPU6050_SELF_TEST_Z         0x0F    /**< Memory address for SELF_TEST_Z register */
#define MPU6050_SELF_TEST_A         0x10    /**< Memory address for SELF_TEST_A register */
#define MPU6050_SMPLRT_DIV          0x19    /**< Memory address for SMPLRT_DIV register */
#define MPU6050_CONFIG              0x1A    /**< Memory address for CONFIG register */
#define MPU6050_GYRO_CONFIG         0x1B    /**< Memory address for GYRO_CONFIG register */
#define MPU6050_ACCEL_CONFIG        0x1C    /**< Memory address for ACCEL_CONFIG register */
#define MPU6050_FIFO_EN             0x23    /**< Memory address for FIFO_EN register */
#define MPU6050_I2C_MST_CTRL        0x24    /**< Memory address for I2C_MST_CTRL register */
#define MPU6050_I2C_SLV0_ADDR       0x25    /**< Memory address for I2C_SLV0_ADDR register */
#define MPU6050_I2C_SLV0_REG        0x26    /**< Memory address for I2C_SLV0_REG register */
#define MPU6050_I2C_SLV0_CTRL       0x27    /**< Memory address for I2C_SLV0_CTRL register */
#define MPU6050_I2C_SLV1_ADDR       0x28    /**< Memory address for I2C_SLV1_ADDR register */
#define MPU6050_I2C_SLV1_REG        0x29    /**< Memory address for I2C_SLV1_REG register */
#define MPU6050_I2C_SLV1_CTRL       0x2A    /**< Memory address for I2C_SLV1_CTRL register */
#define MPU6050_I2C_SLV2_ADDR       0x2B    /**< Memory address for I2C_SLV2_ADDR register */
#define MPU6050_I2C_SLV2_REG        0x2C    /**< Memory address for I2C_SLV2_REG register */
#define MPU6050_I2C_SLV2_CTRL       0x2D    /**< Memory address for I2C_SLV2_CTRL register */
#define MPU6050_I2C_SLV3_ADDR       0x2E    /**< Memory address for I2C_SLV3_ADDR register */
#define MPU6050_I2C_SLV3_REG        0x2F    /**< Memory address for I2C_SLV3_REG register */
#define MPU6050_I2C_SLV3_CTRL       0x30    /**< Memory address for I2C_SLV3_CTRL register */
#define MPU6050_I2C_SLV4_ADDR       0x31    /**< Memory address for I2C_SLV4_ADDR register */
#define MPU6050_I2C_SLV4_REG        0x32    /**< Memory address for I2C_SLV4_REG register */
#define MPU6050_I2C_SLV4_DO         0x33    /**< Memory address for I2C_SLV4_DO register */
#define MPU6050_I2C_SLV4_CTRL       0x34    /**< Memory address for I2C_SLV4_CTRL register */
#define MPU6050_I2C_SLV4_DI         0x35    /**< Memory address for I2C_SLV4_DI register */
#define MPU6050_I2C_MST_STATUS      0x36    /**< Memory address for I2C_MST_STATUS register */
#define MPU6050_INT_PIN_CFG         0x37    /**< Memory address for INT_PIN_CFG register */
#define MPU6050_INT_ENABLE          0x38    /**< Memory address for INT_ENABLE register */
#define MPU6050_INT_STATUS          0x3A    /**< Memory address for INT_STATUS register */
#define MPU6050_ACCEL_XOUT_H        0x3B    /**< Memory address for ACCEL_XOUT_H register */
#define MPU6050_ACCEL_XOUT_L        0x3C    /**< Memory address for ACCEL_XOUT_L register */
#define MPU6050_ACCEL_YOUT_H        0x3D    /**< Memory address for ACCEL_YOUT_H register */
#define MPU6050_ACCEL_YOUT_L        0x3E    /**< Memory address for ACCEL_YOUT_L register */
#define MPU6050_ACCEL_ZOUT_H        0x3F    /**< Memory address for ACCEL_ZOUT_H register */
#define MPU6050_ACCEL_ZOUT_L        0x40    /**< Memory address for ACCEL_ZOUT_L register */
#define MPU6050_TEMP_OUT_H          0x41    /**< Memory address for TEMP_OUT_H register */
#define MPU6050_TEMP_OUT_L          0x42    /**< Memory address for TEMP_OUT_L register */
#define MPU6050_GYRO_XOUT_H         0x43    /**< Memory address for GYRO_XOUT_H register */
#define MPU6050_GYRO_XOUT_L         0x44    /**< Memory address for GYRO_XOUT_L register */
#define MPU6050_GYRO_YOUT_H         0x45    /**< Memory address for GYRO_YOUT_H register */
#define MPU6050_GYRO_YOUT_L         0x46    /**< Memory address for GYRO_YOUT_L register */
#define MPU6050_GYRO_ZOUT_H         0x47    /**< Memory address for GYRO_ZOUT_H register */
#define MPU6050_GYRO_ZOUT_L         0x48    /**< Memory address for GYRO_ZOUT_L register */
#define MPU6050_EXT_SENS_DATA_00    0x49    /**< Memory address for EXT_SENS_DATA_00 register */
#define MPU6050_EXT_SENS_DATA_01    0x4A    /**< Memory address for EXT_SENS_DATA_01 register */
#define MPU6050_EXT_SENS_DATA_02    0x4B    /**< Memory address for EXT_SENS_DATA_02 register */
#define MPU6050_EXT_SENS_DATA_03    0x4C    /**< Memory address for EXT_SENS_DATA_03 register */
#define MPU6050_EXT_SENS_DATA_04    0x4D    /**< Memory address for EXT_SENS_DATA_04 register */
#define MPU6050_EXT_SENS_DATA_05    0x4E    /**< Memory address for EXT_SENS_DATA_05 register */
#define MPU6050_EXT_SENS_DATA_06    0x4F    /**< Memory address for EXT_SENS_DATA_06 register */
#define MPU6050_EXT_SENS_DATA_07    0x50    /**< Memory address for EXT_SENS_DATA_07 register */
#define MPU6050_EXT_SENS_DATA_08    0x51    /**< Memory address for EXT_SENS_DATA_08 register */
#define MPU6050_EXT_SENS_DATA_09    0x52    /**< Memory address for EXT_SENS_DATA_09 register */
#define MPU6050_EXT_SENS_DATA_10    0x53    /**< Memory address for EXT_SENS_DATA_10 register */
#define MPU6050_EXT_SENS_DATA_11    0x54    /**< Memory address for EXT_SENS_DATA_11 register */
#define MPU6050_EXT_SENS_DATA_12    0x55    /**< Memory address for EXT_SENS_DATA_12 register */
#define MPU6050_EXT_SENS_DATA_13    0x56    /**< Memory address for EXT_SENS_DATA_13 register */
#define MPU6050_EXT_SENS_DATA_14    0x57    /**< Memory address for EXT_SENS_DATA_14 register */
#define MPU6050_EXT_SENS_DATA_15    0x58    /**< Memory address for EXT_SENS_DATA_15 register */
#define MPU6050_EXT_SENS_DATA_16    0x59    /**< Memory address for EXT_SENS_DATA_16 register */
#define MPU6050_EXT_SENS_DATA_17    0x5A    /**< Memory address for EXT_SENS_DATA_17 register */
#define MPU6050_EXT_SENS_DATA_18    0x5B    /**< Memory address for EXT_SENS_DATA_18 register */
#define MPU6050_EXT_SENS_DATA_19    0x5C    /**< Memory address for EXT_SENS_DATA_19 register */
#define MPU6050_EXT_SENS_DATA_20    0x5D    /**< Memory address for EXT_SENS_DATA_20 register */
#define MPU6050_EXT_SENS_DATA_21    0x5E    /**< Memory address for EXT_SENS_DATA_21 register */
#define MPU6050_EXT_SENS_DATA_22    0x5F    /**< Memory address for EXT_SENS_DATA_22 register */
#define MPU6050_EXT_SENS_DATA_23    0x60    /**< Memory address for EXT_SENS_DATA_23 register */
#define MPU6050_I2C_SLV0_DO         0x63    /**< Memory address for I2C_SLV0_DO register */
#define MPU6050_I2C_SLV1_DO         0x64    /**< Memory address for I2C_SLV1_DO register */
#define MPU6050_I2C_SLV2_DO         0x65    /**< Memory address for I2C_SLV2_DO register */
#define MPU6050_I2C_SLV3_DO         0x66    /**< Memory address for I2C_SLV3_DO register */
#define MPU6050_I2C_MST_DELAY_CTRL  0x67    /**< Memory address for I2C_MST_DELAY_CTRL register */
#define MPU6050_SIGNAL_PATH_RESET   0x68    /**< Memory address for SIGNAL_PATH_RESET register */
#define MPU6050_USER_CTRL           0x6A    /**< Memory address for USER_CTRL register */
#define MPU6050_PWR_MGMT_1          0x6B    /**< Memory address for PWR_MGMT_1 register */
#define MPU6050_PWR_MGMT_2          0x6C    /**< Memory address for PWR_MGMT_2 register */
#define MPU6050_FIFO_COUNTH         0x72    /**< Memory address for FIFO_COUNTH register */
#define MPU6050_FIFO_COUNTL         0x73    /**< Memory address for FIFO_COUNTL register */
#define MPU6050_FIFO_R_W            0x74    /**< Memory address for FIFO_R_W register */
#define MPU6050_WHO_AM_I            0x75    /**< Memory address for WHO_AM_I register */

#endif /* MPU6050_REGISTERS_H */
