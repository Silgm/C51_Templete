#include "beep.h"


#define FOSC 11960334L

#define T1MS (65534)   //1ms timer calculation method in 12T mode

uint8_t status = 0;

void BeepInit()
{
	
	TMOD = 0x01;                    //set timer0 as mode1 (16-bit)
    TL0 = T1MS;                     //initial timer0 low byte
    TH0 = T1MS >> 8;                //initial timer0 high byte
    TR0 = 1;                        //timer0 start running
    ET0 = 1;                        //enable timer0 interrupt
    EA = 1;                         //open global interrupt switch
}

void BeepOn()
{
	status = 1;
}


void BeepOff()
{
	status = 0;
}

void tm0_isr() interrupt 1 using 1
{
    TL0 = T1MS;                     //reload timer0 low byte
    TH0 = T1MS >> 8;                //reload timer0 high byte
	if (status)
	{
		beepPin = ! beepPin;      //work LED flash
	}
}


