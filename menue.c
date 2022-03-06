/*
 * menue.c
 *
 *  Created on: Mar 25, 2021
 *      Author: NourhanMahmoud
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "main_config.h"
#include <avr/io.h>
#include "avr/delay.h"
#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"
#include "EEPROM_interface.h"


void OpenDoor(void)
{
	DIO_VidSetPinValue(1,5,1);
	DIO_VidSetPinValue(1,6,0);
	_delay_ms(500);

	DIO_VidSetPinValue(1,5,0);
    DIO_VidSetPinValue(1,6,0);
}

void CloseDoor(void)
{
	DIO_VidSetPinValue(1,5,0);
	DIO_VidSetPinValue(1,6,1);

	_delay_ms(500);

	DIO_VidSetPinValue(1,5,0);
    DIO_VidSetPinValue(1,6,0);
}

void LedRedOn(void)
{
	DIO_VidSetPinValue(1,3,1);
}

void LedRedOff(void)
{
	DIO_VidSetPinValue(1,3,0);
}

void LedGreenOn(void)
{
	DIO_VidSetPinValue(1,4,1);
}

void LedGreenOff(void)
{
	DIO_VidSetPinValue(1,4,0);
}

void BuzzerOn(void)
{
	DIO_VidSetPinDirection(1,7,1);
	DIO_VidSetPinValue(1,7,1);
}
void BuzzerOff(void)
{
	DIO_VidSetPinDirection(1,7,0);
	DIO_VidSetPinValue(1,7,0);
}

u8 Main_Screen(void)
{
	UART_Init();
	EEPROM_Init();
	LCD_vidInit();
	// main function
	int Allow_to_enter=0;

	    u8 chs[15];


		 // start address to write in is 28 and writing in 16 addresses


	///////////////////////////////////////////////////////////////////////////////
		LCD_vidWriteString("0 for Register",14);
		LCD_vidSetPosition(1,0);
		LCD_vidWriteString("1 for Login :",13);
		//_delay_ms(1000);



		u8 DATA = NO_DATA ;
		while (DATA == NO_DATA)
		{
			DATA = UART_GetChar();
		}
		LCD_vidWriteCharctr(DATA);
	    _delay_ms(200);
	     LCD_clearscreen();

	      if(DATA=='0'){
	    	  u16 i;
	    	  EEPROM_ReadByte(number_of_users,chs,1);
	    	  _delay_ms(100);
	               i=chs[0];
	    	  if(i==0xff)i=0x00;
	    	  i+=0x01;
	    	  EEPROM_WriteByte(number_of_users,i);
	    		_delay_ms(100);
	    	  u8  current_position=i*ROW;
	    	  LCD_vidWriteString("Set user name :",15);
	    	  LCD_vidSetPosition(1,0);
	    	  		//LCD_clearscreen();
	    	  		u16 name_counter=0;
	    	  		u16 name[NAME_SIZE]={0xff};
	    	  		while (name_counter<NAME_SIZE)
	    	  	    	{
	    	  				DATA = NO_DATA ;
	    	  				while (DATA == NO_DATA)
	    	  					{
	    	  						DATA = UART_GetChar();
	    	  					}
	                       if(DATA=='@')break;
	    	  				name[name_counter]=DATA;
	    	  				LCD_vidWriteCharctr(DATA);
	    	  				_delay_ms(50);
	    	  				u16 cur_poz=current_position+name_counter;
	    	  				EEPROM_WriteByte(cur_poz,DATA);
	    	  				_delay_ms(100);
	    	  				name_counter++;

	    	  	    	}
	    	  			LCD_clearscreen();
	    	  			LCD_vidWriteString("name is saved",13);

	    	  	       	_delay_ms(100);
	    	  	       	LCD_clearscreen();

	                 current_position=(i*ROW+NAME_SIZE);
	                 LCD_vidWriteString("Set user pass :",15);
	                 LCD_vidSetPosition(1,0);
	    	  			u8 pass_counter=0;
	    	  			u8 pass[PASS_SIZE]={0xff};
	    	  			while (pass_counter<PASS_SIZE)
	    	  			{
	    	  				DATA = NO_DATA ;
	    	  				while (DATA == NO_DATA)
	    	  					{
	    	  						DATA = UART_GetChar();
	    	  					}

	    	  				pass[pass_counter]=DATA;

	    	  				LCD_vidWriteCharctr(DATA);
	    	  				_delay_ms(CHARACTER_PREVIEW_TIME);
	    	  				LCD_vidSetPosition(1,pass_counter);
	    	  				LCD_vidWriteCharctr(PASSWORD_SYMBOL);
	    	  				_delay_ms(50);
	    	  				u16 cur_poz=current_position+pass_counter;
	    	  				EEPROM_WriteByte(cur_poz,DATA);
	    	  				_delay_ms(100);
	    	  				pass_counter++;
	    	  			}
						LCD_clearscreen();
						LCD_vidWriteString("pass is saved",13);
						_delay_ms(1000);
						LCD_clearscreen();
						LCD_vidWriteString("Register done",13);
						_delay_ms(1000);
						LCD_clearscreen();
						return Main_Screen();

	    	        }
	      else{

	    	  LCD_clearscreen();
	    	  u8 cnt=0, pass_tries_count=0;

	    	  u8 Num_of_users=0;

	    	   EEPROM_ReadByte(0x01,chs,1);
	    	   Num_of_users=chs[0];
	    		_delay_ms(100);
	    	  if(Num_of_users==0xff){
	    	    LCD_vidWriteString("NO Register yet",15);
	    	      	     return 0;
	    	      }

	        while(cnt++<TRIES_ALLOWED){
	    	  u16 name_counter=0;
	    	  		u16 name[NAME_SIZE]={0xff};
	    	  		u16 stored_name[NAME_SIZE]={0xff};
	    	  		for(u8 i=0;i<NAME_SIZE;i++)name[i]=0xff;
	    	  		DATA = NO_DATA;
	    	  		LCD_clearscreen();
	    	  		LCD_vidWriteString("Enter Name:",11);
	    	  		LCD_vidSetPosition(1,0);
	    	  		_delay_ms(200);
	    	  		name_counter=0;

	    	  		while (name_counter<NAME_SIZE)
	    	  		{
	    	  			DATA = NO_DATA ;
	    	  			while (DATA == NO_DATA)
	    	  				{
	    	  					DATA = UART_GetChar();
	    	  				}
	    	  		  if(DATA=='@')break;
	    	  			name[name_counter]=DATA;
	    	  			LCD_vidWriteCharctr(DATA);

	    	  			_delay_ms(50);
	    	  			name_counter++;
	    	  		}


	    	  		u8 pass_counter=0;
	    	  		u8 pass[PASS_SIZE]={0xff};
	    	  		u8 stored_pass[PASS_SIZE]={0xff};

	    	  		DATA = NO_DATA;
	    	  		LCD_clearscreen();
	    	  		LCD_vidWriteString("Enter Pass:",11);
	    	  		LCD_vidSetPosition(1,0);
	    	  		_delay_ms(200);
	    	  		pass_counter=0;

	    	  		while(pass_counter<PASS_SIZE)
	    	  		{
	    	  			DATA = NO_DATA;
	    	  			while (DATA == NO_DATA)
	    	  			{
	    	  				DATA = UART_GetChar();
	    	  			}
	    	  			pass[pass_counter]=DATA;
	    	  			LCD_vidWriteCharctr(DATA);
	    	  			_delay_ms(CHARACTER_PREVIEW_TIME);
	    	  			LCD_vidSetPosition(1,pass_counter);
	    	  			LCD_vidWriteCharctr(PASSWORD_SYMBOL);
	    	  			_delay_ms(100);
	    	  			pass_counter++;
	    	  		}

	    		 LCD_clearscreen();
	    	  	LCD_vidWriteString("Wait for check:",14);
	    	  	//     0x02*0x1C+0x10
	    	  	// Compare
	    	  	u8 ok=0;

	    	  	 _delay_ms(500);
	    	  	LCD_clearscreen();
	    	    	for(u16 j=1;j<=Num_of_users;j++) { // iterate over all users
	    	    		for(u8 i=0;i<NAME_SIZE;i++)stored_name[i]=0xff;
	    	  		u8 ok1=1,ok2=1;
	    	  		u8 cur_poz=j*ROW;

	    	  		for(u8 i=0;i<NAME_SIZE;i++){
	    	    	EEPROM_ReadByte(cur_poz+i,chs,1);
	    	    	stored_name[i]=chs[0];
	    	  		}
	    	  		cur_poz+=NAME_SIZE;
	    	  		EEPROM_ReadByte(cur_poz,stored_pass,PASS_SIZE);

	    	  		for(u8 i=0;i<NAME_SIZE;i++)
	    	  		    if(stored_name[i]!=name[i])ok1=0;
	    	  		for(u8 i=0;i<PASS_SIZE;i++)
	    	  			if(stored_pass[i]!=pass[i])ok2=0;

	    	  		if(ok1&&ok2){ok=1;break;}
	    	 		}

	    	  		if (ok==1)  //in case of right name and password
	    	  		{
	    	  				pass_tries_count=0;
	    	  				LCD_vidWriteString("Right Data :) ",14);
	    	  				LedGreenOn();
	    	  				Allow_to_enter=1;
	    	  				_delay_ms(1500);
	    	  				LCD_clearscreen();
	    	  				LCD_vidWriteString("Welcome to home",15);
	    	  				LCD_vidSetPosition(1,0);
	    	  				LCD_vidWriteString("Nour and Ola",12);
	    	  				_delay_ms(1500);
	    	  				LCD_clearscreen();
	    	  				break;
	    	  		}
	    	  		else//in case of wrong password
	    	  		{
	    	  				pass_tries_count++;
	    	  				LCD_clearscreen();
	    	  				LedRedOn();
	    	  				LCD_vidWriteString("Wrong Pass",10);
	    	  				LCD_vidSetPosition(1,0);
	    	  				LCD_vidWriteString("Tries left:",11);
	    	  				LCD_vidWriteNumber(TRIES_ALLOWED-pass_tries_count);
	    	  				_delay_ms(2000);
	    	  				LedRedOff();

	    	  				LCD_clearscreen();
	    	  				if (pass_tries_count>=TRIES_ALLOWED)
	    	  				{
	    	  					BuzzerOn();
	    	  					LedRedOn();
	    	  					LCD_vidWriteString("Session Timeout",15);
	    	  					LCD_vidSetPosition(1,0);
	    	  					LCD_vidWriteString("You Can't Enter",15);
	    	  					_delay_ms(3000);
	    	  					LedRedOff();
	    	  					BuzzerOff();
	    	  						break;
	    	  		       }
	    	  		}
	          }
	    	  return Allow_to_enter;
	      }
}



