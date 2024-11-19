// serial.c

#include "serial.h"
#include "delays.h"

// writes character to serial port
void putc(int data) {
    int *mu_io = (int *)MU_IO; // MU_IO register
    *mu_io = data;
}

// writes string to serial port
void uart_puts(char *str) {
    esp_printf(putc, str);
}

// reads character from serial port
char getc() {
    int *mu_io = (int *)MU_IO; // MU_IO register
    while ((*mu_io & 0x01) == 0) {
        // wait for serial data to arrive
        // wait_msec(500);
        // esp_printf(putc, "Waiting for serial data...\n");
    }
    // esp_printf(putc, "getc: %c\n", (char)(*mu_io & 0xFF));
    return (char)(*mu_io & 0xFF);
}

