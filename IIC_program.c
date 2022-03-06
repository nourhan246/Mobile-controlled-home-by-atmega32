#include <avr/io.h>
//#include "IIC.h"

void I2C_Init(void)
{
  // TWI initialization
  // Bit Rate: 400.000 kHz
  TWBR = 72;
  // Two Wire Bus Slave Address: 0x1
  // General Call Recognition: Off
  TWAR = 0x02;
  // Generate Acknowledge Pulse: On
  // TWI Interrupt: Off
  TWCR = 0x44;
  TWSR = 0x00;
  TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));
}

void TWIStart(void)
{
  // Send Start Condition
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
}

void TWIStop(void)
{
  // Send Stop Condition
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWIWrite(unsigned char data)
{
  // Put data On TWI Register
  TWDR = data;
  // Send Data
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
}

unsigned char TWIReadACK(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    //enable Ack
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
  // Read Data
  return TWDR;
}

unsigned char TWIReadNACK(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
  // Read Data
  return TWDR;
}

unsigned char TWIGetStatus(void)
{
  unsigned char status;
  status = TWSR & 0xF8;
  return status;
}
