/*
 * UART_interface.h
 *
 *  Created on: Dec 14, 2021
 *      Author: Mohammed Ali
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


#define	UART_RXNE_FLAG	0b001
#define	UART_TC_FLAG	0b010
#define	UART_PE_FLAG	0b100

/* Functions prototypes */
void UART_Init(void);
void UART_Enable(void);
void UART_Disable(void);
void UART_SendByte(u8 Byte);
void UART_WriteToBuffer(u8 Byte);
u8 UART_ReceiveByte(void);
u8 UART_ReadBuffer(void);
void UART_SendData(u8 * buf, u32 length);
void UART_ReceiveData(u8 * buf, u32 length);
void UART_SetInterruptHandler(void (*Handler)(u8));

#endif /* UART_INTERFACE_H_ */
