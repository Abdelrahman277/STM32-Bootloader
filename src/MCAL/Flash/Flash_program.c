/*
 * Flash_program.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "Flash_private.h"
#include "Flash_config.h"
#include "Flash_interface.h"


STD_ERR Flash_WriteWord(void * Address, u32 Word){
	STD_ERR Local_Error = ERR;

	while(FLASH->SR & FLASH_SR_BSY);
	FLASH->CR |= FLASH_CR_PG;
	*((u16 *)Address) = (u16)Word;

	while(FLASH->SR & FLASH_SR_BSY);
	FLASH->CR |= FLASH_SR_EOP;
	*(((u16 *)Address) + 1) = (u16)(Word >> 16);
	while(FLASH->SR & FLASH_SR_BSY);

	FLASH->CR &= ~FLASH_CR_PG;

	if (*((u32*)Address) == Word){
		Local_Error = NO_ERR;
	}
	return Local_Error;
}

STD_ERR Flash_WriteData(volatile void * DestAddress, volatile void * SrcAddress, u16 NumberOfHalfWords)
{
	volatile STD_ERR Local_Error = ERR;
	u16 Local_Iterator = 0;
	if(((u32) DestAddress >= FLASH_BASE) &&  ((u32) DestAddress <= FLASH_BASE + FLASH_LENGTH))
	{
		while(FLASH->SR & FLASH_SR_BSY);
		FLASH->CR |= FLASH_CR_PG;

		for(Local_Iterator = 0; Local_Iterator < NumberOfHalfWords; Local_Iterator++)
		{
			FLASH->CR |= FLASH_SR_EOP;
			*(((u16 *)DestAddress) + Local_Iterator) = *(((u16 *)SrcAddress) + Local_Iterator);
			while(FLASH->SR & FLASH_SR_BSY);
		}

		FLASH->CR &= ~FLASH_CR_PG;
		Local_Error = NO_ERR;
	}
	else
	{
		// Do Nothing
	}
	return Local_Error;
}

STD_ERR Flash_ErasePage(u32 PageAddress)
{
	STD_ERR Local_Error = ERR;

	/*Check that the address is within the Flash Range*/
	if((PageAddress >= FLASH_BASE )||(PageAddress <= (FLASH_BASE + FLASH_LENGTH)))
	{
		while(FLASH->SR & FLASH_SR_BSY);
		FLASH->CR |= FLASH_CR_PER;
		FLASH->AR = PageAddress;
		FLASH->CR |= FLASH_CR_STRT;
		while(FLASH->SR & FLASH_SR_BSY);

		if(  (*((volatile u32 *)PageAddress) ) == 0xffffffff )
		{
			Local_Error = NO_ERR;
		}

		FLASH->CR &= ~ (FLASH_CR_PER);
	}
	return Local_Error;
}

void Flash_EraseMass(void)
{
	while(FLASH->SR & FLASH_SR_BSY);
	FLASH->CR |= FLASH_CR_MER;
	FLASH->CR |= FLASH_CR_STRT;
	FLASH->CR &= ~(FLASH_CR_MER);
}

STD_ERR Flash_Lock(void)
{
	STD_ERR Local_Error = ERR;
	FLASH->CR |= FLASH_CR_LOCK;
	if(FLASH->CR & FLASH_CR_LOCK)
	{
		Local_Error = NO_ERR;
	}
	return Local_Error;
}

STD_ERR Flash_Unlock(void)
{
	STD_ERR Local_Error = ERR;
	if(FLASH->CR & FLASH_CR_LOCK)
	{
		FLASH->KEYR = FLASH_KEY1;
		FLASH->KEYR = FLASH_KEY2;
		Local_Error = NO_ERR;
	}
	return Local_Error;
}

void Flash_EnablePrefetchBuffer(void)
{
	/* Enable Prefetch Buffer */
	FLASH->ACR |= FLASH_ACR_PRFTBE;
}

STD_ERR Flash_SetLatency(u8 Latency)
{
	STD_ERR Local_Error = ERR;

	if(Latency <= FLASH_LATENCY_2)
	{
		/* Flash wait state */
		FLASH->ACR &= (u32)((u32)~FLASH_ACR_LATENCY);
		FLASH->ACR |= (u32)Latency;
		Local_Error = NO_ERR;
	}
	else
	{
		/* Do Nothing */
	}

    return Local_Error;
}
