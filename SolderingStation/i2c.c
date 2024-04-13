/*
 * i2c.c
 *
 *  Author: RedCAT
 */

#include <avr/io.h> 
#include <avr/interrupt.h>

#include "i2c.h" 

#define i2c_PORT    PORTC
#define i2c_DDR     DDRC
#define i2c_SCL     5
#define i2c_SDA     4

char* Buffer;
volatile bool I2CBusy = false;
uint16_t BufferSize;
uint16_t BufIndex = 0;
uint8_t ControlByte = 0;
uint8_t LastErr = I2C_NO_ERROR;

void i2c_init()
{
    i2c_PORT |= 1 << i2c_SCL | 1 << i2c_SDA;
    i2c_DDR &= ~(1 << i2c_SCL | 1 << i2c_SDA);

    TWBR = 0x80;
    TWSR = 0x00;
    sei();
}

bool i2c_busy()
{
    return I2CBusy;
}

uint8_t i2c_last_error()
{
    return LastErr;
}

void i2c_read(uint8_t address, char* buffer, uint16_t length)
{
    
}

void i2c_write(uint8_t address, char* buffer, uint16_t length)
{        
    ControlByte = address & 0xFE;
    Buffer = buffer;
    BufferSize = length;
    BufIndex = 0;
    LastErr = I2C_NO_ERROR;
    
    TWCR = 1 << TWSTA 
         | 0 << TWSTO
         | 1 << TWINT
         | 0 << TWEA
         | 1 << TWEN
         | 1 << TWIE;
         
    while ((TWCR & (1 << TWINT)) == 0)
        ;
}

ISR(TWI_vect)
{
    switch (TWSR & 0xF8) 
    {
        case 0x00: // Bus Fail
            LastErr = I2C_BUS_FAIL;
            I2CBusy = false;
            TWCR = 0 << TWSTA // Start
                 | 1 << TWSTO // Stop
                 | 1 << TWINT // Interrupt
                 | 0 << TWEA  // Slave
                 | 1 << TWEN  // TWI On
                 | 1 << TWIE; // Enable Interrupt
            break;
            
        case 0x08: // Start 
        case 0x10: // ReStart
            I2CBusy = true;
            TWDR = ControlByte;
            TWCR = 0 << TWSTA
                 | 0 << TWSTO
                 | 1 << TWINT
                 | 0 << TWEA
                 | 1 << TWEN
                 | 1 << TWIE;
            break;
            
        case 0x18: // SLA+W+ACK
            TWDR = Buffer[BufIndex];
            BufIndex++;
            TWCR = 0 << TWSTA
                 | 0 << TWSTO
                 | 1 << TWINT
                 | 0 << TWEA
                 | 1 << TWEN
                 | 1 << TWIE;
            break;
        
        case 0x20: // SLA+W+NACK
            LastErr = I2C_DEV_NO_ANSWER;
            I2CBusy = false;
            TWCR = 0 << TWSTA
                 | 1 << TWSTO
                 | 1 << TWINT
                 | 0 << TWEA
                 | 1 << TWEN
                 | 1 << TWIE;
            break;
            
        case 0x28: // Byte+ACK
            if (BufIndex < BufferSize) {
                TWDR = Buffer[BufIndex];
                BufIndex++;
                TWCR = 0 << TWSTA
                     | 0 << TWSTO
                     | 1 << TWINT
                     | 0 << TWEA
                     | 1 << TWEN
                     | 1 << TWIE;
            }
            else {
                I2CBusy = false;
                TWCR = 0 << TWSTA
                     | 1 << TWSTO
                     | 0 << TWINT
                     | 0 << TWEA
                     | 1 << TWEN
                     | 1 << TWIE;
            }
            break;
        
        // Byte+NACK     
        case 0x30:
            LastErr = I2C_END_TRANSMISSION;
            I2CBusy = false;
            TWCR = 0 << TWSTA
                 | 1 << TWSTO
                 | 1 << TWINT
                 | 0 << TWEA
                 | 1 << TWEN
                 | 1 << TWIE;
            break;
            
        // Collision
        case 0x38:
            LastErr = I2C_LOW_PRIORITY;
            BufIndex = 0;
            TWCR = 1 << TWSTA
                 | 0 << TWSTO
                 | 1 << TWINT
                 | 0 << TWEA
                 | 1 << TWEN
                 | 1 << TWIE;
            break; 
            
        // SLA+R+ACK
        case 0x40:
            break;
            
        // SLA+R+NACK   
        case 0x48:
            I2CBusy = false;
            break;
        
        // Receive Byte   
        case 0x50:
            break;
        
        // Receive Byte+NACK    
        case 0x58:
            I2CBusy = false; 
            break;             
    }
}
