/*
 * DMA_program.c
 *
 *  Created on: Feb 27, 2022
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "DMA_private.h"
#include "DMA_config.h"
#include "DMA_interface.h"

void DMA_ChannelInit(u32 chennel, DMA_ChannelSetup_t setup)
{
	((DMA_Channel_TypeDef *) chennel)->CCR = (*((u32*) &setup)) << 4;
}

void DMA_ChennelEnable(u32 chennel)
{
	((DMA_Channel_TypeDef *) chennel)->CCR |= DMA_CCRx_EN;
}

void DMA_ChennelDisable(u32 chennel)
{
	((DMA_Channel_TypeDef *) chennel)->CCR &= ~DMA_CCRx_EN;
}

void DMA_ChennelNumberOfData(u32 chennel, u16 number)
{
	((DMA_Channel_TypeDef *) chennel)->CNDTR = (u32) number;
}

void DMA_ChennelMemAddress(u32 chennel, void * address)
{
	((DMA_Channel_TypeDef *) chennel)->CMAR = (u32)((u32 *)address);
}

void DMA_ChennelPeriphAddress(u32 chennel, void * address)
{
	((DMA_Channel_TypeDef *) chennel)->CPAR = (u32)((u32 *)address);
}

void DMA_ChennelInterruptEnable(u32 chennel)
{
	((DMA_Channel_TypeDef *) chennel)->CCR |= DMA_CCRx_TCIE | DMA_CCRx_TEIE;
}

void DMA_ChennelInterruptDisable(u32 chennel)
{
	((DMA_Channel_TypeDef *) chennel)->CCR &= ~(DMA_CCRx_TCIE | DMA_CCRx_TEIE);
}

void DMA_InterruptFlagClear(u32 chennelNumber)
{
	DMA1->IFCR = 0x0F << ((chennelNumber - 1) << 2);
}
