// debug.c

#include "debug.h"
#include "serial.h"

void break_point() {
  esp_printf(putc, "Breakpoint\n");
};