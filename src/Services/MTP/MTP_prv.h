/*
 * MTP_prv.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_MTP_MTP_PRV_H_
#define SERVICES_MTP_MTP_PRV_H_

#define UART_DATAREG_ADDRESS		((void *) 0x40013804)
#define MTP_START_BYTE	0x25
#define TX_CHANNEL	DMA1_Channel4
#define RX_CHANNEL	DMA1_Channel5
#define	RECEIVE_ERROR()						ProcessState = STOPPED;DMA_ChennelDisable(RX_CHANNEL);return ERR;

#define RECEIVE_DATA(bytes, storage) DMA_ChennelNumberOfData(RX_CHANNEL, bytes);  										  \
									 DMA_ChennelMemAddress(RX_CHANNEL, storage); 										  \
									 DMA_ChennelEnable(RX_CHANNEL);         										          \
									 {																					  \
									   	u32 iterator = 0;																  \
										while(RxDMAState != DATA_RECEIVED)												 \
										{ \
											if(ProcessState == WAITING_FOR_STARTBYTE){if(iterator >= CyclesToBreak){ProcessState = STOPPED;RECEIVE_ERROR();}} \
											else if(iterator >= MTP_CYCLES_TO_BREAK){ProcessState = STOPPED;RECEIVE_ERROR();}\
											iterator++;																		\
										} \
									 }  																					   \
									 DMA_ChennelDisable(RX_CHANNEL);														  \
									 RxDMAState = NO_DATA




/* Private Types */
typedef enum
{
	STOPPED,
	WAITING_FOR_STARTBYTE,
	WAITING_FOR_ID_AND_LENGTH,
	WAITING_FOR_DATA_AND_CHECKSUM,
	SENDING_MESSAGE,

} MTPState_t;

typedef enum
{
	NO_DATA,
	DATA_RECEIVED,
	SENDING,
	DATA_SENT
} DMAState_t;

typedef struct
{
	u8 ID;
	u16 length;
	u8 * Buffer;
	u16 checksum;
} MTPFrame_t;

/* Private Variables */
__VOLATILE DMAState_t 	RxDMAState = NO_DATA;
__VOLATILE DMAState_t 	TxDMAState = NO_DATA;
u8 transimissinBuffer[MTP_TX_BUFFER_SIZE];

GPIO_t UARTPins[] =
{
		{GPIOA, GPIO_PIN_9, GPIO_OUTPUT_AF_PUSH_PULL},
		{GPIOA, GPIO_PIN_10, GPIO_INPUT_FLOATING}
};

DMA_ChannelSetup_t RxChennel = {
		.MemToPeriph 		= FALSE,
		.CircularMode		= FALSE,
		.PeriphIncrement 	= FALSE,
		.MemIncrement		= TRUE,
		.PeriphSize 		= DMA_PSIZE_8BITS,
		.MemSize 			= DMA_MSIZE_8BITS,
		.Priority 			= DMA_PRIORITY_HIGH,
		.MemToMemMode 		= FALSE,
	};

DMA_ChannelSetup_t TxChennel = {
		.MemToPeriph 		= TRUE,
		.CircularMode		= FALSE,
		.PeriphIncrement 	= FALSE,
		.MemIncrement		= TRUE,
		.PeriphSize 		= DMA_PSIZE_8BITS,
		.MemSize 			= DMA_MSIZE_8BITS,
		.Priority 			= DMA_PRIORITY_HIGH,
		.MemToMemMode 		= FALSE,
	};

/* Private Functions */
u16 MTP_CalculateChecksum(MTP_MSG_t * msg);
void DMA1_Channel4_IRQHandler(void);
void DMA1_Channel5_IRQHandler(void);


#endif /* SERVICES_MTP_MTP_PRV_H_ */
