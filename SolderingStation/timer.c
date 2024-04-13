/*
 * timer.c
 *
 * Created: 10.03.2024 8:16:15
 *  Author: RedCAT
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>
#include "timer.h"
#include "model.h"

typedef struct Timer 
{
    uint32_t interval;
    uint32_t counter;
    timer_function_t* ontimer;
} timer_t;

volatile timer_t timers[TIMERS_MAX_COUNT];
uint8_t timers_count;

ISR(TIMER0_COMPA_vect)
{
    uint8_t i;
    for (i = 0; i < TIMERS_MAX_COUNT; i++)
    {
        if (timers[i].interval > 0 && timers[i].ontimer)
        {
            timers[i].counter++;
            if (timers[i].counter == timers[i].interval)
            {
                timers[i].counter = 0;
                timers[i].ontimer();
            }
        }
        else
            break;
    }
}

void timer_init()
{
    uint8_t i;
    cli();
    timers_count = 0;
    for (i = 0; i < TIMERS_MAX_COUNT; i++)
    {
        timers[i].interval = 0;
        timers[i].counter = 0;
        timers[i].ontimer = NULL;
    }
    TCCR0A = 0;
    TCCR0B = 0;
    OCR0A = 250;
    TCCR0B |= ((1 << WGM12) | (1 << CS10) | (1 << CS11));
    TIMSK0 |= (1 << OCIE1A);
    sei();
}

void attach_timer_func(timer_function_t* func, uint32_t interval_mills)
{
    uint8_t i;
    cli();
    if (timers_count < TIMERS_MAX_COUNT) 
    {
        timers[timers_count].counter = 0;
        timers[timers_count].interval = interval_mills;
        timers[timers_count].ontimer = func;
        timers_count++;
    }    
    sei();
}

void detach_timer_func(timer_function_t* func)
{
    uint8_t i, j;
    cli();
    for (i = 0; i < timers_count; i++)
    {
        if (timers[i].ontimer == func)
        {
            timers[i].interval = 0;
            timers[i].counter = 0;
            timers[i].ontimer = NULL;
            
            for (j = i+1; j < timers_count; j++)
            {
                timers[j-1].interval = timers[j].interval;
                timers[j-1].counter = timers[j].counter;
                timers[j-1].ontimer = timers[j].ontimer;
            }
            
            timers_count--;
            break;
        }
    }
    sei();
}
