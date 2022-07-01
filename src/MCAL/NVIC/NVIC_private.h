/*
 * NVIC_private.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_
#define NVIC_BASE           (0xE000E000UL +  0x0100UL)

#define NVIC_PRIO_BITS          4

/* Structure type to access the Nested Vectored Interrupt Controller (NVIC). */
typedef struct
{
  __IO u32 ISER[8];                 /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
       u32 RESERVED0[24];
  __IO u32 ICER[8];                 /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
       u32 RSERVED1[24];
  __IO u32 ISPR[8];                 /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
       u32 RESERVED2[24];
  __IO u32 ICPR[8];                 /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
       u32 RESERVED3[24];
  __IO u32 IABR[8];                 /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
       u32 RESERVED4[56];
  __IO u8  IP[240];                 /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
       u32 RESERVED5[644];
  __O  u32 STIR;                    /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;

#define NVIC	((NVIC_Type *) NVIC_BASE)   /*!< NVIC configuration struct          */

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
