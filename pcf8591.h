#ifndef _PCF8591_H_
#define _PCF8591_H_

#include "i2c.h"


#define PCF8591_ADDRESS 0x48

typedef struct _pcf8591{
	i2cDev dev;	
}Pcf8591;

void pcf8591_Create(Pcf8591 *this, uint8_t sda, uint8_t sdl);
void pcf8591_Begin(Pcf8591 *this);

#endif
