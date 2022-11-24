/*
 * MIT License
 *
 * Copyright (c) 2022 Damian Ślusarczyk
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include "mpu6050_tests.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "mpu6050.h"

#define TAG                 "MPU6050"

#define MPU6050_PORT        I2C_NUM_1
#define MPU6050_SDA_GPIO    23
#define MPU6050_SCL_GPIO    18
#define MPU6050_CLK_SPEED   100000
#define MPU6050_GYRO_RANGE  MPU6050_GYRO_2000
#define MPU6050_ACCEL_RANGE MPU6050_ACCEL_2G

#define MPU6050_BUFFER_SIZE MPU6050_BUFF_MINIMAL
#define MPU6050_I2C_WAIT_MS 1000

#define READ_PERIOD_MS      1000

static void nvs_init(void);

void mpu6050_init_test(void)
{
    uint8_t deviceBuffer[MPU6050_BUFFER_SIZE];
    MPU6050_t device;
    i2c_config_t i2cConfig;

    nvs_init();
    if (I2C_OK != i2c__MasterInitConfigDefault(MPU6050_SDA_GPIO, MPU6050_SCL_GPIO, MPU6050_CLK_SPEED, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize I2C configuration.");
        return;
    }
    if (MPU6050_OK != mpu6050__InitDevice(&device, deviceBuffer, MPU6050_BUFFER_SIZE, MPU6050_PORT, MPU6050_I2C_WAIT_MS, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize MPU6050.");
        return;
    }
    if (MPU6050_OK != mpu6050__ConfigureGyroscope(&device, MPU6050_GYRO_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 gyroscope.");
    }
    if (MPU6050_OK != mpu6050__ConfigureAccelerometer(&device, MPU6050_ACCEL_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 accelerometer.");
    }

    ESP_LOGI(TAG, "Successfully initialized MPU6050 driver.");

    return;
}

void mpu6050_reading_test(void)
{
    uint8_t deviceBuffer[MPU6050_BUFFER_SIZE];
    MPU6050_t device;
    i2c_config_t i2cConfig;

    nvs_init();
    if (I2C_OK != i2c__MasterInitConfigDefault(MPU6050_SDA_GPIO, MPU6050_SCL_GPIO, MPU6050_CLK_SPEED, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize I2C configuration.");
        return;
    }
    if (MPU6050_OK != mpu6050__InitDevice(&device, deviceBuffer, MPU6050_BUFFER_SIZE, MPU6050_PORT, MPU6050_I2C_WAIT_MS, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize MPU6050.");
        return;
    }
    if (MPU6050_OK != mpu6050__ConfigureGyroscope(&device, MPU6050_GYRO_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 gyroscope.");
    }
    if (MPU6050_OK != mpu6050__ConfigureAccelerometer(&device, MPU6050_ACCEL_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 accelerometer.");
    }

    while (1)
    {
        MPU6050_temperature_t temperature;
        if (MPU6050_OK != mpu6050__ReadTemperature(&device, &temperature))
        {
            ESP_LOGI(TAG, "Failure while trying to read temperature..");
        }
        else
        {
            ESP_LOGI(TAG, "Temperature: %.4f", temperature);
        }

        MPU6050_gyroscope_t rotation;
        if (MPU6050_OK != mpu6050__ReadGyroscope(&device, &rotation))
        {
            ESP_LOGI(TAG, "Failure while trying to read gyroscope values..");
        }
        else
        {
            ESP_LOGI(TAG, "Rotation X: %.4f", rotation.x);
            ESP_LOGI(TAG, "Rotation Y: %.4f", rotation.y);
            ESP_LOGI(TAG, "Rotation Z: %.4f", rotation.z);
        }

        MPU6050_accelerometer_t acceleration;
        if (MPU6050_OK != mpu6050__ReadAccelerometer(&device, &acceleration))
        {
            ESP_LOGI(TAG, "Failure while trying to read accelerometer values..");
        }
        else
        {
            ESP_LOGI(TAG, "Acceleration X: %.4f", acceleration.x);
            ESP_LOGI(TAG, "Acceleration Y: %.4f", acceleration.y);
            ESP_LOGI(TAG, "Acceleration Z: %.4f", acceleration.z);
        }

        vTaskDelay(pdMS_TO_TICKS(READ_PERIOD_MS));
    }
}

static void nvs_init(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}