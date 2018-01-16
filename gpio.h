#ifndef GPIO_H_
#define GPIO_H_
#include <reg52.h>

#define HIGH		(1)
#define LOW			(0)

#define LSBFIRST	(1)
#define MSBFIRST	(0)

typedef unsigned char 	uint8_t;
typedef unsigned int 	uint16_t;



typedef enum _pin{
	P0_0 = 0, P0_1 = 1, P0_2 = 2, P0_3 = 3, P0_4 = 4, P0_5 = 5, P0_6 = 6, P0_7 = 7,
	
	P1_0 = 8, P1_1 = 9, P1_2 = 10, P1_3 = 11, P1_4 = 12, P1_5 = 13, P1_6 = 14, P1_7 = 15,
	
	P2_0 = 16, P2_1 = 17, P2_2 = 18, P2_3 = 19, P2_4 = 20, P2_5 = 21, P2_6 = 22, P2_7 = 23,

}_Pin;

void digitalWrite(_Pin pin, uint8_t);
uint8_t digitalRead(_Pin pin);
void shiftOut(_Pin dataPin, _Pin clockPin, _Pin bitOrder, uint8_t val);
uint8_t shiftIn(_Pin dataPin, _Pin clockPin, _Pin bitOrder) ;

#endif
