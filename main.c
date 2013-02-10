#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "serial.h"

extern unsigned count;

void timer_init();

const delay_val = 500;

int main (void)
{
 DDRB |= _BV(DDB5);

 uart_init(9600);
 timer_init();

  sei();
 
 while(1) {
  PORTB |= _BV(PORTB5);
  _delay_ms(delay_val);

  PORTB &= ~_BV(PORTB5);
  _delay_ms(delay_val);

//  uart_write_sync("hello");
 }


 return 0;
}
