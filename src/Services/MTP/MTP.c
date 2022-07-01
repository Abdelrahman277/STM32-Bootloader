/*
 * MTP.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/DMA/DMA_interface.h"
#include "HAL/Interrupts/Interrupts_interface.h"

#include "MTP_cfg.h"
#include "MTP.h"
#include "MTP_prv.h"


/*
 * Message Transfer Protocol
 * */

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//           //        //             //             //                            //               //               //
// StartByte // IDByte // LengthByte0 // LengthByte1 // DataByte0        DataByteN // CheckSumByte0 // CheckSumByte1 //
//           //        //             //             //                            //               //               //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* MTP Initialization */
void MTP_Init(void)
{
	u8 Local_Iterator = 0;
	RCC_EnableDMA();
	RCC_EnableGPIOA();
	RCC_EnableUART();

	for(Local_Iterator = 0; Local_Iterator < sizeof(UARTPins)/sizeof(GPIO_t); Local_Iterator++)
	{
		GPIO_Init(&UARTPins[Local_Iterator]);
	}

	UART_Init();

	DMA_ChannelInit(TX_CHANNEL, TxChennel);
	DMA_ChannelInit(RX_CHANNEL, RxChennel);

	DMA_ChennelPeriphAddress(TX_CHANNEL, UART_DATAREG_ADDRESS);
	DMA_ChennelPeriphAddress(RX_CHANNEL, UART_DATAREG_ADDRESS);

	DMA_ChennelInterruptEnable(TX_CHANNEL);
	DMA_ChennelInterruptEnable(RX_CHANNEL);

	Interrupts_EnableIRQ(DMA1_Channel4_IRQn);
	Interrupts_EnableIRQ(DMA1_Channel5_IRQn);
	UART_Enable();

}

STD_ERR MTP_ReceiveData(MTP_MSG_t * msg, u32 CyclesToBreak)
{
	static MTPState_t ProcessState = STOPPED;
	u8 temp_bytes[3];
	u16 Received_CheckSum;
	u16 Calculated_CheckSum;

	/* Prepare to receive */
	if(ProcessState == STOPPED)
	{
		ProcessState = WAITING_FOR_STARTBYTE;
	}
	else
	{
		return ERR;
	}

	/* Receive a message */
	while(1)
	{
		switch(ProcessState)
		{
		case WAITING_FOR_STARTBYTE:
			/* Receive 1 byte (start byte) */
			RECEIVE_DATA(1, &temp_bytes);

			/* check if start byte is correct */
			if(temp_bytes[0] == MTP_START_BYTE)
			{
				ProcessState = WAITING_FOR_ID_AND_LENGTH;
			}
			else
			{
				/* Start byte is not correct */
				RECEIVE_ERROR();
			}
			break;

		case WAITING_FOR_ID_AND_LENGTH:
			/* Receive 3 bytes (ID & length) */
			RECEIVE_DATA(3, &temp_bytes);

			/* Write ID byte */
			msg->ID = temp_bytes[0];

			/* Write length bytes */
			msg->length = *(u16 *)&temp_bytes[1];

			ProcessState = WAITING_FOR_DATA_AND_CHECKSUM;
			break;

		case WAITING_FOR_DATA_AND_CHECKSUM:
			/* Receive data + 2 bytes(checksum) */
			RECEIVE_DATA((msg->length) + 2, (void *)((u32)(msg->Buffer)));

			/* Extract checksum from the message (last 2 bytes)*/
			Received_CheckSum = *(u16 *)((msg->Buffer) + msg->length);

			/* Calculate and compare checksum */
			Calculated_CheckSum = MTP_CalculateChecksum(msg);

			/* Stop the process */
			ProcessState = STOPPED;
			if(Calculated_CheckSum == Received_CheckSum)
			{
				return NO_ERR;
			}
			else
			{
				return ERR;
			}
			break;

		default:
			return ERR;
		}
	}

	return ERR;
}

STD_ERR MTP_SendData(MTP_MSG_t * msg)
{
	static MTPState_t ProcessState = STOPPED;
	u32 Local_Counter;

	/* Check if the process is running (in multi-threads systems)*/
	if(ProcessState != STOPPED)
	{
			return ERR;
	}
	else
	{
		ProcessState = SENDING_MESSAGE;
	}

	/* Writing start byte to buffer */
	transimissinBuffer[0] = MTP_START_BYTE;
	/* Writing ID byte to buffer */
	transimissinBuffer[1] = msg->ID;
	/* Writing length bytes to buffer */
	*((u16 *) &transimissinBuffer[2]) = msg->length;

	/* Writing data bytes to buffer */
	for(Local_Counter = 0; Local_Counter < msg->length; Local_Counter++)
	{
		*((u16 *) &transimissinBuffer[4 + Local_Counter]) = msg->Buffer[Local_Counter];
	}

	/* Writing checksum bytes to buffer */
	*((u16 *) &transimissinBuffer[msg->length + 4]) = MTP_CalculateChecksum(msg);

	/* Prepare DMA */
	DMA_ChennelNumberOfData(TX_CHANNEL, msg->length + 6);
	DMA_ChennelMemAddress(TX_CHANNEL, &transimissinBuffer);
	TxDMAState = SENDING;

	/* Start transmission */
	DMA_ChennelEnable(TX_CHANNEL);

	/* Wait to finish */
	while(TxDMAState != DATA_SENT);

	/* End of transmission */
	DMA_ChennelDisable(TX_CHANNEL);
	ProcessState = STOPPED;

	return NO_ERR;
}

u16 MTP_CalculateChecksum(MTP_MSG_t * msg)
{
	u16 Local_CHKCounter = 0;
	u16 Local_CheckSum = 0;
	u8 * Local_DataBuffer;

	/* Checksum = ID byte(1) + Length bytes(2) + Data bytes(N) */

	Local_CheckSum += (msg->ID);
	Local_CheckSum += (u8)(msg->length);
	Local_CheckSum += (u8)((msg->length) >> 8);
	Local_DataBuffer = (msg->Buffer);

	/* Calculate Checksum for data */
	for(Local_CHKCounter = 0; Local_CHKCounter < (msg->length); Local_CHKCounter++)
	{
		Local_CheckSum += *Local_DataBuffer;
		Local_DataBuffer++;
	}

	return Local_CheckSum;
}

void DMA1_Channel4_IRQHandler(void)
{
	TxDMAState = DATA_SENT;
	DMA_InterruptFlagClear(4);
}

void DMA1_Channel5_IRQHandler(void)
{
	RxDMAState = DATA_RECEIVED;
	DMA_InterruptFlagClear(5);
}
