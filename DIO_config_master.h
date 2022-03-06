/*
 * DIO_config_master.h
 *
 * Created: 4/24/2018 11:53:29 PM
 *  Author: Mohamed Zaghlol
 */ 


#ifndef DIO_CONFIG_MASTER_H_
#define DIO_CONFIG_MASTER_H_

/*****************************  Ports and pins of input and output pins ******************/
#define ADMIN_LED_PORT (uint8)'C'
#define GUEST_LED_PORT (uint8)'C'
#define BLOCK_LED_PORT (uint8)'C'

#define ADMIN_LED_PIN  (uint8)0
#define GUEST_LED_PIN  (uint8)1
#define BLOCK_LED_PIN  (uint8)2
/*****************************************************************************************/
/* keypad Macros */
#define KEYPAD_PORT			(uint8)'D'
#define KEYPAD_FIRST_PIN	(uint8)0
#define KEYPAD_SECOND_PIN	(uint8)1
#define KEYPAD_THIRD_PIN	(uint8)2
#define KEYPAD_FOURTH_PIN	(uint8)3
#define KEYPAD_FIFTH_PIN	(uint8)4
#define KEYPAD_SIXTH_PIN	(uint8)5
#define KEYPAD_SEVENTH_PIN	(uint8)6
#define KEYPAD_EIGHTH_PIN	(uint8)7
/* LCD Macros */
#define LCD_PORT			(uint8)'A'
#define LCD_FIRST_PIN		(uint8)0
#define LCD_SECOND_PIN		(uint8)1
#define LCD_THIRD_PIN		(uint8)2
#define LCD_FOURTH_PIN		(uint8)3
#define LCD_FIFTH_PIN		(uint8)4
#define LCD_SIXTH_PIN		(uint8)5
#define LCD_SEVENTH_PIN		(uint8)6
#define LCD_EIGHTH_PIN		(uint8)7
#define LCD_CONTROL_PORT	(uint8)'B'
#define LCD_EN_PIN			(uint8)0
#define LCD_RS_PIN			(uint8)1
#define LCD_RW_PIN			(uint8)2

#endif /* DIO_CONFIG_MASTER_H_ */