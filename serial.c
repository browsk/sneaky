#include <avr/io.h>


#define BRR(baud) F_CPU/16/(baud - 1)

void uart_write_sync(char * buffer)
{
  while(*buffer != 0)
  {
		while(!(UCSR0A & (1 << UDRE0)));	
		UDR0 = *buffer++;
  }
}

void uart_init(unsigned baud)
{
  unsigned brr = BRR(baud);

  UBRR0H = (brr >> 8);
  UBRR0L = (brr & 0x00ff);

	// enable rx and tx
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	// 8n1
  UCSR0C = 0x06;

}
