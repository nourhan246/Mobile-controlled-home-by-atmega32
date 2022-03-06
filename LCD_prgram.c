
//#define F_CPU 16000000
//#include "types.h"
#include "STD_TYPES.h"
#include "avr/delay.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"


void LCD_vidInit(void)
{


	DIO_VidSetPortDirection (PORT_Data,255) ;
	DIO_VidSetPinDirection(PORT_Control, RS, HIGH);
	DIO_VidSetPinDirection(PORT_Control, RW, HIGH);
	DIO_VidSetPinDirection(PORT_Control, E, HIGH);


	_delay_ms(30);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(15);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);


	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);

}



void LCD_vidSendCommand(u8 u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_VidSetPinValue(PORT_Control, RS, LOW);

	/* Set R/W to LOW */
	DIO_VidSetPinValue(PORT_Control, RW, LOW);

	/* Set E to HIGH  */
	DIO_VidSetPinValue(PORT_Control, E, HIGH);

	/* Load Command on Data bus */
	DIO_VidSetPortValue(PORT_Data, u8CmdCpy);

	/* Set E to LOW */
	DIO_VidSetPinValue(PORT_Control, E, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	//DIO_VidSetPinValue(PORT_Control, E, HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}


void LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* Set RS to HIG */
	DIO_VidSetPinValue(PORT_Control, RS, HIGH);

	/* Set R/W to LOW */
	DIO_VidSetPinValue(PORT_Control, RW, LOW);

	/* Set E to HIGH */
	DIO_VidSetPinValue(PORT_Control, E, HIGH);

	/* Load Command on Data bus */
	DIO_VidSetPortValue(PORT_Data, u8DataCpy);

	/* Set E to LOW */
	DIO_VidSetPinValue(PORT_Control, E, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	//DIO_VidSetPinValue(PORT_Control, E, HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

void LCD_vidWriteNumber(u32 x){
	if(x==0){
		LCD_vidWriteCharctr('0');
		return ;
	}
	char arr[20];
	int cnt=-1;
	while(x>0){
		arr[++cnt]=x%10+'0';
		x/=10;
	}
	while(cnt>=0){
		LCD_vidWriteCharctr(arr[cnt--]);

	}
}

void LCD_clearscreen(void)
{
	LCD_vidSendCommand(0x01); // clear the screen
}

void LCD_vidDrawCharctr(u8 x){

	  //  0
		LCD_vidSendCommand(64);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00001110);
		LCD_vidWriteCharctr(0b00010101);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00001010);
		LCD_vidWriteCharctr(0b00010001);
		LCD_vidWriteCharctr(0b00010001);
       //   1
		LCD_vidWriteCharctr(0b00000011);
		LCD_vidWriteCharctr(0b00000110);
		LCD_vidWriteCharctr(0b00011100);
		LCD_vidWriteCharctr(0b00001100);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);


         /// 2
		LCD_vidWriteCharctr(0b00100100);
		LCD_vidWriteCharctr(0b00100100);
		LCD_vidWriteCharctr(0b00001111);
		LCD_vidWriteCharctr(0b00010100);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00001010);
		LCD_vidWriteCharctr(0b00010001);
		LCD_vidWriteCharctr(0b00010001);
        /// 3
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00011110);
		LCD_vidWriteCharctr(0b00000101);
		LCD_vidWriteCharctr(0b00000100);
		LCD_vidWriteCharctr(0b00001010);
		LCD_vidWriteCharctr(0b00010001);
		LCD_vidWriteCharctr(0b00010001);
       //  4
		LCD_vidWriteCharctr(0b00011000);
		LCD_vidWriteCharctr(0b00001100);
		LCD_vidWriteCharctr(0b00000111);
		LCD_vidWriteCharctr(0b00000110);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);
		LCD_vidWriteCharctr(0b00000000);

}

void LCD_vidSetPosition(u8 row,u8 col){
	if(row==0)
		LCD_vidSendCommand(128+col);
	else
		LCD_vidSendCommand(128+64+col);
}

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{

	//	/* Local loop index */
	//	u8 u8Index = 0;
	u8 iteration=0;
	//	while (pu8StringCpy[u8Index] != '\0')
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

		//		/* Increment local loop index */
		//		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}


void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
		switch(Y)
		{
		case 1:
			LCD_vidSendCommand(X+127);
			break;
		case 2:
			LCD_vidSendCommand(X+191);
			break;
		default:
			break;
		}
	}
}


void LCD_vidWriteExtraChar (u8 Y,u8 X)
{
	u8 iteration1,iteration2;

	/*DDRAM-->CGRAM*/
	LCD_vidSendCommand(64);
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteCharctr(ExtraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand(128);
	Gotoxy(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr(iteration2);

		_delay_ms(5);
	}
}
