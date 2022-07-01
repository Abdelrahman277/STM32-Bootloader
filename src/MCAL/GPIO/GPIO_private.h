/*
 * GPIO_private.h
 *
 *  Created on: Dec 15, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE            ((u32)0x40010800)
#define GPIOB_BASE            ((u32)0x40010C00)
#define GPIOC_BASE            ((u32)0x40011000)

/* GPIO data type */
typedef struct
{
  __IO u32 CRL;
  __IO u32 CRH;
  __IO u32 IDR;
  __IO u32 ODR;
  __IO u32 BSRR;
  __IO u32 BRR;
  __IO u32 LCKR;
} GPIO_TypeDef;



#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
