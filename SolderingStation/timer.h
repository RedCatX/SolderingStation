/*
 * timer.h
 *
 * Created: 10.03.2024 8:15:50
 *  Author: RedCAT
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

#define TIMERS_MAX_COUNT 4

typedef void (timer_function_t)(void);

void timer_init();
void attach_timer_func(timer_function_t* func, uint32_t interval_mills);
void detach_timer_func(timer_function_t* func);

#endif /* TIMER_H_ */