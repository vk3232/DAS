#include <avr/io.h>
#include<util/delay.h>

void LCD_COMMAND(unsigned char Command)
{
	PORTC = 0b10000000;
	PORTD = Command;
	_delay_ms(5);
	PORTC = 0b00000000;
}
void LCD_DATA(unsigned char MESSAGE)
{
	PORTC = 0b10100000;
	PORTD = MESSAGE;
	_delay_ms(5);
	PORTC = 0b00100000;
}
void Initialsie_LCD(void)
{
	DDRC = 0xFF;
	DDRD = 0xFF;
	LCD_COMMAND(0x38);
	LCD_COMMAND(0x0E);
	LCD_COMMAND(0x06);
	LCD_COMMAND(0x01);
	LCD_COMMAND(0x80);
}
void LCD_clear()
{
	LCD_COMMAND(0x01);
}
void LCD_Message(unsigned char ROW, unsigned char COL, char *Message)
{
	if(ROW == 1)
		ROW = 0x80;
	else
		ROW = 0xC0;
	LCD_COMMAND(ROW|COL);
	while(*Message)
	{
		LCD_DATA(*Message);
		Message++;
	}
}