/*
 * Flash_private.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_FLASH_FLASH_PRIVATE_H_
#define MCAL_FLASH_FLASH_PRIVATE_H_


#define FLASH_R_BASE          ((u32)0x40022000) /*!< Flash registers base address */
#define OB_BASE               ((u32)0x1FFFF800) /*!< Flash Option Bytes base address */


/*******************  Bit definition for FLASH_ACR register  ******************/
#define  FLASH_ACR_LATENCY                   ((u8)0x03)               /*!< LATENCY[2:0] bits (Latency) */

#define  FLASH_ACR_HLFCYA                    ((u8)0x08)               /*!< Flash Half Cycle Access Enable */
#define  FLASH_ACR_PRFTBE                    ((u8)0x10)               /*!< Prefetch Buffer Enable */
#define  FLASH_ACR_PRFTBS                    ((u8)0x20)               /*!< Prefetch Buffer Status */

/******************  Bit definition for FLASH_KEYR register  ******************/
#define  FLASH_KEYR_FKEYR                    ((u32)0xFFFFFFFF)        /*!< FPEC Key */

/******************  FLASH Keys  **********************************************/
#define RDP_Key                  ((u16)0x00A5)
#define FLASH_KEY1               ((u32)0x45670123)
#define FLASH_KEY2               ((u32)0xCDEF89AB)

/*****************  Bit definition for FLASH_OPTKEYR register  ****************/
#define  FLASH_OPTKEYR_OPTKEYR               ((u32)0xFFFFFFFF)        /*!< Option Byte Key */

/******************  Bit definition for FLASH_SR register  *******************/
#define  FLASH_SR_BSY                        ((u8)0x01)               /*!< Busy */
#define  FLASH_SR_PGERR                      ((u8)0x04)               /*!< Programming Error */
#define  FLASH_SR_WRPRTERR                   ((u8)0x10)               /*!< Write Protection Error */
#define  FLASH_SR_EOP                        ((u8)0x20)               /*!< End of operation */

/*******************  Bit definition for FLASH_CR register  *******************/
#define  FLASH_CR_PG                         ((u16)0x0001)            /*!< Programming */
#define  FLASH_CR_PER                        ((u16)0x0002)            /*!< Page Erase */
#define  FLASH_CR_MER                        ((u16)0x0004)            /*!< Mass Erase */
#define  FLASH_CR_OPTPG                      ((u16)0x0010)            /*!< Option Byte Programming */
#define  FLASH_CR_OPTER                      ((u16)0x0020)            /*!< Option Byte Erase */
#define  FLASH_CR_STRT                       ((u16)0x0040)            /*!< Start */
#define  FLASH_CR_LOCK                       ((u16)0x0080)            /*!< Lock */
#define  FLASH_CR_OPTWRE                     ((u16)0x0200)            /*!< Option Bytes Write Enable */
#define  FLASH_CR_ERRIE                      ((u16)0x0400)            /*!< Error Interrupt Enable */
#define  FLASH_CR_EOPIE                      ((u16)0x1000)            /*!< End of operation interrupt enable */

/*******************  Bit definition for FLASH_AR register  *******************/
#define  FLASH_AR_FAR                        ((u32)0xFFFFFFFF)        /*!< Flash Address */

/* Flash data type */
typedef struct
{
  __IO u32 ACR;
  __IO u32 KEYR;
  __IO u32 OPTKEYR;
  __IO u32 SR;
  __IO u32 CR;
  __IO u32 AR;
  __IO u32 RESERVED;
  __IO u32 OBR;
  __IO u32 WRPR;
} FLASH_TypeDef;

/* Flash Control Register */
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

#endif /* MCAL_FLASH_FLASH_PRIVATE_H_ */
