/*
 * i2c_eeprom.c
 *
 * Created: 19.03.2024 22:02:09
 *  Author: RedCAT
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "i2c_eeprom.h"
#include "setup.h"

#define F_EEPROM_SPEED 200UL

void i2c_eeprom_init()
{
    TWBR = (((F_CPU/F_EEPROM_SPEED) - 16) / 2);
}

void twi_start()
{
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while ( !(TWCR&(1<<TWINT)) )
        ;
}

void twi_stop()
{
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

void twi_send_byte(uint8_t b)
{
    TWDR = b;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while ( !(TWCR & (1<<TWINT)) )
        ;
}

uint8_t i2c_eeprom_read(uint16_t address, void* buf, uint8_t size)
{
     uint8_t i = 0, 
             bytes = 0;
     // I2C start
     twi_start();
     // Send device address, block selects bits and R/W bit (0 - Write)
     twi_send_byte(0xA0 | (((uint8_t)(address / 256)) << 1));
     // Send word address
     twi_send_byte((uint8_t)(address % 256));
     // I2C start
     twi_start();
     // Send device address, block selects bits and R/W bit (1 - Read)
     twi_send_byte(0xA1 | (((uint8_t)(address / 256)) << 1));
     // Recieve data
     for (i = 0; i < size - 1; i++)
     {
         TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
         while ( !(TWCR & (1<<TWINT)) )
            ;
         if ((TWSR & 0xF8) != 0x50) 
            break;
         *((uint8_t*)(buf+i)) = TWDR;
         bytes++;
     }
     // Recieve last byte
     TWCR = (1<<TWINT) | (1<<TWEN);
     while ( !(TWCR & (1<<TWINT)) )
        ;
     if ((TWSR & 0xF8) == 0x58)
     {
         *((uint8_t*)(buf+i)) = TWDR; 
         bytes++;
     }         
     // I2C stop
     twi_stop();
     return bytes;
}

uint8_t i2c_eeprom_write(uint16_t address, void* buf, uint8_t size)
{
    uint8_t i, bytes = 0;
    // I2C start
    twi_start();
    // Send device address, block selects bits and R/W bit (0 - Write)
    twi_send_byte(0xA0 | (((uint8_t)(address / 256)) << 1));
    // Send word address
    twi_send_byte((uint8_t)(address % 256));
    // Send data
    for (i = 0; i < size; i++)
    {
        twi_send_byte(*((uint8_t*)(buf)));
        if ((TWSR & 0xF8) != 0x28)
            break;
            
        bytes++;
        buf++;
    }
    // I2C stop
    twi_stop();
    return bytes;
}

