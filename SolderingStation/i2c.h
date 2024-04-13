/*
 * i2c.h
 *
 * Created: 30.11.2019 2:05:57
 *  Author: RedCAT
 */ 


#ifndef I2C_H_
#define I2C_H_

#include <stdbool.h>
#include <stdint.h>

#define I2C_NO_ERROR          0
#define I2C_DEV_NO_ANSWER     1
#define I2C_LOW_PRIORITY      3
#define I2C_END_TRANSMISSION  4
#define I2C_BUS_FAIL          5

void i2c_init();
bool i2c_busy();
uint8_t i2c_last_error();
void i2c_read(uint8_t address, char* buffer, uint16_t length);
void i2c_write(uint8_t address, char* buffer, uint16_t length);


#endif /* I2C_H_ */