#ifndef _BEEP_H_
#define _BEEP_H_

#include "gpio.h"

sbit beepPin = P1^5;

void BeepInit();
void BeepOn();
void BeepOff();


#endif

