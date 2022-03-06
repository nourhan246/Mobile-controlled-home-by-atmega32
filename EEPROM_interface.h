#ifndef EEPROM_H
#define EEPROM_H

void EEPROM_Init(void);
unsigned char EEPROM_WriteByte(unsigned int addr, unsigned char data);
unsigned char EEPROM_ReadByte(unsigned int addr, unsigned char chs[],u8 num);

#endif
