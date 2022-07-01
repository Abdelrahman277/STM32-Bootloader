/*
 * DMA_interface.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Mohammed Ali
 */

#ifndef MCAL_DMA_DMA_INTERFACE_H_
#define MCAL_DMA_DMA_INTERFACE_H_

#define DMA1_Channel1    (0x40020000 + 0x0008)
#define DMA1_Channel2    (0x40020000 + 0x001C)
#define DMA1_Channel3    (0x40020000 + 0x0030)
#define DMA1_Channel4    (0x40020000 + 0x0044)
#define DMA1_Channel5    (0x40020000 + 0x0058)
#define DMA1_Channel6    (0x40020000 + 0x006C)
#define DMA1_Channel7    (0x40020000 + 0x0080)

#define DMA_PSIZE_8BITS			0x00
#define DMA_PSIZE_16BITS		0x01
#define DMA_PSIZE_32BITS		0x02

#define DMA_MSIZE_8BITS			0x00
#define DMA_MSIZE_16BITS		0x01
#define DMA_MSIZE_32BITS		0x02

#define DMA_PRIORITY_LOW		0x00
#define DMA_PRIORITY_MEDIUM		0x01
#define DMA_PRIORITY_HIGH		0x02
#define DMA_PRIORITY_VERYHIGH	0x03


typedef struct
{
  u32 MemToPeriph : 1;
  u32 CircularMode : 1;
  u32 PeriphIncrement : 1;
  u32 MemIncrement : 1;
  u32 PeriphSize : 2;
  u32 MemSize : 2;
  u32 Priority : 2;
  u32 MemToMemMode : 1;
} DMA_ChannelSetup_t;

void DMA_ChannelInit(u32 chennel, DMA_ChannelSetup_t setup);
void DMA_ChennelEnable(u32 chennel);
void DMA_ChennelDisable(u32 chennel);
void DMA_ChennelNumberOfData(u32 chennel, u16 number);
void DMA_ChennelMemAddress(u32 chennel, void * address);
void DMA_ChennelPeriphAddress(u32 chennel, void * address);
void DMA_ChennelInterruptEnable(u32 chennel);
void DMA_ChennelInterruptDisable(u32 chennel);
void DMA_InterruptFlagClear(u32 chennelNumber);


#endif /* MCAL_DMA_DMA_INTERFACE_H_ */
