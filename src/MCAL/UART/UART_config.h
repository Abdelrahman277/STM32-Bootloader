/*
 * UART_config.h
 *
 *  Created on: Dec 14, 2021
 *      Author: Mohammed Ali
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

//#define CONFIG_PARITY_ENABLE
#define CONFIG_ODD_PARITY
#define CONFIG_9BITS_DATA

//#define CONFIG_0_5_STOP_BIT
//#define CONFIG_1_0_STOP_BIT
//#define CONFIG_1_5_STOP_BIT
#define CONFIG_2_0_STOP_BIT

//#define CONFIG_ENABLE_INTERRUPTS
#define CONFIG_ENABLE_DMA

/* Set baud rate = 115200 Bps
	*  USARTDIV = Fck / (16 * baud_rate)
	*           = 72000000 / (16 * 115200) = 39.06
	*
	*  DIV_Fraction = 16 * 0.06 = 9.6 = 10 = 0xA
	*  DIV_Mantissa = 39 = 0x27
	*
	*  BRR          = 0x27A */
#define CONFIG_DIV_MANTISSA		0x27
#define CONFIG_DIV_FRACTION		0xA



/* Set baud rate = 4800 Bps
	*  USARTDIV = Fck / (16 * baud_rate)
	*           = 36000000 / (16 * 4800) = 468.75
	*
	*  DIV_Fraction = 16 * 0.75 = 12 = 0xC
	*  DIV_Mantissa = 468 = 0x1D4
	*
	*  BRR          = 0x30D */
//#define CONFIG_DIV_MANTISSA		0x1D4
//#define CONFIG_DIV_FRACTION		0xC

#endif /* UART_CONFIG_H_ */
