/*
 * RCC_interface.h
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

void RCCSystemInit (void);
STD_ERR RCC_StartHSE(void);
void RCC_SetSystemClock72MHz(void);
u32 RCC_GetSystemCoreClock(void);
void RCC_EnableGPIOA(void);
void RCC_ResetGPIOA(void);
void RCC_DisableGPIOA(void);
void RCC_EnableGPIOB(void);
void RCC_ResetGPIOB(void);
void RCC_DisableGPIOB(void);
void RCC_EnableGPIOC(void);
void RCC_ResetGPIOC(void);
void RCC_DisableGPIOC(void);
void RCC_EnableUART(void);
void RCC_ResetUART(void);
void RCC_DisableUART(void);
void RCC_EnableDMA(void);
void RCC_DisableDMA(void);

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
