/*
 * RCC_program.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */

#include "STD_Types.h"
#include "Bit_Math.h"

#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"


void RCCSystemInit (void)
{
  /* Reset the RCC clock configuration to the default reset state(for debug purpose) */
  /* Set HSION bit */
  RCC->CR |= (u32)0x00000001;

  /* Wait till HSI is ready */
  while(RCC_CR_HSIRDY != (RCC_CR_HSIRDY & RCC->CR))
  {
	/* Waiting */
  }

  /* Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits */
  RCC->CFGR &= (u32)0xF8FF0000;

  /* Reset HSEON, CSSON and PLLON bits */
  RCC->CR &= (u32)0xFEF6FFFF;

  /* Reset HSEBYP bit */
  RCC->CR &= (u32)0xFFFBFFFF;

  /* Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits */
  RCC->CFGR &= (u32)0xFF80FFFF;

  /* Disable all interrupts and clear pending bits  */
  RCC->CIR = 0x009F0000;
}

STD_ERR RCC_StartHSE(void)
{
	__IO u32 Local_StartUpCounter = 0;
	__IO STD_ERR Local_Error = ERR;

	  /* SYSCLK, HCLK, PCLK2 and PCLK1 configuration ---------------------------*/
	  /* Enable HSE */
	  RCC->CR |= ((u32)RCC_CR_HSEON);

	  /* Wait till HSE is ready and if Time out is reached exit */
	  do
	  {
	    Local_StartUpCounter++;
	  } while(((RCC->CR & RCC_CR_HSERDY) == 0) && (Local_StartUpCounter != HSE_STARTUP_TIMEOUT));

	  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
	  {
		  Local_Error = NO_ERR;
	  }
	  else
	  {
		  /* Do Nothing */
	  }

	  return Local_Error;
}

void RCC_SetSystemClock72MHz(void)
{
	/* HCLK = SYSCLK */
	RCC->CFGR |= (u32)RCC_CFGR_HPRE_DIV1;

	/* PCLK2 = HCLK */
	RCC->CFGR |= (u32)RCC_CFGR_PPRE2_DIV1;

	/* PCLK1 = HCLK */
	RCC->CFGR |= (u32)RCC_CFGR_PPRE1_DIV2;

	/*  PLL configuration: PLLCLK = HSE * 9 = 72 MHz */
	RCC->CFGR &= (u32)((u32)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
										RCC_CFGR_PLLMULL));
	///////////////////////////
	RCC->CFGR |= (u32)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);

	//////////////////////////////////////////////////////////////////////////
	// Select HSI 8MHz to get 36MHz SYSCLK
	//RCC->CFGR |= (u32)(RCC_CFGR_PLLMULL9);
	//////////////////////////////////////////////////////////////////////////


	/* Enable PLL */
	RCC->CR |= RCC_CR_PLLON;

	/* Wait till PLL is ready */
	while((RCC->CR & RCC_CR_PLLRDY) == 0)
	{
	}

	/* Select PLL as system clock source */
	RCC->CFGR &= (u32)((u32)~(RCC_CFGR_SW));
	RCC->CFGR |= (u32)RCC_CFGR_SW_PLL;

	/* Wait till PLL is used as system clock source */
	while ((RCC->CFGR & (u32)RCC_CFGR_SWS) != (u32)0x08)
	{
	}
}

u32 RCC_GetSystemCoreClock(void)
{
	u32 SystemCoreClock;
	u32 tmp = 0, pllmull = 0, pllsource = 0;

	/* Get SYSCLK source -------------------------------------------------------*/
	tmp = RCC->CFGR & RCC_CFGR_SWS;

	switch (tmp)
	{
	case 0x00:  /* HSI used as system clock */
	  SystemCoreClock = HSI_VALUE;
	  break;
	case 0x04:  /* HSE used as system clock */
	  SystemCoreClock = HSE_VALUE;
	  break;
	case 0x08:  /* PLL used as system clock */

	  /* Get PLL clock source and multiplication factor ----------------------*/
	  pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
	  pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
	  pllmull = ( pllmull >> 18) + 2;

	  if (pllsource == 0x00)
	  {
		/* HSI oscillator clock divided by 2 selected as PLL clock entry */
		SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
	  }
	  else
	  {
		/* HSE selected as PLL clock entry */
		if ((RCC->CFGR & RCC_CFGR_PLLXTPRE) != (u32)RESET)
		{/* HSE oscillator clock divided by 2 */
		  SystemCoreClock = (HSE_VALUE >> 1) * pllmull;
		}
		else
		{
		  SystemCoreClock = HSE_VALUE * pllmull;
		}
	  }
	  break;

	default:
	  SystemCoreClock = HSI_VALUE;
	  break;
	  }

	  /* Compute HCLK clock frequency ----------------*/
	  /* Get HCLK prescaler */
	  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
	  /* HCLK clock frequency */
	  SystemCoreClock >>= tmp;

	  return SystemCoreClock;
}

void RCC_EnableGPIOA(void)
{
	RCC->APB2ENR	|= RCC_APB2ENR_IOPAEN;
}

void RCC_ResetGPIOA(void)
{
	RCC->APB2RSTR	|= RCC_APB2RSTR_IOPARST;
	RCC->APB2RSTR = 0;
}

void RCC_DisableGPIOA(void)
{
	RCC->APB2ENR	&= ~RCC_APB2ENR_IOPAEN;
}

void RCC_EnableGPIOB(void)
{
	RCC->APB2ENR	|= RCC_APB2ENR_IOPBEN;
}

void RCC_ResetGPIOB(void)
{
	RCC->APB2RSTR	|= RCC_APB2RSTR_IOPBRST;
	RCC->APB2RSTR = 0;
}

void RCC_DisableGPIOB(void)
{
	RCC->APB2ENR	&= ~RCC_APB2ENR_IOPBEN;
}

void RCC_EnableGPIOC(void)
{
	RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN;
}

void RCC_ResetGPIOC(void)
{
	RCC->APB2RSTR	|= RCC_APB2RSTR_IOPCRST;
	RCC->APB2RSTR = 0;
}

void RCC_DisableGPIOC(void)
{
	RCC->APB2ENR	&= ~RCC_APB2ENR_IOPCEN;
}

void RCC_EnableUART(void)
{
	RCC->APB2ENR	|= RCC_APB2ENR_USART1EN;
}

void RCC_ResetUART(void)
{
	RCC->APB2RSTR	|= RCC_APB2RSTR_USART1RST;
	RCC->APB2RSTR = 0;
}

void RCC_DisableUART(void)
{
	RCC->APB2ENR	&= ~RCC_APB2ENR_USART1EN;
}

void RCC_EnableDMA(void)
{
	RCC->AHBENR	|= RCC_AHBENR_DMA1EN;
}

void RCC_DisableDMA(void)
{
	RCC->AHBENR	&= ~RCC_AHBENR_DMA1EN;
}



