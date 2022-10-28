#ifndef MPU6050_LOW_H
#define MPU6050_LOW_H

#include "driver/i2c.h"

typedef enum MPU6050_buffer_size_t      MPU6050_buffer_size_t;
typedef enum MPU6050_gyro_range_t       MPU6050_gyro_range_t;
typedef enum MPU6050_accel_range_t      MPU6050_accel_range_t;
typedef struct MPU6050_t                MPU6050_t;

typedef double                          MPU6050_rotate_t;
typedef double                          MPU6050_acceleration_t;
typedef double                          MPU6050_temperature_t;

enum MPU6050_buffer_size_t
{
    MPU6050_BUFF_MINIMAL                = 6
};

enum MPU6050_gyro_range_t
{
    MPU6050_GYRO_250 = 0,
    MPU6050_GYRO_500,
    MPU6050_GYRO_1000,
    MPU6050_GYRO_2000,
    MPU6050_GYRO_COUNT
};

enum MPU6050_accel_range_t
{
    MPU6050_ACCEL_2G = 0,
    MPU6050_ACCEL_4G,
    MPU6050_ACCEL_8G,
    MPU6050_ACCEL_16G,
    MPU6050_ACCEL_COUNT
};

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
