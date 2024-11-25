// delays.h

#define TIMER_COUNT_REGISTER 0x3f003004

unsigned long get_timer_count();

void wait_cycles(unsigned long time);

void wait_msec(unsigned long time);

void wait_seconds(unsigned long time);