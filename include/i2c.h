#ifndef I2C_H
#define I2C_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "driver/i2c.h"

bool i2c__MasterInitConfigDefault(int sda, int scl, uint32_t clkSpeed, i2c_config_t *config);
bool i2c__MasterInit(i2c_port_t port, i2c_config_t *config);

bool i2c__MasterRead(i2c_port_t port, uint8_t *data, size_t dataSize, uint8_t slaveAddress);
bool i2c__MasterWrite(i2c_port_t port, uint8_t *data, size_t dataSize, uint8_t slaveAddress);

#endif /* I2C_H */
