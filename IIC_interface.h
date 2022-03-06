#ifndef I2C_H
#define I2C_H

#define TW_MT_ARB_LOST   0x38
#define TW_MR_ARB_LOST   0x38
#define TW_START         0x08
#define TW_REP_START     0x10
#define TW_MT_SLA_ACK    0x18
#define TW_MT_DATA_ACK   0x28
#define TW_MR_DATA_NOT_ACK  0x58
#define TW_MR_SLA_NOT_ACK   0x48
#define TW_MT_SLA_NOT_ACK   0x20
#define TW_MT_DATA_NOT_ACK  0x30
#define TW_MR_DATA_ACK   0x50
#define TW_MR_SLA_ACK    0x40

void I2C_Init(void);
void TWIStart(void);
void TWIStop(void);
void TWIWrite(unsigned char data);
unsigned char TWIReadACK(void);
unsigned char TWIReadNACK(void);
unsigned char TWIGetStatus(void);

#endif
