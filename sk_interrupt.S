#include <avr/io.h>

  temp = 19

	.section .text 

	.global	TIMER0_COMPA_vect

TIMER0_COMPA_vect:
  push	r19
	ldi		temp, '*'
  sts		UDR0, temp
	eor		r19, r19
  sts		TCNT0, r19
#TIFR0 = (1 << OCF0A);
	pop		r19
	reti
	
