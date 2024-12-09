// rprintf.h

#ifndef RPRINTF_H
#define RPRINTF_H

#include <stdarg.h>  // For variable argument handling

// rprintf function prototype
void rprintf(const char *fmt, ...);

// Utility function to convert integers to strings (itoa)
void itoa(int num, char *str, int base);

#endif // RPRINTF_H
