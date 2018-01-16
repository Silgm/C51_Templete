#ifndef LCD12864_H_
#define LCD12864_H_
#include "gpio.h"

#define LCD_MOD_CHAR    1
#define LCD_MOD_GRAP    0

typedef struct _lcd12864
{
	_Pin dataPin;
	_Pin clockPin;
	_Pin CS;
	uint8_t MOD;
}Lcd12864;

void lcd12864_Create(Lcd12864 *this, _Pin CS, _Pin dataPin, _Pin clockPin);
void lcd12864_Begin(Lcd12864 *this, uint8_t lcdmod);
void lcd12864_SetCursor(Lcd12864 *this, uint8_t x, uint8_t y);
void lcd12864_Print(Lcd12864 *this, const char *szString);





#endif
