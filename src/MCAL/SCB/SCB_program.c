/*
 * SCB_program.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */
#include "STD_Types.h"
#include "Bit_Math.h"

#include "SCB_private.h"
#include "SCB_config.h"
#include "SCB_interface.h"

/* Set Offset of Vector Table */
void SCB_SetVectorTableOffset(u32 Address)
{
	__ASM("DMB");
	SCB->VTOR =	Address;
	__ASM("DSB");
}

/* Set Priority Grouping */
void SCB_SetNVICPriorityGrouping(u32 PriorityGroup)
{
  u32 reg_value;
  u32 PriorityGroupTmp = (PriorityGroup & (u32)0x07);               /* only values 0..7 are used          */

  reg_value  =  SCB->AIRCR;                                                   /* read old register configuration    */
  reg_value &= ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk);             /* clear bits to change               */
  reg_value  =  (reg_value                                 |
                ((u32)0x5FA << SCB_AIRCR_VECTKEY_Pos) |
                (PriorityGroupTmp << 8));                                     /* Insert write key and priorty group */
  SCB->AIRCR =  reg_value;
}

/* Set Interrupt Priority */
void SCB_SetSystemPriority(s32 IRQn, u32 priority)
{
  if(IRQn < 0)
  {
	/* set Priority for Cortex-M  System Interrupts */
    SCB->SHP[((u32)(IRQn) & 0xF)-4] = ((priority << (8 - NVIC_PRIO_BITS)) & 0xff);
  }
  else
  {

  }
}

/* Get Interrupt Priority */
u32 SCB_GetSystemPriority(s32 IRQn)
{
  if(IRQn < 0)
  {
	/* get priority for Cortex-M  system interrupts */
    return((u32)(SCB->SHP[((u32)(IRQn) & 0xF)-4] >> (8 - NVIC_PRIO_BITS)));
  }
  else
  {
    return ~0;
  }
}
