/*
 * GccApplication1.c
 *
 * Created: 9/3/2015 10:26:37
 *  Author: gxsham
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "serial.h"
int main(void)
{
	char ch; 
	usart_init(51);
	InitializingLED();
	printf("hello from faf-131");
	while(1)
	{
		printf("Press 1 to turn on LED, press 0 to turn off\r");
		ch = usart_getchar() ; 
		if (ch=='0')
		{
			LEDoff();
			printf("led off\r");
		}
		else if (ch=='1')
		{
			LEDon();
			printf("led on\r");
		}
	}

}