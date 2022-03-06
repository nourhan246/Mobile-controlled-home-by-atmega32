

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define PORT_Data PORTA
#define PORT_Control PORTB

#define E PIN0
#define RS PIN1
#define RW PIN2

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

const u8  ExtraChar[]=
{
		0x02, 0x00, 0x17, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char0
		0x00, 0x00, 0x00, 0x04, 0x07, 0x04, 0x0C, 0x18, //Char1
		0x04, 0x0A, 0x00, 0x15, 0x1F, 0x00, 0x00, 0x00, //Char2
		0x06, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, //Char3
		0x00, 0x00, 0x0E, 0x0A, 0x0E, 0x02, 0x04, 0x08, //Char4
		0x00, 0x00, 0x00, 0x00, 0x07, 0x04, 0x0C, 0x18, //Char5
		0x00, 0x00, 0x04, 0x0A, 0x1B, 0x0A, 0x04, 0x00, //Char6
		0x00, 0x00, 0x07, 0x04, 0x1F, 0x00, 0x00, 0x00, //Char7
};


#endif 