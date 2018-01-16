#include <reg52.h>
#include "gpio.h"
#include "lcd12864.h"
#include "beep.h"
#include "i2c.h"

void delay_ms(int ms)
{
	int i = 0, j = 0;
	for (i = 0; i < 120; ++i)
		for (j = 0; j < ms; ++j);
}
	

int main()
{
	Lcd12864 lcd;
	BeepInit();
	lcd12864_Create(&lcd, P2_7, P2_6, P2_5);
	lcd12864_Begin(&lcd, LCD_MOD_CHAR);
	lcd12864_SetCursor(&lcd, 0, 0);
	while(1)
	{
		if (!digitalRead(P1_0))
		{
			lcd12864_SetCursor(&lcd, 0, 0);
			lcd12864_Print(&lcd, "CO:Warning");
			BeepOn();
		}
		else
		{
			lcd12864_SetCursor(&lcd, 0, 0);
			lcd12864_Print(&lcd, "CO:Normoal");			
			BeepOff();
		}	
		
		if (!digitalRead(P1_1))
		{
			lcd12864_SetCursor(&lcd, 1, 0);
			lcd12864_Print(&lcd, "shake:Warning");
			BeepOn();
			delay_ms(1000);
		}
		else
		{
			lcd12864_SetCursor(&lcd, 1, 0);
			lcd12864_Print(&lcd, "shake:Normoal");			
			BeepOff();
		}
	}
}
