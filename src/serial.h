// serial.h

#define MU_IO 0x3F215040 // MU_IO register

void putc(int data);

void uart_puts(char *str);

char getc();