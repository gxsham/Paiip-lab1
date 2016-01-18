/*
 * LEDdriver.c
 *
 * Created: 9/17/2015 10:48:53
 *  Author: gxsham
 */ 
#include "LEDdriver.h"
#include <avr/io.h>

void InitializingLED()
{
	DDRA = (1<<7) ; 
	PORTA = !(1<<7) ; 
}

void LEDon()
{
	 PORTA |=  1<<7 ; 
}

void LEDoff()
{
   PORTA &= !(1<<7);	
}