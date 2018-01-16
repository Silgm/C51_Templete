#ifndef _I2C_H_
#define _I2C_H_

#include "gpio.h"

typedef struct i2c_line
{
	uint8_t sda;
	uint8_t scl;
}i2cDev;

void i2cDev_Create(i2cDev *this, uint8_t sda, uint8_t scl);
void i2cDev_Start(i2cDev *this);
void i2cDev_Stop(i2cDev *this);

void i2cDev_WriteByte(i2cDev *this, uint8_t byte);
uint8_t i2cDev_ReadByte(i2cDev *this);

#endif
