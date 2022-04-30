#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include <string.h>
#include <stdio.h>

#define PT100 0
#define WEIGHT 1

unsigned long voltage;

int main(void)
{
	char Msg1[] = "TEMP: 0.000 Volts";
	char Msg2[] = "WEG : 0.000 volts";
	Initialsie_LCD();
	LCD_Message(1,0,"INITIALIZING...");
	adc_init();
    while(1)
    {
        LCD_clear();
		
		voltage = analogRead(PT100);
		
		Msg1[6]=(voltage/1000)+48;
		Msg1[7]=(voltage%1000)/100+0x30;
		Msg1[8]=(voltage%100)/10+0x30;
		Msg1[9]=(voltage%10) + 0x30;
		
		LCD_Message(1,0,Msg);
		
		voltage = analogRead(PT100);
		
		Msg2[6]=(voltage/1000)+48;
		Msg2[7]=(voltage%1000)/100+0x30;
		Msg2[8]=(voltage%100)/10+0x30;
		Msg2[9]=(voltage%10) + 0x30;
		
		LCD_Message(2,0,Msg);
		_delay_ms(25);
    }
}