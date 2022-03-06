#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

void UART_Init(void);

void UART_SendChar(u8 data);

u8 UART_GetChar(void);

void UART_vSendstring( char *ptr);



#endif
