#include <avr/io.h>
#include "IIC_interface.h"
//#include "DIO_Interface.h"

void EEPROM_Init(void)
{
  I2C_Init();
}

unsigned char EEPROM_WriteByte(unsigned int addr, unsigned char data)
{
  unsigned char state = 0;
  unsigned char _3MSBAddr = 0;

  // Start TWI
  TWIStart();
  // Get State
  state = TWIGetStatus();
  // Check if TWI Start
  if (state != TW_START)
  {
    //  PORTA |= 0x02;
    return 0;
  }
  // Send Slave Address -> For EEPROM 24cXX
  // The Slave Address of Chip is 0b1010, so have Three bits free
  // We can take a part from 11 bit address and send it with Device Add
  // Send 3 MSBs From Address "As Device Address"
  // Set Action To Write -> 0
  _3MSBAddr = ((unsigned char) ((addr & 0x0700) >> 7));
  // TWIWrite(0xA0|_3MSBAddr);
  TWIWrite(0xA0);
  // Get Status
  state = TWIGetStatus();
  // Check if it is TW_MT_SLA_ACK
  if (state != TW_MT_SLA_ACK)
  {
   // PORTA |= 0x02;
    return 0;
  }

  // Write the Rest of Location Address(8 Bits)
  TWIWrite((unsigned char) addr);

  // Get State
  state = TWIGetStatus();

  // check if it is TW_MT_DATA_ACK
  if (state != TW_MT_DATA_ACK)
  {
//    PORTA |= 0x02;
    return 0;
  }

  // Send Data
  TWIWrite(data);

  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MT_DATA_ACK
  if (state != TW_MT_DATA_ACK)
  {
    //   PORTA |= 0x02;
    return 0;
  }

  // TWI Stop
  TWIStop();
  // Return Done
  return 1;
}

unsigned char EEPROM_ReadByte(unsigned int addr, unsigned char chs[],unsigned int num)
{
  unsigned char state = 0;
  unsigned char _3MSBAddr = 0;

  // Start TWI
  TWIStart();

  // Get State
  state = TWIGetStatus();

  // Check if TWI Start
  if (state != TW_START)
    return 0;

  // Send Slave Address -> For EEPROM 24cXX
  // The Slave Address of Chip is 0b1010, so have Three bits free
  // We can take a part from 11 bit address and send it with Device Add
  // Send 3 MSBs From Address "As Device Address"
  // Set Action to write -> 0
  _3MSBAddr = ((unsigned char) ((addr & 0x0700) >> 7));
  // TWIWrite(0xA0|_3MSBAddr);
  TWIWrite(0xA0);

  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MT_SLA_ACK
  if (state != TW_MT_SLA_ACK)
    return 0;

  // Write the Rest of Location Address(8 Bits)
  TWIWrite((unsigned char) addr);

  // Get State
  state = TWIGetStatus();

  // check if it is TW_MT_DATA_ACK
  if (state != TW_MT_DATA_ACK)
    return 0;

  // Now The Master Will Be Master Reciever

  // Now we need to Send Start Bit Again
  // Start TWI
  TWIStart();

  // Get State
  state = TWIGetStatus();

  // Check if TW_REP_START
  if (state != TW_REP_START)
    return 0;

  // Send Slave Address -> For EEPROM 24cXX
  // The Slave Address of Chip is 0b1010, so have Three bits free
  // We can take a part from 11 bit address and send it with Device Add
  // Send 3 MSBs From Address "As Device Address"
  // Set Action to Read -> 1
  _3MSBAddr = ((unsigned char) ((addr & 0x0700) >> 7));
//    TWIWrite(0xA0|_3MSBAddr|1);
  TWIWrite(0xA0 | 1);
  // Get Status
  state = TWIGetStatus();

  // Check if it is TW_MR_SLA_ACK
  if (state != TW_MR_SLA_ACK)
    return 0;

  for(int i=0;i<num;i++)
  {
	  // Edit here....
	  if(i==num-1)
	  {
		 chs[i]=TWIReadNACK();
		state = TWIGetStatus();
		if (state != TW_MR_DATA_NOT_ACK)
		  {
			//PORTA |= 0x04;
			return 0;
		  }
	  }

	  else
	  {
			chs[i] = TWIReadACK();
		  state = TWIGetStatus();

		  if (state != TW_MR_DATA_ACK)
		  {
			//PORTA |= 0x04;
			return 0;
		  }
	  }
	  // TWI Stop
  }

  TWIStop();

  // Return Done
  return 1;
}
