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
#include "i2c.h"

#define I2C_RX_BUFFER_SIZE  0 /**< Size of I2C receive buffer */
#define I2C_TX_BUFFER_SIZE  0 /**< Size of I2C transmit buffer */
#define I2C_FLAGS           0 /**< Flags for I2C driver configuration */

#define I2C_ACK             0x0 /**< I2C ACK flag value */
#define I2C_NACK            0x1 /**< I2C NACK flag value */

i2c_error_t i2c__MasterInitConfigDefault(const int sda, const int scl, const uint32_t clkSpeed, i2c_config_t * const config)
{
    if (!config)
    {
        return I2C_INV_ARG;
    }

    config->mode = I2C_MODE_MASTER;
    config->sda_io_num = sda;
    config->sda_pullup_en = GPIO_PULLUP_ENABLE;
    config->scl_io_num = scl;
    config->scl_pullup_en = GPIO_PULLUP_ENABLE;
    config->master.clk_speed = clkSpeed;
    config->clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL;

    return I2C_OK;
}

i2c_error_t i2c__MasterInit(const i2c_port_t port, const i2c_config_t * const config)
{
    if (!config)
    {
        return I2C_INV_ARG;
    }

    if (I2C_MODE_MASTER != config->mode)
    {
        return I2C_INV_CONF;
    }

    if (ESP_OK != i2c_param_config(port, config))
    {
        return I2C_CONF_FAIL;
    }
    
    if (ESP_OK != i2c_driver_install(port, config->mode, I2C_RX_BUFFER_SIZE, I2C_TX_BUFFER_SIZE, I2C_FLAGS))
    {
        return I2C_CONF_FAIL;
    }

    return I2C_OK;
}

i2c_error_t i2c__MasterRead(const i2c_port_t port, uint8_t * const data, const size_t dataSize, const uint8_t slaveAddress, const uint16_t waitMs)
{
    if (!data || !dataSize)
    {
        return I2C_INV_ARG;
    }

    i2c_cmd_handle_t i2cCommand = i2c_cmd_link_create();
    i2c_master_start(i2cCommand);
    
    i2c_master_write_byte(i2cCommand, (slaveAddress << 1) | I2C_MASTER_READ, true);
    if (dataSize > 1)
    {
        i2c_master_read(i2cCommand, data, dataSize - 1, I2C_ACK);
    }
    i2c_master_read_byte(i2cCommand, data + dataSize - 1, I2C_NACK);

    i2c_master_stop(i2cCommand);
    i2c_error_t status = (ESP_OK != i2c_master_cmd_begin(port, i2cCommand, pdMS_TO_TICKS(waitMs))) ? I2C_OP_FAIL : I2C_OK;
    i2c_cmd_link_delete(i2cCommand);

    return status;
}

i2c_error_t i2c__MasterWrite(const i2c_port_t port, const uint8_t * const data, const size_t dataSize, const uint8_t slaveAddress, const uint16_t waitMs)
{
    if (!data || !dataSize)
    {
        return false;
    }

    i2c_cmd_handle_t i2cCommand = i2c_cmd_link_create();
    i2c_master_start(i2cCommand);

    i2c_master_write_byte(i2cCommand, (slaveAddress << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write(i2cCommand, data, dataSize, true);

    i2c_master_stop(i2cCommand);
    i2c_error_t status = (ESP_OK != i2c_master_cmd_begin(port, i2cCommand, pdMS_TO_TICKS(waitMs))) ? I2C_OP_FAIL : I2C_OK;
    i2c_cmd_link_delete(i2cCommand);

    return status;
}