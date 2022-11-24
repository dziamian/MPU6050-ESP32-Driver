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
#include "mpu6050.h"

#include "mpu6050_registers.h"
#include "mpu6050_registers_values.h"
#include "mpu6050_converter.h"

#define MPU6050_DATA_NULL       0   /**< Means that data buffer pointer is NULL */
#define MPU6050_DATA_1BYTE      1   /**< Means that data buffer size is one byte */

mpu6050_error_t mpu6050__InitDevice(MPU6050_t * const device, uint8_t * const buffer, const MPU6050_buffer_size_t bufferSize, const i2c_port_t port, const uint16_t i2cWaitMs, const i2c_config_t * const config)
{
    if (!device || !buffer || !bufferSize)
    {
        return MPU6050_INV_ARG;
    }

    if (I2C_OK != i2c__MasterInit(port, config))
    {
        return MPU6050_INV_CONF;
    }

    device->buffer = buffer;
    device->bufferSize = bufferSize;
    device->port = port;
    device->i2cWaitMs = i2cWaitMs;
    device->gyroRange = MPU6050_GYRO_250;
    device->accelRange = MPU6050_ACCEL_2G;

    // Disable sleep mode
    uint8_t data = !MPU6050_PWR_MGMT_1_SLEEP;
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_PWR_MGMT_1, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    return MPU6050_OK;
}

mpu6050_error_t mpu6050__ConfigureGyroscope(MPU6050_t * const device, const MPU6050_gyro_range_t gyroRange)
{
    if (!device)
    {
        return MPU6050_INV_ARG;
    }

    // Configure gyroscope
    uint8_t data = gyroRange << MPU6050_GYRO_CONFIG_SHIFT;
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_GYRO_CONFIG, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    device->gyroRange = gyroRange;

    return MPU6050_OK;
}

mpu6050_error_t mpu6050__ConfigureAccelerometer(MPU6050_t * const device, const MPU6050_accel_range_t accelRange)
{
    if (!device)
    {
        return MPU6050_INV_ARG;
    }

    // Configure accelerometer
    uint8_t data = accelRange << MPU6050_ACCEL_CONFIG_SHIFT;
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_ACCEL_CONFIG, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    device->accelRange = accelRange;

    return MPU6050_OK;
}

mpu6050_error_t mpu6050__ReadTemperature(const MPU6050_t * const device, MPU6050_temperature_t * const temperatureOut)
{
    if (!device || !temperatureOut)
    {
        return MPU6050_INV_ARG;
    }

    // Request temperature register reading
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_TEMP_OUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    // Read temperature register
    if (I2C_OK != i2c__MasterRead(device->port, device->buffer, MPU6050_TEMP_BYTES, MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }
    
    // Convert read value
    *temperatureOut = mpu6050_convert_temperature_bytes(device->buffer[MPU6050_TEMP_MSB], device->buffer[MPU6050_TEMP_LSB]);

    return MPU6050_OK;
}

mpu6050_error_t mpu6050__ReadGyroscope(const MPU6050_t * const device, MPU6050_gyroscope_t * const gyroscopeOut)
{
    if (!device || !gyroscopeOut)
    {
        return MPU6050_INV_ARG;
    }

    // Request gyroscope register reading
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_GYRO_XOUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    // Read gyroscope register
    if (I2C_OK != i2c__MasterRead(device->port, device->buffer, MPU6050_GYRO_BYTES, MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    // Convert read value
    gyroscopeOut->x = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_X_MSB], device->buffer[MPU6050_GYRO_X_LSB], device->gyroRange);
    gyroscopeOut->y = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_Y_MSB], device->buffer[MPU6050_GYRO_Y_LSB], device->gyroRange);
    gyroscopeOut->z = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_Z_MSB], device->buffer[MPU6050_GYRO_Z_LSB], device->gyroRange);

    return MPU6050_OK;
}

mpu6050_error_t mpu6050__ReadAccelerometer(const MPU6050_t * const device, MPU6050_accelerometer_t * const accelerometerOut)
{
    if (!device || !accelerometerOut)
    {
        return MPU6050_INV_ARG;
    }

    // Request accelerometer register reading
    if (I2C_OK != i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_ACCEL_XOUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    // Read accelerometer register
    if (I2C_OK != i2c__MasterRead(device->port, device->buffer, MPU6050_ACCEL_BYTES, MPU6050_SLAVE_ADDRESS, device->i2cWaitMs))
    {
        return MPU6050_I2C_FAIL;
    }

    // Convert read value
    accelerometerOut->x = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_X_MSB], device->buffer[MPU6050_ACCEL_X_LSB], device->accelRange);
    accelerometerOut->y = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_Y_MSB], device->buffer[MPU6050_ACCEL_Y_LSB], device->accelRange);
    accelerometerOut->z = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_Z_MSB], device->buffer[MPU6050_ACCEL_Z_LSB], device->accelRange);

    return MPU6050_OK;
}