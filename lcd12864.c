#include "lcd12864.h"



#define  CMD_CLEAR                  0x01 //清屏
#define  CMD_RESET_DDRAM            0x02 //DDRAM地址归位
#define  CMD_LEFT_MOVE              0x04 //游标左移
#define  CMD_RIGHT_MOVE             0x06 //游标右移
#define  CMD_ALL_LEFT_MOVE          0x05 //画面整体左移
#define  CMD_ALL_RIGHT_MOVE         0x07 //画面整体右移
#define  CMD_ENABLE_WITHOUT_CUR     0x0c //开显示，无游标，不反白
#define  CMD_ENABLE_WITH_CUR        0x0f //开显示，开游标，不反白
#define  CMD_DISPLAY_LEFT_MOVE      0x10 //显示游标左移
#define  CMD_DISPLAY_RIGHT_MOVE     0x14 //显示游标右移
#define  CMD_SET_FUNCTION1          0x30 //基本指令集动作
#define  CMD_SET_CGRAM              0x40 //设定CGRAM地址
#define  CMD_SET_DDRAM              0x80 //设定DDRAM地址
#define  CMD_SET_FUNCTION2          0x34 //扩充指令集动作
#define  CMD_FUNCTION2_REV_WRITE    0x04 //反白第一行(扩充指令集)
#define  CMD_FUNCTION2_SET_GDRAM    0x80 //设定GDRAM地址(扩充指令集)
#define  CMD_FUNCTION2_ON_GRAPHIC   0x36 //开绘图显示(扩充指令集)
#define  CMD_FUNCTION2_OFF_GRAPHIC  0x34 //关绘图显示(扩充指令集)

static void delay(long ms)
{
	int i = 0;
	for (;ms > 0 ;ms--)
		for (; i < 120; i++);
}

static void lcd12864_WriteCmd(Lcd12864 *this, uint8_t cmd)
{
	digitalWrite(this->CS, HIGH);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xf8);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xf0&cmd);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xf0&(cmd<<4));
	digitalWrite(this->CS, LOW);
}

static void lcd12864_WriteDat(Lcd12864 *this, uint8_t dat)
{
	digitalWrite(this->CS, HIGH);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xfa);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xf0&dat);
	shiftOut(this->dataPin, this->clockPin, MSBFIRST, 0xf0&(dat<<4));
	digitalWrite(this->CS, LOW);
}



void lcd12864_Create(Lcd12864 *this, _Pin CS, _Pin dataPin, _Pin clockPin)
{
	this->CS = CS;
	this->dataPin = dataPin;
	this->clockPin = clockPin;
}

void lcd12864_Begin(Lcd12864 *this, uint8_t lcdmod)
{
	if (lcdmod == LCD_MOD_CHAR){
		this->MOD = lcdmod;
		lcd12864_WriteCmd(this, CMD_SET_FUNCTION1);
		lcd12864_WriteCmd(this, CMD_ENABLE_WITHOUT_CUR);
		lcd12864_WriteCmd(this, CMD_CLEAR);
		delay(5);
		lcd12864_WriteCmd(this, CMD_RESET_DDRAM);
		lcd12864_WriteCmd(this, CMD_RIGHT_MOVE);
	}
}

void lcd12864_SetCursor(Lcd12864 *this, uint8_t x, uint8_t y)
{
	if (this->MOD == LCD_MOD_CHAR){
		switch (x){
		case 0:
			lcd12864_WriteCmd(this, 0x80 + y);
			break;
		case 1:
			lcd12864_WriteCmd(this, 0x90 + y);
			break;
		case 2:
			lcd12864_WriteCmd(this, 0x88 + y);
			break;
		case 3:
			lcd12864_WriteCmd(this, 0x98 + y);
			break;
		default:
			break;
		}
	}
}

void lcd12864_Print(Lcd12864 *this, const char *szString)
{
	char *pStr = szString;
	while (*pStr)
		lcd12864_WriteDat(this, *pStr++);
}
	












