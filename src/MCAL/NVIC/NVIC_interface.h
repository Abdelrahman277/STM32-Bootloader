/*
 * NVIC_interface.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

void NVIC_EnableIRQ(s32 IRQn);
void NVIC_DisableIRQ(s32 IRQn);
u32 NVIC_GetPendingIRQ(s32 IRQn);
void NVIC_SetPendingIRQ(s32 IRQn);
void NVIC_ClearPendingIRQ(s32 IRQn);
u32 NVIC_GetActive(s32 IRQn);
void NVIC_SetDevicePriority(s32 IRQn, u32 priority);
u32 NVIC_GetDevicePriority(s32 IRQn);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
