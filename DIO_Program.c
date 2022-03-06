#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Register.h"


void DIO_VidSetPinValue(u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8PinValue)
{
	
		if (LOC_u8PinValue==1)
		{
			switch (LOC_u8Port)
			{
				case 0: SET_BIT(PORTA,LOC_u8Pin); break;
				case 1: SET_BIT(PORTB,LOC_u8Pin); break;
				case 2: SET_BIT(PORTC,LOC_u8Pin); break;
				case 3: SET_BIT(PORTD,LOC_u8Pin); break;
			}
		
		}
		
		else if (LOC_u8PinValue==0)
		{
			switch (LOC_u8Port)
			{
				case 0: CLR_BIT(PORTA,LOC_u8Pin); break;
				case 1: CLR_BIT(PORTB,LOC_u8Pin); break;
				case 2: CLR_BIT(PORTC,LOC_u8Pin); break;
				case 3: CLR_BIT(PORTD,LOC_u8Pin); break;
			}
		
		}
	
}


u8 DIO_U8GetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin)
{

	u8 u8ResultLocal;
	
	switch (LOC_U8Port)
	 {
		case 0: u8ResultLocal= GET_BIT(PINA,LOC_U8Pin); break;
		case 1: u8ResultLocal= GET_BIT(PINB,LOC_U8Pin); break;
		case 2: u8ResultLocal= GET_BIT(PINC,LOC_U8Pin); break;
		case 3: u8ResultLocal= GET_BIT(PIND,LOC_U8Pin); break;
	 }
	return u8ResultLocal;
}


void DIO_VidSetPinDirection (u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State)
{

		if (LOC_u8State==1 )
		{
		
			switch (LOC_u8Port)
			{
				case 0: SET_BIT(DDRA,LOC_u8Pin); break;
				case 1: SET_BIT(DDRB,LOC_u8Pin); break;
				case 2: SET_BIT(DDRC,LOC_u8Pin); break;
				case 3: SET_BIT(DDRD,LOC_u8Pin); break;
			}
		}
		
		else if(LOC_u8State==0 )
		{
			switch (LOC_u8Port)
			{
				case 0: CLR_BIT(DDRA,LOC_u8Pin); break;
				case 1: CLR_BIT(DDRB,LOC_u8Pin); break;
				case 2: CLR_BIT(DDRC,LOC_u8Pin); break;
				case 3: CLR_BIT(DDRD,LOC_u8Pin); break;
			}
		}
		
}


void DIO_VidSetPortDirection (u8 LOC_U8Port, u8 LOC_U8dir)
{
	
	switch (LOC_U8Port)
	{
		case     0: DDRA = LOC_U8dir; break;
		case     1: DDRB = LOC_U8dir; break;
		case     2: DDRC = LOC_U8dir; break;
		case     3: DDRD = LOC_U8dir; break;
		default:       break;
	}
}


void DIO_VidSetPortValue (u8 LOC_U8Port, u8 LOC_U8Value)
{
	
	switch (LOC_U8Port)
	{
		case     0: PORTA = LOC_U8Value ; break;
		case     1: PORTB = LOC_U8Value; break;
		case     2: PORTC = LOC_U8Value; break;
		case     3: PORTD = LOC_U8Value; break;
		default:        break;
	}
}

void DIO_VidTogglePin (u8 LOC_U8Port, u8 LOC_U8Pin){
	u8 x=DIO_U8GetPinValue(LOC_U8Port,LOC_U8Pin);
	DIO_VidSetPinValue(LOC_U8Port,LOC_U8Pin,!x);
}
