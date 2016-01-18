/*
 * serial.h
 *
 * Created: 9/17/2015 09:14:03
 *  Author: gxsham
 */ 
//http://efundies.com/avr/avr_printf.htm

#ifndef SERIAL_H_
#define SERIAL_H_

#include <avr/io.h>
#include <stdio.h>



void usart_init(uint16_t ubrr);
char usart_getchar( void );
void usart_putchar( char data );




#endif /* SERIAL_H_ */