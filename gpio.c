#include "gpio.h"

#define PORT0	0
#define PORT1	1
#define PORT2	2


#define digitalPinToPort(pin) 		(pin/8)
#define digitalPinToBitMask(pin)	(0x01<<(pin%8))

void digitalWrite(_Pin pin, uint8_t val)
{
	uint8_t bitMask = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	
	switch(port)
	{
		case PORT0:
			if (val)
			{
				P0 |= bitMask;
			}
			else
			{
				P0 &= ~bitMask;
			}				
			break;
		case PORT1:
			if (val)
			{
				P1 |= bitMask;
			}
			else
			{
				P1 &= ~bitMask;
			}
			break;
		case PORT2:
			if (val)
			{
				P2 |= bitMask;
			}
			else
			{
				P2 &= ~bitMask;
			}
			break;
		default:
			break;
	}
}


uint8_t digitalRead(_Pin pin)
{
	uint8_t bitMask = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	
	switch(port)
	{
		case PORT0:
			return (P0 & bitMask);
			break;
		case PORT1:
			return (P1 & bitMask);
			break;
		case PORT2:
			return (P2 & bitMask);
			break;
		default:
			break;
	}
	return HIGH;
}

uint8_t shiftIn(_Pin dataPin, _Pin clockPin, _Pin bitOrder) 
{
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, HIGH);
		if (bitOrder)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, LOW);
	}
	return value;
}


void shiftOut(_Pin dataPin, _Pin clockPin, _Pin bitOrder, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}

