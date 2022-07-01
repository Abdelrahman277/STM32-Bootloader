/*
 * GPIO_interface.h
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/* Existing GPIO units */
#define GPIOA               ((void *) 0x40010800)
#define GPIOB               ((void *) 0x40010C00)
#define GPIOC               ((void *) 0x40011000)

/* GPIO pins */
#define GPIO_PIN_0									0
#define GPIO_PIN_1									1
#define GPIO_PIN_2									2
#define GPIO_PIN_3									3
#define GPIO_PIN_4									4
#define GPIO_PIN_5									5
#define GPIO_PIN_6									6
#define GPIO_PIN_7									7
#define GPIO_PIN_8									8
#define GPIO_PIN_9									9
#define GPIO_PIN_10									10
#define GPIO_PIN_11									11
#define GPIO_PIN_12									12
#define GPIO_PIN_13									13
#define GPIO_PIN_14									14
#define GPIO_PIN_15									15

/* GPIO mode */
#define GPIO_INPUT_ANALOG					0
#define GPIO_INPUT_FLOATING					1
#define GPIO_INPUT_PULLUP_PULLDOWN			2
#define GPIO_OUTPUT_GP_PUSH_PULL			4
#define GPIO_OUTPUT_GP_OPEN_DRAIN			5
#define GPIO_OUTPUT_AF_PUSH_PULL  			6
#define GPIO_OUTPUT_AF_OPEN_DRAIN			7

/* GPIO pin data type */
typedef struct
{
	volatile void * Port;
	u32 Pin;
	u32 Mode;
} GPIO_t;

/* Functions prototypes */
STD_ERR GPIO_Init(GPIO_t * gpio);
STD_ERR GPIO_SetPinValue(volatile void * Port, u32 Pin, u32 Value);
STD_ERR GPIO_WritePort(volatile void * Port, u32 Value);
u32 GPIO_GetPinValue(volatile void * Port, u32 Pin);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
