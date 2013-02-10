#include <avr/interrupt.h>
#include <avr/io.h>
#include "serial.h"

void timer_init()
{
	TCCR0A = 1 << WGM01;
	TCCR0B = (1 << CS02) | (1 << CS00);

	TIFR0 = (1 << OCF0A);
	OCR0A = 250;

	TIMSK0 = 1 << OCIE0A;

	TCNT0 = 0;
}

unsigned count = 0;

/*
ISR(TIMER0_COMPA_vect)
{
	TIFR0 = (1 << OCF0A);
	TCNT0 = 0;
	
  if (++count == 1000)
  {
  	count = 0;
		uart_write_sync("!"); 
	}
}
*/
