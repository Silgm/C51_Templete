#include <reg52.h>
#include "gpio.h"
#include "lcd12864.h"
#include "beep.h"

int main()
{
	Lcd12864 lcd;
	beepInit();
	lcd12864_Create(&lcd, P2_7, P2_6, P2_5);
	lcd12864_Begin(&lcd, LCD_MOD_CHAR);
	lcd12864_SetCursor(&lcd, 0, 0);
	while(1)
	{
		if (!digitalRead(P1_0))
		{
			lcd12864_SetCursor(&lcd, 0, 0);
			lcd12864_Print(&lcd, "Warning");
			beepOn();
		}
		else
		{
			lcd12864_SetCursor(&lcd, 0, 0);
			lcd12864_Print(&lcd, "Normoal");			
			beepOff();
		}	
	}
}
