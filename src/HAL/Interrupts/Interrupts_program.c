/*
 * Interrupts_program.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */
#include "STD_Types.h"
#include "Bit_Math.h"

#include "MCAL/SCB/SCB_interface.h"
#include "MCAL/NVIC/NVIC_interface.h"

#include "Interrupts_private.h"
#include "Interrupts_config.h"
#include "Interrupts_interface.h"

/* Set Interrupt Priority */
void Interrupts_SetPriority(s32 IRQn, u32 priority)
{
  if(IRQn < 0)
  {
	  SCB_SetSystemPriority(IRQn, priority);
  }
  else
  {
	  NVIC_SetDevicePriority(IRQn, priority);
  }

}


/* Get Interrupt Priority */
u32 Interrupts_GetPriority(s32 IRQn)
{

  if(IRQn < 0)
  {
    return SCB_GetSystemPriority(IRQn);
  }
  else
  {
    return NVIC_GetDevicePriority(IRQn);
  }
}

void Interrupts_EnableIRQ(s32 IRQn)
{
	NVIC_EnableIRQ(IRQn);
}

void Interrupts_DisableIRQ(s32 IRQn)
{
	NVIC_DisableIRQ(IRQn);
}

u32 Interrupts_GetPendingIRQ(s32 IRQn)
{
	return NVIC_GetPendingIRQ(IRQn);
}

void Interrupts_SetPendingIRQ(s32 IRQn)
{
	NVIC_SetPendingIRQ(IRQn);
}

void Interrupts_ClearPendingIRQ(s32 IRQn)
{
	NVIC_ClearPendingIRQ(IRQn);
}

u32 Interrupts_GetActive(s32 IRQn)
{
	return NVIC_GetActive(IRQn);
}

void Interrupts_SetDevicePriority(s32 IRQn, u32 priority)
{
	NVIC_SetDevicePriority(IRQn, priority);
}

u32 Interrupts_GetDevicePriority(s32 IRQn)
{
	return NVIC_GetDevicePriority(IRQn);
}
