/*
 * model.h
 *
 * Created: 18.11.2021 17:01:48
 *  Author: RedCAT
 */ 


#ifndef MODEL_H_
#define MODEL_H_

#include <stdint.h>
#include <stdbool.h>

void model_init();

// Temperature control
void set_temperature(uint16_t value);
uint16_t get_temperature();
uint16_t get_measured_temp();
void boost_mode();
bool get_boost_mode();

// Beep
void change_signal_state();
void* get_signal_state();

#endif /* MODEL_H_ */