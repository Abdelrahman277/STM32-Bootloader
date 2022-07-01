/*
 * GPIO_program.c
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */

#include "STD_Types.h"
#include "Bit_Math.h"

#include "GPIO_private.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"

STD_ERR GPIO_Init(GPIO_t * gpio)
{
	STD_ERR Local_ERROR = NO_ERR;
	__IO u32 * Register = &(((GPIO_TypeDef *)(gpio->Port))->CRL);
	u32 Local_Mode = gpio->Mode;
	u32 Local_Pin = gpio->Pin;

	if(Local_Pin <= GPIO_PIN_15)
	{
		if(Local_Pin >= GPIO_PIN_8)
		{
			Local_Pin -= GPIO_PIN_8;
			Register = &(((GPIO_TypeDef *)(gpio->Port))->CRH);
		}

		if(Local_Mode <= GPIO_INPUT_PULLUP_PULLDOWN)
		{
			*Register &= ~(0x0F << (Local_Pin * 4));
			*Register |= (Local_Mode << ((Local_Pin * 4) + 2));
		}
		else if(Local_Mode <= GPIO_OUTPUT_AF_OPEN_DRAIN)
		{
			*Register &= ~(0x0F << (Local_Pin * 4));
			*Register |= ((Local_Mode & 0b11) << ((Local_Pin * 4) + 2));
			*Register |= (GPIO_SPEED << (Local_Pin * 4));
		}
		else
		{
			Local_ERROR = ERR;
		}
	}
	else
	{
		Local_ERROR = ERR;
	}
	return Local_ERROR;
}


STD_ERR GPIO_SetPinValue(volatile void * Port, u32 Pin, u32 Value)
{
	STD_ERR Local_ERROR = ERR;
	if(Pin <= GPIO_PIN_15)
	{
		if(Value == HIGH)
		{
			SET_BIT((((GPIO_TypeDef *)Port)->ODR), Pin);
		}
		else if(Value == LOW)
		{
			CLR_BIT((((GPIO_TypeDef *)Port)->ODR), Pin);
		}
		else
		{
			/* Do Nothing */
		}

		if(GET_BIT((((GPIO_TypeDef *)Port)->ODR), Pin) == Value)
		{
			Local_ERROR = NO_ERR;
		}

	}
	else
	{
		/* Do Nothing */
	}
	return Local_ERROR;

}

STD_ERR GPIO_WritePort(volatile void * Port, u32 Value)
{
	STD_ERR Local_ERROR = ERR;

	((GPIO_TypeDef *)Port)->ODR = Value;
	if(((GPIO_TypeDef *)Port)->ODR == Value)
	{
		Local_ERROR = NO_ERR;
	}
	else
	{
		/* Do Nothing */
	}
	return Local_ERROR;

}

u32 GPIO_GetPinValue(volatile void * Port, u32 Pin)
{
	return GET_BIT((((GPIO_TypeDef *)Port)->IDR), Pin);
}
