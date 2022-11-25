# MPU6050-ESP32-Driver

## Introduction

Project includes component for controlling [MPU6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/) device. It is compatible with ESP32 microcontrollers. Source code of the driver has been written in C. 

It is written and tested for v4.4.2 of the [ESP-IDF](https://github.com/espressif/esp-idf) environment using the xtensa-esp32-elf toolchain (gcc version 8.4.0).

## Build

To include the component into your ESP-IDF project, you need to create `CMakeLists.txt` file containing:
```cmake
idf_component_register(
    SRC_DIRS "." "com"
    INCLUDE_DIRS "/include" "com/include"
    REQUIRES "nvs_flash"
)
```

Consult [ESP-IDF documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html) for more details about build system.

## Features

✔️ Static memory allocation <br />

✔️ Instantiation - using many driver instances simultaneously is possible <br />

✔️ Supports measurement of temperature (in Celsius), gyroscope (3-axis in °/s) and accelerometer (3-axis as gravitational acceleration) <br />

✔️ Supports configuring the full scale range of sensors - gyroscope and accelerometer <br />

## Example

Below is the example of using the driver.

```c
#define MPU6050_I2C_PORT        I2C_NUM_1               // Port where I2C driver will be installed
#define MPU6050_I2C_SDA_GPIO    23                      // I2C SDA GPIO
#define MPU6050_I2C_SCL_GPIO    18                      // I2C SCL GPIO
#define MPU6050_I2C_CLK_SPEED   100000                  // I2C clock speed frequency in Hz
#define MPU6050_I2C_WAIT_MS     1000                    // Time allowed to perform the read/write operation

#define MPU6050_GYRO_RANGE      MPU6050_GYRO_2000       // Full scale range for gyroscope
#define MPU6050_ACCEL_RANGE     MPU6050_ACCEL_2G        // Full scale range for accelerator
#define MPU6050_BUFFER_SIZE     MPU6050_BUFF_MINIMAL    // Internal buffer size for the MPU6050 instance

uint8_t deviceBuffer[MPU6050_BUFFER_SIZE];
MPU6050_t device;
i2c_config_t i2cConfig;

//! Initialize NVS flash - check https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/storage/nvs_flash.html

if (I2C_OK != i2c__MasterInitConfigDefault(MPU6050_I2C_SDA_GPIO, MPU6050_I2C_SCL_GPIO, MPU6050_I2C_CLK_SPEED, &i2cConfig))
{
    // Error handling
}
if (MPU6050_OK != mpu6050__InitDevice(&device, deviceBuffer, MPU6050_BUFFER_SIZE, MPU6050_I2C_PORT, MPU6050_I2C_WAIT_MS, &i2cConfig))
{
    // Error handling
}
if (MPU6050_OK != mpu6050__ConfigureGyroscope(&device, MPU6050_GYRO_RANGE))
{
    // Error handling
}
if (MPU6050_OK != mpu6050__ConfigureAccelerometer(&device, MPU6050_ACCEL_RANGE))
{
    // Error handling
}

while (1)
{
    MPU6050_temperature_t temperature;
    if (MPU6050_OK != mpu6050__ReadTemperature(&device, &temperature))
    {
        // Error handling
    }
    printf("Temperature: %.4f", temperature);

    MPU6050_gyroscope_t rotation;
    if (MPU6050_OK != mpu6050__ReadGyroscope(&device, &rotation))
    {
        // Error handling
    }
    printf("Rotation X: %.4f", rotation.x);
    printf("Rotation Y: %.4f", rotation.y);
    printf("Rotation Z: %.4f", rotation.z);

    MPU6050_accelerometer_t acceleration;
    if (MPU6050_OK != mpu6050__ReadAccelerometer(&device, &acceleration))
    {
        // Error handling
    }
    printf("Acceleration X: %.4f", acceleration.x);
    printf("Acceleration Y: %.4f", acceleration.y);
    printf("Acceleration Z: %.4f", acceleration.z);

    // Delay infinite loop for some time
}
```

## Documentation

Generated API documentation is available [here](http://dziamian.github.io/MPU6050-ESP32-Driver).

## Source Code

The source code is available on [GitHub](https://github.com/dziamian/MPU6050-ESP32-Driver).

## License

The code in this project is licensed under the MIT license - see [LICENSE.md](https://github.com/dziamian/MPU6050-ESP32-Driver/blob/main/LICENSE.md) for details.

## Links
 
 * [ESP-IDF](https://github.com/espressif/esp-idf)
 * [MPU6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
 * [MPU6050 Datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf)
 * [MPU6050 Register Map](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Register-Map1.pdf)