#include "mpu6050_converter.h"

#define MPU6050_TEMP_CONVERTER_MSB_MULTIPLIER   256
#define MPU6050_TEMP_CONVERTER_VALUE_DIVIDER    340.0
#define MPU6050_TEMP_CONVERTER_BASE             36.53

#define MPU6050_GYRO_CONVERTER_MSB_MULTIPLIER   256
#define MPU6050_ACCEL_CONVERTER_MSB_MULTIPLIER  256

#define MPU6050_GYRO_CONFIG_FS_SENS_250         131.0
#define MPU6050_GYRO_CONFIG_FS_SENS_500         65.5
#define MPU6050_GYRO_CONFIG_FS_SENS_1000        32.8
#define MPU6050_GYRO_CONFIG_FS_SENS_2000        16.4

#define MPU6050_GYRO_CONFIG_AFS_SENS_2G         16384.0
#define MPU6050_GYRO_CONFIG_AFS_SENS_4G         8192.0
#define MPU6050_GYRO_CONFIG_AFS_SENS_8G         4096.0
#define MPU6050_GYRO_CONFIG_AFS_SENS_16G        2048.0

static MPU6050_rotate_t gyroscopeSensitivities[MPU6050_GYRO_COUNT] =
{
    [MPU6050_GYRO_250] MPU6050_GYRO_CONFIG_FS_SENS_250,
    [MPU6050_GYRO_500] MPU6050_GYRO_CONFIG_FS_SENS_500,
    [MPU6050_GYRO_1000] MPU6050_GYRO_CONFIG_FS_SENS_1000,
    [MPU6050_GYRO_2000] MPU6050_GYRO_CONFIG_FS_SENS_2000
};
static MPU6050_acceleration_t accelerometerSensitivities[MPU6050_ACCEL_COUNT] =
{
    [MPU6050_ACCEL_2G] MPU6050_GYRO_CONFIG_AFS_SENS_2G,
    [MPU6050_ACCEL_4G] MPU6050_GYRO_CONFIG_AFS_SENS_4G,
    [MPU6050_ACCEL_8G] MPU6050_GYRO_CONFIG_AFS_SENS_8G,
    [MPU6050_ACCEL_16G] MPU6050_GYRO_CONFIG_AFS_SENS_16G
};

MPU6050_temperature_t mpu6050_convert_temperature_bytes(uint8_t msb, uint8_t lsb)
{
    return (MPU6050_temperature_t)
                ((int16_t) (lsb + (msb * MPU6050_TEMP_CONVERTER_MSB_MULTIPLIER)))
                    / MPU6050_TEMP_CONVERTER_VALUE_DIVIDER + MPU6050_TEMP_CONVERTER_BASE;
}

MPU6050_rotate_t mpu6050_convert_gyroscope_bytes(uint8_t msb, uint8_t lsb, MPU6050_gyro_range_t gyroRange)
{
    return (MPU6050_rotate_t)
                ((int16_t) (lsb + (msb * MPU6050_GYRO_CONVERTER_MSB_MULTIPLIER)))
                    / gyroscopeSensitivities[gyroRange];
}

MPU6050_acceleration_t mpu6050_convert_accelerometer_bytes(uint8_t msb, uint8_t lsb, MPU6050_accel_range_t accelRange)
{
    return (MPU6050_acceleration_t)
                ((int16_t) -(lsb + (msb * MPU6050_ACCEL_CONVERTER_MSB_MULTIPLIER)))
                    / accelerometerSensitivities[accelRange];
}