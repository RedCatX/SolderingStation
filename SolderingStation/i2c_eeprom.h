/*
 * i2c_eeprom.h
 *
 * Created: 19.03.2024 22:01:53
 *  Author: RedCAT
 */ 


#ifndef I2C_EEPROM_H_
#define I2C_EEPROM_H_

void i2c_eeprom_init();
uint8_t i2c_eeprom_read(uint16_t address, void* buf, uint8_t size);
uint8_t i2c_eeprom_write(uint16_t address, void* buf, uint8_t size);



#endif /* I2C_EEPROM_H_ */