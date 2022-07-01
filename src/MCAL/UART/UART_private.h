/*
 * UART_private.h
 *
 *  Created on: Dec 14, 2021
 *      Author: Mohammed Ali
 */

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/* Pointer to Interrupt handler */
void (*USART1_func)(u8 flags);

#define USART1_BASE           ((u32)0x40013800)

/*******************  Bit definition for USART_SR register  *******************/
#define  USART_SR_PE                         ((u16)0x0001)            /*!< Parity Error */
#define  USART_SR_FE                         ((u16)0x0002)            /*!< Framing Error */
#define  USART_SR_NE                         ((u16)0x0004)            /*!< Noise Error Flag */
#define  USART_SR_ORE                        ((u16)0x0008)            /*!< OverRun Error */
#define  USART_SR_IDLE                       ((u16)0x0010)            /*!< IDLE line detected */
#define  USART_SR_RXNE                       ((u16)0x0020)            /*!< Read Data Register Not Empty */
#define  USART_SR_TC                         ((u16)0x0040)            /*!< Transmission Complete */
#define  USART_SR_TXE                        ((u16)0x0080)            /*!< Transmit Data Register Empty */
#define  USART_SR_LBD                        ((u16)0x0100)            /*!< LIN Break Detection Flag */
#define  USART_SR_CTS                        ((u16)0x0200)            /*!< CTS Flag */

/*******************  Bit definition for USART_DR register  *******************/
#define  USART_DR_DR                         ((u16)0x01FF)            /*!< Data value */

/******************  Bit definition for USART_BRR register  *******************/
#define  USART_BRR_DIV_Fraction              ((u16)0x000F)            /*!< Fraction of USARTDIV */
#define  USART_BRR_DIV_Mantissa              ((u16)0xFFF0)            /*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_CR1 register  *******************/
#define  USART_CR1_SBK                       ((u16)0x0001)            /*!< Send Break */
#define  USART_CR1_RWU                       ((u16)0x0002)            /*!< Receiver wakeup */
#define  USART_CR1_RE                        ((u16)0x0004)            /*!< Receiver Enable */
#define  USART_CR1_TE                        ((u16)0x0008)            /*!< Transmitter Enable */
#define  USART_CR1_IDLEIE                    ((u16)0x0010)            /*!< IDLE Interrupt Enable */
#define  USART_CR1_RXNEIE                    ((u16)0x0020)            /*!< RXNE Interrupt Enable */
#define  USART_CR1_TCIE                      ((u16)0x0040)            /*!< Transmission Complete Interrupt Enable */
#define  USART_CR1_TXEIE                     ((u16)0x0080)            /*!< TXEIE Interrupt Enable */
#define  USART_CR1_PEIE                      ((u16)0x0100)            /*!< PE Interrupt Enable */
#define  USART_CR1_PS                        ((u16)0x0200)            /*!< Parity Selection */
#define  USART_CR1_PCE                       ((u16)0x0400)            /*!< Parity Control Enable */
#define  USART_CR1_WAKE                      ((u16)0x0800)            /*!< Wakeup method */
#define  USART_CR1_M                         ((u16)0x1000)            /*!< Word length */
#define  USART_CR1_UE                        ((u16)0x2000)            /*!< USART Enable */
#define  USART_CR1_OVER8                     ((u16)0x8000)            /*!< USART Oversmapling 8-bits */

/******************  Bit definition for USART_CR2 register  *******************/
#define  USART_CR2_ADD                       ((u16)0x000F)            /*!< Address of the USART node */
#define  USART_CR2_LBDL                      ((u16)0x0020)            /*!< LIN Break Detection Length */
#define  USART_CR2_LBDIE                     ((u16)0x0040)            /*!< LIN Break Detection Interrupt Enable */
#define  USART_CR2_LBCL                      ((u16)0x0100)            /*!< Last Bit Clock pulse */
#define  USART_CR2_CPHA                      ((u16)0x0200)            /*!< Clock Phase */
#define  USART_CR2_CPOL                      ((u16)0x0400)            /*!< Clock Polarity */
#define  USART_CR2_CLKEN                     ((u16)0x0800)            /*!< Clock Enable */

#define  USART_CR2_STOP                      ((u16)0x3000)            /*!< STOP[1:0] bits (STOP bits) */
#define  USART_CR2_STOP_0                    ((u16)0x1000)            /*!< Bit 0 */
#define  USART_CR2_STOP_1                    ((u16)0x2000)            /*!< Bit 1 */

#define  USART_CR2_LINEN                     ((u16)0x4000)            /*!< LIN mode enable */

/******************  Bit definition for USART_CR3 register  *******************/
#define  USART_CR3_EIE                       ((u16)0x0001)            /*!< Error Interrupt Enable */
#define  USART_CR3_IREN                      ((u16)0x0002)            /*!< IrDA mode Enable */
#define  USART_CR3_IRLP                      ((u16)0x0004)            /*!< IrDA Low-Power */
#define  USART_CR3_HDSEL                     ((u16)0x0008)            /*!< Half-Duplex Selection */
#define  USART_CR3_NACK                      ((u16)0x0010)            /*!< Smartcard NACK enable */
#define  USART_CR3_SCEN                      ((u16)0x0020)            /*!< Smartcard mode enable */
#define  USART_CR3_DMAR                      ((u16)0x0040)            /*!< DMA Enable Receiver */
#define  USART_CR3_DMAT                      ((u16)0x0080)            /*!< DMA Enable Transmitter */
#define  USART_CR3_RTSE                      ((u16)0x0100)            /*!< RTS Enable */
#define  USART_CR3_CTSE                      ((u16)0x0200)            /*!< CTS Enable */
#define  USART_CR3_CTSIE                     ((u16)0x0400)            /*!< CTS Interrupt Enable */
//#define  USART_CR3_ONEBIT                    ((u16)0x0800)            /*!< One Bit method */

/* USART data type */
typedef struct
{
  __IO u16 SR;
  u16  RESERVED0;
  __IO u16 DR;
  u16  RESERVED1;
  __IO u16 BRR;
  u16  RESERVED2;
  __IO u16 CR1;
  u16  RESERVED3;
  __IO u16 CR2;
  u16  RESERVED4;
  __IO u16 CR3;
  u16  RESERVED5;
  __IO u16 GTPR;
  u16  RESERVED6;
} USART_TypeDef;

/* Existing UART units */
#define USART1              ((USART_TypeDef *) USART1_BASE)

#endif /* UART_PRIVATE_H_ */
