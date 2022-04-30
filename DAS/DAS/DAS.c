#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include <string.h>
#include <stdio.h>

#define PT100 0
#define WEIGHT 1

int main(void)
{
	char Msg[10];
	Initialsie_LCD();
	LCD_Message(1,0,"INITIALIZING...");
	adc_init();
    while(1)
    {
        LCD_clear();
		sprintf(Msg,"MOISTURE: %f",getVal(PT100));
		LCD_Message(1,0,Msg);
		sprintf(Msg,"TEMPERATURE: %d",getVal(WEIGHT));
		LCD_Message(2,0,Msg);
		_delay_ms(25);
    }
}