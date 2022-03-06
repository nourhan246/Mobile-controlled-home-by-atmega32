#ifndef MAIN_CONFIG_H_
#define MAIN_CONFIG_H_

#include "STD_TYPES.h"

#define NOT_STORED   0xFF
#define NOT_SELECTED 0xFF

#define BLOCK_MODE_TIME		   (u32)20000
#define CHARACTER_PREVIEW_TIME (u16)300
#define DEGREES_SYMBOL		   (u8)0xDF

/*********************************** PIN Configuration ***********************************/
#define PASS_SIZE       (u8)4
#define NAME_SIZE       (u8)12
#define TRIES_ALLOWED   (u8)3
#define PASSWORD_SYMBOL (u8)'*'
#define NO_DATA         (u8)'#'
#define ASCII_ZERO      (u8)'0'

//#define PASS_NOT_SET (u)0xFF
//#define REGISTER_DONE     (u8)0x01

#define STATE (u8)0
#define ROW (u8)16
#define number_of_users (u8)1

/*****************************************************************************************/

/************************************   Login configurations *****************************/
#define NO_MODE (u8)0
#define ADMIN   (u8)1
#define GUEST   (u8)2
/*****************************************************************************************/

/************************************   Logic values *************************************/
#define FALSE   (u8)0
#define TRUE    (u8)1
/*****************************************************************************************/


#endif /* MAIN_CONFIG_H_ */
