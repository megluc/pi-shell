// delays.c

#include "delays.h"

unsigned long get_timer_count() {
  unsigned long *timer_count_register = TIMER_COUNT_REGISTER;
  return *timer_count_register;
}

// delays OS by num cycles, where each cycle is 1 microsecond
void wait_cycles(unsigned long cycles) {
  unsigned long start = get_timer_count();
  unsigned long end = start + cycles;
  while (get_timer_count() < end) {
    // do nothing
  }
}

// delays OS by num milliseconds
void wait_msec(unsigned long ms) {
  wait_cycles(ms * 1000);
}

// delay os/kernel_main by time = seconds
void wait_seconds(unsigned long secs) {
  wait_msec(secs * 1000);
}