// rprintf.c

#include "rprintf.h"   // Header file for rprintf declarations
#include "serial.h"    // Assume your serial functions are in this file

// Basic implementation of rprintf
void rprintf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // Loop through the string and print each character
    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            if (*fmt == 's') {  // Handle string
                char *str = va_arg(args, char*);
                while (*str) {
                    putc(*str);  // Send character via serial or other output
                    str++;
                }
            } else if (*fmt == 'd') {  // Handle integer
                int num = va_arg(args, int);
                char buf[20];  // A buffer for the number (sufficient for int)
                itoa(num, buf, 10);  // Convert the integer to string
                char *p = buf;
                while (*p) {
                    putc(*p);
                    p++;
                }
            } else if (*fmt == 'c') {  // Handle single character
                char c = (char) va_arg(args, int);  // Characters are promoted to int
                putc(c);
            }
        } else {
            putc(*fmt);  // Just print the character
        }
        fmt++;
    }

    va_end(args);
}

// Function to convert integer to string (itoa)
void itoa(int num, char *str, int base) {
    int i = 0;
    int isNegative = 0;

    // Handle 0 explicitly, otherwise empty string is printed
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Handle negative numbers only if base is 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Append negative sign for negative numbers
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
