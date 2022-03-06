#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "main_config.h"
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"
#include "menu.h"
#include "EEPROM_interface.h"

int main(void)
{

	UART_Init();
	EEPROM_Init();
	DIO_VidSetPinDirection(3,0,0);
	DIO_VidSetPinDirection(3,1,1);

	//DC Motor.....
	DIO_VidSetPinDirection(1,5,1);
	DIO_VidSetPinDirection(1,6,1);

	//Red Led.....
	DIO_VidSetPinDirection(1,3,1);
	//green led
	DIO_VidSetPinDirection(1,4,1);

	//LCD initialize.....
	LCD_vidInit();

	/* Printing Welcome screen */
	LCD_vidWriteString("Welcome to smart",16);
	LCD_vidSetPosition(1,0);
	LCD_vidWriteString("home system",11);
	_delay_ms(1000);
	LCD_clearscreen();


	 u8 Allow_to_enter=0;
	 Allow_to_enter= Main_Screen();

      if(Allow_to_enter)
      {
	while (1)//The start of the periodic code
	{
		LCD_vidWriteString("1 for Open Door",15);
		LCD_vidSetPosition(1,0);
		LCD_vidWriteString("0 for close door :",16);
		u8 x=UART_GetChar();
		LCD_vidWriteCharctr(x);
		_delay_ms(1000);
		LCD_clearscreen();
		if(x=='1')
			OpenDoor();
		else if(x=='0')
			CloseDoor();
	}
      }



}//end of main function
