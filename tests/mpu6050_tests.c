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

#define READ_PERIOD_MS      1000

static void nvs_init(void);

void mpu6050_init_test(void)
{
    uint8_t deviceBuffer[MPU6050_BUFFER_SIZE];
    MPU6050_t device;
    i2c_config_t i2cConfig;

    nvs_init();
    if (!i2c__MasterInitConfigDefault(MPU6050_SDA_GPIO, MPU6050_SCL_GPIO, MPU6050_CLK_SPEED, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize I2C configuration.");
        return;
    }
    if (!mpu6050__InitDevice(&device, deviceBuffer, MPU6050_BUFFER_SIZE, MPU6050_PORT, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize MPU6050.");
        return;
    }
    if (!mpu6050__ConfigureGyroscope(&device, MPU6050_GYRO_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 gyroscope.");
    }
    if (!mpu6050__ConfigureAccelerometer(&device, MPU6050_ACCEL_RANGE))
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
    if (!i2c__MasterInitConfigDefault(MPU6050_SDA_GPIO, MPU6050_SCL_GPIO, MPU6050_CLK_SPEED, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize I2C configuration.");
        return;
    }
    if (!mpu6050__InitDevice(&device, deviceBuffer, MPU6050_BUFFER_SIZE, MPU6050_PORT, &i2cConfig))
    {
        ESP_LOGI(TAG, "Failure while trying to initialize MPU6050.");
        return;
    }
    if (!mpu6050__ConfigureGyroscope(&device, MPU6050_GYRO_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 gyroscope.");
    }
    if (!mpu6050__ConfigureAccelerometer(&device, MPU6050_ACCEL_RANGE))
    {
        ESP_LOGI(TAG, "Failure while trying to configure MPU6050 accelerometer.");
    }

    while (1)
    {
        MPU6050_temperature_t temperature;
        if (!mpu6050__ReadTemperature(&device, &temperature))
        {
            ESP_LOGI(TAG, "Failure while trying to read temperature..");
        }
        else
        {
            ESP_LOGI(TAG, "Temperature: %.4f", temperature);
        }

        MPU6050_gyroscope_t rotation;
        if (!mpu6050__ReadGyroscope(&device, &rotation))
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
        if (!mpu6050__ReadAccelerometer(&device, &acceleration))
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