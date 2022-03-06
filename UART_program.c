#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_register.h"
#include "DIO_Interface.h"
#include <avr/delay.h>

void UART_Init(void)
{
	
	// Set Frame Format -> 8 data, 1 stop, No Parity
	UCSRC=0b10000110;
	
	
 // Set BaudRate -> 9600/8MhZ
  UBRRL = 51;
  UBRRH = 0;
  
  //enable TX,RX
	UCSRB=0x18;
}

void UART_SendChar(u8 data)
{
	while(GET_BIT(UCSRA,5)==0x00);
	UDR=data;
	
}

u8 UART_GetChar(void)
{
//	u8 Result;
	while(GET_BIT(UCSRA,7)==0x00);
//	Result=UDR;
	
	//clear flag
//	SET_BIT(UCSRA,7);
	return UDR;
}

void UART_vSendstring( char *ptr)
{
	while(*ptr!=0)
	{
		UART_SendChar(*ptr);
		ptr++;
		_delay_ms(100);
	}
}
