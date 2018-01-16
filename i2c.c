#include "i2c.h"

void i2cDev_Create(i2cDev *this, uint8_t sda, uint8_t scl)
{
	this->sda = sda;
	this->scl = scl;
	digitalWrite(this->sda, HIGH);
	digitalWrite(this->scl, HIGH);
}

void i2cDev_Start(i2cDev *this)
{
	digitalWrite(this->sda, HIGH);
	digitalWrite(this->scl, HIGH);
	
	digitalWrite(this->sda, LOW);
	digitalWrite(this->scl, LOW);
}

void i2cDev_Stop(i2cDev *this)
{
	digitalWrite(this->sda, LOW);
	digitalWrite(this->scl, HIGH);
	digitalWrite(this->sda, HIGH);
}

void i2cDev_WriteByte(i2cDev *this, uint8_t byte)
{
	uint8_t loop;
	for (loop = 0; loop < 8; ++loop)
	{
		digitalWrite(this->sda, (byte & 0x80) != 0);
		digitalWrite(this->scl, HIGH);
		digitalWrite(this->sda, LOW);
		byte <<= 1;
	}
}

uint8_t i2cDev_ReadByte(i2cDev *this)
{
	uint8_t byte = 0;
	uint8_t loop;
	
	for (loop = 0; loop < 8; ++loop) {
		digitalWrite(this->sda, HIGH);
		digitalWrite(this->scl, HIGH);
		byte = (byte << 1) | digitalRead(this->sda);
		digitalWrite(this->scl, LOW);
	}

  return byte;
}


