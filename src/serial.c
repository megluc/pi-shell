// serial.c

#include "serial.h"
#include "delays.h"

// writes character to serial port
void putc(int data) {
    int *mu_io = (int *)MU_IO; // MU_IO register
    *mu_io = data;
}

// writes string to serial port, wrapper for esp_printf(putc)
void uart_puts(char *str) {
    esp_printf(putc, str);
}

// reads character from serial port
char getc() {
    int *mu_io = (int *)MU_IO; // MU_IO register
    int *mu_lsr = (int *)MU_LSR; // MU_LSR register

    while (!(*mu_lsr & 0x01)) {}// waits for line status flag

    return (char)(*mu_io & 0xFF); // returns character
}

