#ifndef MPU6050_REGISTERS_VALUES_H
#define MPU6050_REGISTERS_VALUES_H

#define MPU6050_TEMP_MSB                0
#define MPU6050_TEMP_LSB                1
#define MPU6050_TEMP_BYTES              2

#define MPU6050_GYRO_X_MSB              0
#define MPU6050_GYRO_X_LSB              1
#define MPU6050_GYRO_Y_MSB              2
#define MPU6050_GYRO_Y_LSB              3
#define MPU6050_GYRO_Z_MSB              4
#define MPU6050_GYRO_Z_LSB              5
#define MPU6050_GYRO_BYTES              6

#define MPU6050_ACCEL_X_MSB             0
#define MPU6050_ACCEL_X_LSB             1
#define MPU6050_ACCEL_Y_MSB             2
#define MPU6050_ACCEL_Y_LSB             3
#define MPU6050_ACCEL_Z_MSB             4
#define MPU6050_ACCEL_Z_LSB             5
#define MPU6050_ACCEL_BYTES             6

#define MPU6050_GYRO_CONFIG_SHIFT       3
#define MPU6050_ACCEL_CONFIG_SHIFT      3

#define MPU6050_PWR_MGMT_1_RESET        0x80
#define MPU6050_PWR_MGMT_1_SLEEP        0x40
#define MPU6050_PWR_MGMT_1_CYCLE        0x20
#define MPU6050_PWR_MGMT_1_TEMP_DIS     0x08

#endif /* MPU6050_REGISTERS_VALUES_H */
