// serial.h

// Mini UART registers
#define MU_IO 0x3F215040 // MU_IO register
#define MU_LSR 0x3F215054 // MU_LSR register

void putc(int data);

void uart_puts(char *str);

char getc();