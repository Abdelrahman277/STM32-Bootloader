/*
 * NVIC_program.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_interface.h"


/* Enable Interrupt */
void NVIC_EnableIRQ(s32 IRQn)
{
  NVIC->ISER[((u32)(IRQn) >> 5)] = (1 << ((u32)(IRQn) & 0x1F)); /* enable interrupt */
}


/* Disable Interrupt */
void NVIC_DisableIRQ(s32 IRQn)
{
  NVIC->ICER[((u32)(IRQn) >> 5)] = (1 << ((u32)(IRQn) & 0x1F)); /* disable interrupt */
}

/* brief  Get Pending Interrupt */
u32 NVIC_GetPendingIRQ(s32 IRQn)
{
  return((u32) ((NVIC->ISPR[(u32)(IRQn) >> 5] & (1 << ((u32)(IRQn) & 0x1F)))?1:0)); /* Return 1 if pending else 0 */
}


/* Set Pending Interrupt */
void NVIC_SetPendingIRQ(s32 IRQn)
{
  NVIC->ISPR[((u32)(IRQn) >> 5)] = (1 << ((u32)(IRQn) & 0x1F)); /* set interrupt pending */
}


/* Clear Pending Interrupt */
void NVIC_ClearPendingIRQ(s32 IRQn)
{
  NVIC->ICPR[((u32)(IRQn) >> 5)] = (1 << ((u32)(IRQn) & 0x1F)); /* Clear pending interrupt */
}


/* Get Active Interrupt */
u32 NVIC_GetActive(s32 IRQn)
{
  return((u32)((NVIC->IABR[(u32)(IRQn) >> 5] & (1 << ((u32)(IRQn) & 0x1F)))?1:0)); /* Return 1 if active else 0 */
}


/* Set Interrupt Priority */
void NVIC_SetDevicePriority(s32 IRQn, u32 priority)
{
  if(IRQn < 0)
  {

  }
  else
  {
	  /* set Priority for device specific Interrupts  */
    NVIC->IP[(u32)(IRQn)] = ((priority << (8 - NVIC_PRIO_BITS)) & 0xff);
  }
}


/* Get Interrupt Priority */
u32 NVIC_GetDevicePriority(s32 IRQn)
{
  if(IRQn < 0)
  {
    return ~0x0;
  }
  else
  {
	/* get priority for device specific interrupts  */
    return((u32)(NVIC->IP[(u32)(IRQn)] >> (8 - NVIC_PRIO_BITS)));
  }
}
