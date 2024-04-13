/*
 * model.c
 *
 * Created: 18.11.2021 17:02:04
 *  Author: RedCAT
 */ 

#include "model.h"
#include "setup.h"
#include "i2c_eeprom.h"
#include <avr/sfr_defs.h>

uint16_t temp = 310;
bool boost = false;
volatile bool beep = false;

void model_init()
{
    DDRB |= _BV(DDB5);
    i2c_eeprom_init();
    i2c_eeprom_read(2, &temp, 2);
}

void set_temperature(uint16_t value)
{
    if (temp != value)
    {
        temp = value;
        i2c_eeprom_write(2, &temp, 2);
    }
}

uint16_t get_temperature()
{
    return temp;
}

uint16_t get_measured_temp()
{
    return 298;
}

void boost_mode()
{
    boost = !boost;
}

bool get_boost_mode()
{
    return boost;
}

void change_signal_state()
{
    if (beep = !beep)
        PORTB |= _BV(PORTB5);
    else
        PORTB &= ~(_BV(PORTB5));
}

void* get_signal_state()
{
    return (void*) beep;
}
