#ifndef MPU6050_CONVERTER_H
#define MPU6050_CONVERTER_H

#include "mpu6050_low.h"
#include "mpu6050_types_res.h"

MPU6050_temperature_t mpu6050_convert_temperature_bytes(uint8_t msb, uint8_t lsb);
MPU6050_rotate_t mpu6050_convert_gyroscope_bytes(uint8_t msb, uint8_t lsb, MPU6050_gyro_range_t gyroRange);
MPU6050_acceleration_t mpu6050_convert_accelerometer_bytes(uint8_t msb, uint8_t lsb, MPU6050_accel_range_t accelRange);

#endif /* MPU6050_CONVERTER_H */
