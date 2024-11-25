// delays.c

#include "delays.h"

unsigned long *timer_count_register = 0x3f003004;

// returns pointer to the timer count register
// timer count register stores total microseconds since boot
unsigned long get_timer_count() {
  // unsigned long *timer_count_register = 0x3f003004;
  return *timer_count_register;
}

// delays os/kernel_main by time = microseconds
void wait_cycles(unsigned long cycles) {
  unsigned long tmp = get_timer_count();
  unsigned long end = tmp + cycles;
  while (tmp < end) {
    tmp = get_timer_count();
  }
}

// delays os/kernel_main by time = milliseconds
void wait_msec(unsigned long ms) {
  wait_cycles(ms * 1000);
}

// delay os/kernel_main by time = seconds
void wait_seconds(unsigned long secs) {
  wait_msec(secs * 1000);
}