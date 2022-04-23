#include <avr/io.h>

void adc_init(void){
	 ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0)); 
	 ADMUX |= (1<<REFS0); 
	 ADCSRA |= (1<<ADEN); 
	 ADCSRA |= (1<<ADSC); 
}

unsigned int analogRead(uint8_t channel){
	 ADMUX &= 0xF0; 
	 ADMUX |= channel; 
	 ADCSRA |= (1<<ADSC); 
	 while((ADCSRA & (1<<ADIF))==0); 
	 return ADCW; 
}

float getPt(uint8_t channel)
{
	int v = 5.0*(analogRead(channel)/1023.0);
	float Rx = v*79.489+14.187;
	return (Rx/100.0)/0.0385;
}