/*
 * Serial.c
 *
 * Created: 9/17/2015 09:09:06
 *  Author: gxsham
 */ 
#include "serial.h"

static FILE mystdout = FDEV_SETUP_STREAM (usart_putchar, usart_getchar, _FDEV_SETUP_RW);

void usart_init( uint16_t ubrr) {
	
	stdout = &mystdout ;
	// Set baud rate
	UBRRH = (uint8_t)(ubrr>>8);
	UBRRL = (uint8_t)ubrr;
	// Enable receiver and transmitter
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// Set frame format: 8data, 1stop bit
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
}
void usart_putchar(char data) {
	// Wait for empty transmit buffer
	while ( !(UCSRA & (_BV(UDRE))) );
	// Start transmission
	UDR = data;
}
char usart_getchar(void) {
	// Wait for incoming data
	while ( !(UCSRA & (_BV(RXC))) );
	// Return the data
	return UDR;
}
