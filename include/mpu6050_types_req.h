#ifndef MPU6050_TYPES_REQ_H
#define MPU6050_TYPES_REQ_H

typedef enum MPU6050_buffer_size_t      MPU6050_buffer_size_t;
typedef enum MPU6050_gyro_range_t       MPU6050_gyro_range_t;
typedef enum MPU6050_accel_range_t      MPU6050_accel_range_t;

enum MPU6050_buffer_size_t
{
    MPU6050_BUFF_MINIMAL                = 6
};

enum MPU6050_gyro_range_t
{
    MPU6050_GYRO_250                    = 0,
    MPU6050_GYRO_500,
    MPU6050_GYRO_1000,
    MPU6050_GYRO_2000,
    MPU6050_GYRO_COUNT
};

enum MPU6050_accel_range_t
{
    MPU6050_ACCEL_2G                    = 0,
    MPU6050_ACCEL_4G,
    MPU6050_ACCEL_8G,
    MPU6050_ACCEL_16G,
    MPU6050_ACCEL_COUNT
};

#endif /* MPU6050_TYPES_REQ_H */
