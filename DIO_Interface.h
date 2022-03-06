#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

/* Port Defines */
#define PORTA   0
#define PORTB   1
#define PORTC   2
#define PORTD   3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Directions */
#define INPUT  0
#define OUTPUT 1

/* PIN Value Options */
#define HIGH   1
#define LOW    0

/* IO Pins */

void DIO_VidSetPinDirection (u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8State);

void DIO_VidSetPortDirection (u8 LOC_U8Port, u8 LOC_U8dir) ;

void DIO_VidSetPinValue(u8 LOC_u8Port, u8 LOC_u8Pin, u8 LOC_u8PinValue);

u8 DIO_U8GetPinValue(u8 LOC_U8Port, u8 LOC_U8Pin);

void DIO_VidSetPortValue (u8 LOC_U8Port, u8 LOC_U8Value);

void DIO_VidTogglePin (u8 LOC_U8Port, u8 LOC_U8Pin);


#endif
