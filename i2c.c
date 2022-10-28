#include "i2c.h"

#define I2C_RX_BUFFER_SIZE  0
#define I2C_TX_BUFFER_SIZE  0
#define I2C_FLAGS           0

#define I2C_ACK             0x0
#define I2C_NACK            0x1

bool i2c__MasterInitConfigDefault(int sda, int scl, uint32_t clkSpeed, i2c_config_t *config)
{
    if (!config)
    {
        return false;
    }

    config->mode = I2C_MODE_MASTER;
    config->sda_io_num = sda;
    config->sda_pullup_en = GPIO_PULLUP_ENABLE;
    config->scl_io_num = scl;
    config->scl_pullup_en = GPIO_PULLUP_ENABLE;
    config->master.clk_speed = clkSpeed;
    config->clk_flags = I2C_SCLK_SRC_FLAG_FOR_NOMAL;

    return true;
}

bool i2c__MasterInit(i2c_port_t port, i2c_config_t *config)
{
    if (!config)
    {
        return false;
    }

    if (ESP_OK != i2c_param_config(port, config))
    {
        return false;
    }
    
    if (ESP_OK != i2c_driver_install(port, config->mode, I2C_RX_BUFFER_SIZE, I2C_TX_BUFFER_SIZE, I2C_FLAGS))
    {
        return false;
    }

    return true;
}

bool i2c__MasterRead(i2c_port_t port, uint8_t *data, size_t dataSize, uint8_t slaveAddress)
{
    if (!data || !dataSize)
    {
        return false;
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
    bool status = (ESP_OK == i2c_master_cmd_begin(port, i2cCommand, pdMS_TO_TICKS(1000)));
    i2c_cmd_link_delete(i2cCommand);

    return status;
}

bool i2c__MasterWrite(i2c_port_t port, uint8_t *data, size_t dataSize, uint8_t slaveAddress)
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
    bool status = (ESP_OK == i2c_master_cmd_begin(port, i2cCommand, pdMS_TO_TICKS(1000)));
    i2c_cmd_link_delete(i2cCommand);

    return status;
}