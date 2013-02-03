
/*
enum BaudRate { BR_9600 = 9600, BR_19200 = 19200, BR_57600 = 57600, BR_115200 = 115200 };

typedef struct _tagSerialParams
{
  BaudRate baud_rate;
} 
SerialParams;
*/
void uart_write_sync(char * buffer);

void uart_init(unsigned baud);
