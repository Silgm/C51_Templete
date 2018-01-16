#ifndef _I2C_H_
#define _I2C_H_

#include "gpio.h"

typedef struct i2c_line
{
	uint8_t sdl;
	uint8_t scl;
}i2cDev;

void i2cDev_Start();
void i2cDev_Stop();
bool i2cDev_WriteByte(uint8_t byte);
uint8_t i2cDev_ReadByte();

#endif
