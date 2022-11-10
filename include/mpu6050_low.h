#ifndef MPU6050_LOW_H
#define MPU6050_LOW_H

#include "driver/i2c.h"

#include "mpu6050_types_req.h"

typedef struct MPU6050_t                MPU6050_t;

struct MPU6050_t
{
    uint8_t                             *buffer;
    MPU6050_buffer_size_t               bufferSize;
    i2c_port_t                          port;
    MPU6050_gyro_range_t                gyroRange;
    MPU6050_accel_range_t               accelRange;
};

size_t mpu6050_buffer_write(MPU6050_t *device, uint8_t cmd, uint8_t *data, size_t dataSize);

#endif /* MPU6050_LOW_H */
