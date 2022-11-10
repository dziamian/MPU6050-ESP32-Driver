#ifndef MPU6050_TYPES_RES_H
#define MPU6050_TYPES_RES_H

typedef struct MPU6050_gyroscope_t      MPU6050_gyroscope_t;
typedef struct MPU6050_accelerometer_t  MPU6050_accelerometer_t;

typedef double                          MPU6050_rotate_t;
typedef double                          MPU6050_acceleration_t;
typedef double                          MPU6050_temperature_t;

struct MPU6050_gyroscope_t
{
    MPU6050_rotate_t                    x;
    MPU6050_rotate_t                    y;
    MPU6050_rotate_t                    z;
};

struct MPU6050_accelerometer_t
{
    MPU6050_acceleration_t              x;
    MPU6050_acceleration_t              y;
    MPU6050_acceleration_t              z;
};

#endif /* MPU6050_TYPES_RES_H */
