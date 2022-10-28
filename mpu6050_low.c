#include "mpu6050_low.h"

#include "mpu6050_registers.h"

#define MPU6050_BUFFER_NULL     0

#define MPU6050_BUFFER_START    0

size_t mpu6050_buffer_write(MPU6050_t *device, uint8_t cmd, uint8_t *data, size_t dataSize)
{
    if (!device || (!data && MPU6050_BUFFER_NULL < dataSize)) 
    { 
        return MPU6050_BUFFER_NULL;
    }

    size_t index = MPU6050_BUFFER_START;
    device->buffer[index++] = cmd;
    for (size_t dataIndex = 0; dataIndex < dataSize; ++dataIndex) 
    {
        device->buffer[index++] = data[dataIndex];
    }
    
    return index;
}