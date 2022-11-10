#ifndef MPU6050_H
#define MPU6050_H

#include <stdbool.h>

#include "mpu6050_low.h"
#include "mpu6050_types_res.h"
#include "i2c.h"

bool mpu6050__InitDevice(MPU6050_t *device, uint8_t *buffer, MPU6050_buffer_size_t bufferSize, i2c_port_t port, i2c_config_t *config);
bool mpu6050__ConfigureGyroscope(MPU6050_t *device, MPU6050_gyro_range_t gyroRange);
bool mpu6050__ConfigureAccelerometer(MPU6050_t *device, MPU6050_accel_range_t accelRange);

bool mpu6050__ReadTemperature(MPU6050_t *device, MPU6050_temperature_t *temperatureOut);
bool mpu6050__ReadGyroscope(MPU6050_t *device, MPU6050_gyroscope_t *gyroscopeOut);
bool mpu6050__ReadAccelerometer(MPU6050_t *device, MPU6050_accelerometer_t *accelerometerOut);

#endif /* MPU6050_H */
