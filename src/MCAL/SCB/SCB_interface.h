/*
 * SCB_interface.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_SCB_SCB_INTERFACE_H_
#define MCAL_SCB_SCB_INTERFACE_H_

void SCB_SetVectorTableOffset(u32 Address);
void SCB_SetNVICPriorityGrouping(u32 PriorityGroup);
void SCB_SetSystemPriority(s32 IRQn, u32 priority);
u32 SCB_GetSystemPriority(s32 IRQn);

#endif /* MCAL_SCB_SCB_INTERFACE_H_ */
