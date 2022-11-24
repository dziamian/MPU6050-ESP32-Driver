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
#include "mpu6050_low.h"

#include "mpu6050_registers.h"

/** Means that buffer has not been overwritten */
#define MPU6050_BUFFER_NULL     0

/** Index of the start of the data buffer */
#define MPU6050_BUFFER_START    0

size_t mpu6050_buffer_write(const MPU6050_t * const device, const uint8_t cmd, const uint8_t * const data, const size_t dataSize)
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