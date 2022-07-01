/*
 * UART_program.c
 *
 *  Created on: Dec 14, 2021
 *      Author: Mohammed Ali
 */

#include "STD_Types.h"
#include "Bit_Math.h"

#include "UART_private.h"
#include "UART_config.h"
#include "UART_interface.h"



void UART_Init(void)
{

	/* Reset all registers */
	USART1->CR1 = 0x0;
	USART1->CR2 = 0x0;
	USART1->CR3 = 0x0;

	/* Select 1 Start bit, 8 or 9 Data bits, n Stop bit */
#ifdef CONFIG_9BITS_DATA
	USART1->CR1 |= USART_CR1_M;
#endif

	/* Select 1 stop bit */
#ifdef CONFIG_1_0_STOP_BIT
	USART1->CR2 &= ~USART_CR2_STOP;
#elif defined CONFIG_1_5_STOP_BIT
	USART1->CR2 |= USART_CR2_STOP_0 | USART_CR2_STOP_1;
#elif defined CONFIG_2_0_STOP_BIT
	USART1->CR2 |= USART_CR2_STOP_1;
#elif defined CONFIG_0_5_STOP_BIT
	USART1->CR2 |= USART_CR2_STOP_0;
#endif

	/* Enable parity control */
#ifdef CONFIG_PARITY_ENABLE
	USART1->CR1 |= USART_CR1_PCE;
#endif

	/* Select odd parity */
#ifdef CONFIG_ODD_PARITY
	USART1->CR1 |= USART_CR1_PS;
#endif

	/* Enable DMA Mode*/
#ifdef CONFIG_ENABLE_DMA
	USART1->CR3 |= USART_CR3_DMAR;
	USART1->CR3 |= USART_CR3_DMAT;
#endif
	/* Set baud rate */
	USART1->BRR = (CONFIG_DIV_MANTISSA << 4) | (CONFIG_DIV_FRACTION & 0x0000000F);
}

void UART_Enable(void)
{
	/* Enable USART1 */
	USART1->CR1 |= USART_CR1_UE;

	/* Enable transmitter */
	USART1->CR1 |= USART_CR1_TE;

	/* Enable receiver */
	USART1->CR1 |= USART_CR1_RE;

#ifdef CONFIG_ENABLE_INTERRUPTS
	/* Enable reception buffer not empty flag interrupt */
	USART1->CR1 |= USART_CR1_RXNEIE;

	/* Enable Transmission completed interrupt */
	USART1->CR1 |= USART_CR1_TCIE;
#endif
}

void UART_Disable(void)
{
	/* Disable USART1 */
	USART1->CR1 &= ~USART_CR1_UE;

	/* Disable transmitter */
	USART1->CR1 &= ~USART_CR1_TE;

	/* Disable receiver */
	USART1->CR1 &= ~USART_CR1_RE;

#ifdef CONFIG_ENABLE_INTERRUPTS
	/* Disable reception buffer not empty flag interrupt */
	USART1->CR1 &= ~USART_CR1_RXNEIE;

	/* Disable Transmission completed interrupt */
	USART1->CR1 &= ~USART_CR1_TCIE;
#endif
}

void UART_SendByte(u8 Byte)
{
	USART1->DR = (u16) Byte;
	while(!(USART1->SR & USART_SR_TXE));
}

void UART_WriteToBuffer(u8 Byte)
{
	USART1->DR = (u16) Byte;
}

u8 UART_ReceiveByte(void)
{
	while(!(USART1->SR & USART_SR_RXNE));
	return (u8) USART1->DR;
}

u8 UART_ReadBuffer(void)
{
	return (u8) USART1->DR;
}

void UART_SendData(u8 * buf, u32 length)
{
	while(length--)
	{
		UART_SendByte(*buf);
		buf++;
	}
}

void UART_ReceiveData(u8 * buf, u32 length)
{
	while(length--)
	{
		*buf = UART_ReceiveByte();
		buf++;
	}
}

#ifdef CONFIG_ENABLE_INTERRUPTS
void UART_SetInterruptHandler(void (*Handler)(u8))
{
	USART1_func = Handler;
}

void USART1_IRQHandler(void)
{
	u8 flags = 0;
	if(USART1->SR & USART_SR_RXNE)
	{
		flags |= UART_RXNE_FLAG;
	}
	if(USART1->SR & USART_SR_TC)
	{
		flags |= UART_TC_FLAG;
	}
	if(USART1->SR & USART_SR_PE)
	{
		flags |= UART_PE_FLAG;
	}
	if(USART1_func)
	{
		USART1_func(flags);
	}
	USART1->SR = 0;
}
#endif
