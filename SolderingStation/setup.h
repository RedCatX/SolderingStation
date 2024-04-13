/*
 * setup.h
 *
 * Created: 13.03.2024 20:37:42
 *  Author: RedCAT
 */ 


#ifndef SETUP_H_
#define SETUP_H_

#include <avr/io.h>

// Encoder
#define ENCODER_PORT        PORTC
#define ENCODER_PINS        PINC
#define ENCODER_DDR         DDRC
#define ENCODER_PCIE        PCIE1
#define ENCODER_PCMSK       PCMSK1
#define ENCODER_MASK        ((1 << PCINT8) | (1 << PCINT9) | (1 << PCINT10))
#define ENCODER_LEFT_PIN    2
#define ENCODER_RIGHT_PIN   1
#define ENCODER_BUTTON_PIN  0

// I2C Display
#define DISPLAY_PORT        PORTD
#define DISPLAY_DDR         DDRD
#define DISPLAY_SDA         2
#define DISPLAY_SCL         3

// I2C EEPROM

// CPU frequency
#define F_CPU 16000000UL

// Temperature control
#define TEMP_SET_MIN 100
#define TEMP_SET_MAX 450
#define TEMP_SET_STEP 10

#endif /* SETUP_H_ */