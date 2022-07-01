/*
 * Init.c
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */


#include "STD_Types.h"
#include "Bit_Math.h"

#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/Flash/Flash_interface.h"
#include "MCAL/SCB/SCB_interface.h"

#include "Init.h"

#ifdef SYSCLK_FREQ_72MHz
  static void SetSysClockTo72(void);
#endif

/**
  * Setup the microcontroller system
  * Initialize the Embedded Flash Interface, the PLL and update the
  * SystemCoreClock variable.
  */

void SystemInit (void)
{
	RCCSystemInit();

  /* Configure the System clock frequency, HCLK, PCLK2 and PCLK1 prescalers */
  /* Configure the Flash Latency cycles and enable prefetch buffer */
#ifdef SYSCLK_FREQ_72MHz
	SetSysClockTo72();
#endif

	SCB_SetVectorTableOffset(FLASH_BASE | VECT_TAB_OFFSET); /* Vector Table Relocation in Internal FLASH. */
}


#ifdef SYSCLK_FREQ_72MHz
/**
  * Sets System clock frequency to 72MHz and configure HCLK, PCLK2
  * and PCLK1 prescalers.
  */
static void SetSysClockTo72(void)
{
  __IO STD_ERR HSEStatus = ERR;

  HSEStatus = RCC_StartHSE();

  if (HSEStatus == NO_ERR)
  {
	Flash_EnablePrefetchBuffer();
	Flash_SetLatency(FLASH_LATENCY_2);
	RCC_SetSystemClock72MHz();
  }
  else
  { /* If HSE fails to start-up, the application will have wrong clock
         configuration. User can add here some code to deal with this error */
  }
}
#endif
