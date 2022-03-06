
#ifndef LCD_H_
#define LCD_H_



void LCD_vidInit(void);

void LCD_vidSendCommand(u8 u8CmdCpy);


void LCD_vidWriteCharctr(u8 u8DataCpy);

void LCD_vidWriteNumber(u32 x);
void LCD_clearscreen(void);

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);

void LCD_vidDrawCharctr(u8 x);
void LCD_vidSetPosition(u8 row,u8 col);
void Gotoxy (u8 Y,u8 X);
void LCD_vidWriteExtraChar (u8 Y,u8 X);

#endif /* LCD_H_ */
