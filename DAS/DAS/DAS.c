#include <avr/io.h>
#include "ADC.h"
#include "LCD.h"
#include <string.h>
#include <stdio.h>

#define PT100 0

int main(void)
{
    while(1)
    {
        float pt=  getPt(PT100);
    }
}