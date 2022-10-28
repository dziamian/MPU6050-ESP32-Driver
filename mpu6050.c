#include "mpu6050.h"

#include "mpu6050_registers.h"
#include "mpu6050_registers_values.h"
#include "mpu6050_converter.h"

#define MPU6050_DATA_NULL       0
#define MPU6050_DATA_1BYTE      1

bool mpu6050__InitDevice(MPU6050_t *device, uint8_t *buffer, MPU6050_buffer_size_t bufferSize, i2c_port_t port, i2c_config_t *config)
{
    if (!device || !buffer || !bufferSize)
    {
        return false;
    }

    if (!i2c__MasterInit(port, config))
    {
        return false;
    }

    device->buffer = buffer;
    device->bufferSize = bufferSize;
    device->port = port;
    device->gyroRange = MPU6050_GYRO_250;
    device->accelRange = MPU6050_ACCEL_2G;

    // Turn off sleep mode
    uint8_t data = !MPU6050_PWR_MGMT_1_SLEEP;
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_PWR_MGMT_1, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    return true;
}

bool mpu6050__ConfigureGyroscope(MPU6050_t *device, MPU6050_gyro_range_t gyroRange)
{
    if (!device)
    {
        return false;
    }

    // Configure gyroscope
    uint8_t data = gyroRange << MPU6050_GYRO_CONFIG_SHIFT;
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_GYRO_CONFIG, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    device->gyroRange = gyroRange;

    return true;
}

bool mpu6050__ConfigureAccelerometer(MPU6050_t *device, MPU6050_accel_range_t accelRange)
{
    if (!device)
    {
        return false;
    }

    // Configure accelerometer
    uint8_t data = accelRange << MPU6050_ACCEL_CONFIG_SHIFT;
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_ACCEL_CONFIG, &data, MPU6050_DATA_1BYTE
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    device->accelRange = accelRange;

    return true;
}

bool mpu6050__ReadTemperature(MPU6050_t *device, MPU6050_temperature_t *temperatureOut)
{
    if (!device || !temperatureOut)
    {
        return false;
    }

    // Request temperature register reading
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_TEMP_OUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    // Read temperature register
    if (!i2c__MasterRead(device->port, device->buffer, MPU6050_TEMP_BYTES, MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }
    
    // Convert read value
    *temperatureOut = mpu6050_convert_temperature_bytes(device->buffer[MPU6050_TEMP_MSB], device->buffer[MPU6050_TEMP_LSB]);

    return true;
}

bool mpu6050__ReadGyroscope(MPU6050_t *device, MPU6050_gyroscope_t *gyroscopeOut)
{
    if (!device || !gyroscopeOut)
    {
        return false;
    }

    // Request gyroscope register reading
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_GYRO_XOUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    // Read gyroscope register
    if (!i2c__MasterRead(device->port, device->buffer, MPU6050_GYRO_BYTES, MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    // Convert read value
    gyroscopeOut->x = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_X_MSB], device->buffer[MPU6050_GYRO_X_LSB], device->gyroRange);
    gyroscopeOut->y = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_Y_MSB], device->buffer[MPU6050_GYRO_Y_LSB], device->gyroRange);
    gyroscopeOut->z = mpu6050_convert_gyroscope_bytes(device->buffer[MPU6050_GYRO_Z_MSB], device->buffer[MPU6050_GYRO_Z_LSB], device->gyroRange);

    return true;
}

bool mpu6050__ReadAccelerometer(MPU6050_t *device, MPU6050_accelerometer_t *accelerometerOut)
{
    if (!device || !accelerometerOut)
    {
        return false;
    }

    // Request accelerometer register reading
    if (!i2c__MasterWrite(device->port, device->buffer, 
        mpu6050_buffer_write(
            device, MPU6050_ACCEL_XOUT_H, NULL, MPU6050_DATA_NULL
        ), MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    // Read accelerometer register
    if (!i2c__MasterRead(device->port, device->buffer, MPU6050_ACCEL_BYTES, MPU6050_SLAVE_ADDRESS))
    {
        return false;
    }

    // Convert read value
    accelerometerOut->x = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_X_MSB], device->buffer[MPU6050_ACCEL_X_LSB], device->accelRange);
    accelerometerOut->y = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_Y_MSB], device->buffer[MPU6050_ACCEL_Y_LSB], device->accelRange);
    accelerometerOut->z = mpu6050_convert_accelerometer_bytes(device->buffer[MPU6050_ACCEL_Z_MSB], device->buffer[MPU6050_ACCEL_Z_LSB], device->accelRange);

    return true;
}