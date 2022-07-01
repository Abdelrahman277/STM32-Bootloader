/*
 * Flash_interface.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_FLASH_FLASH_INTERFACE_H_
#define MCAL_FLASH_FLASH_INTERFACE_H_

#define FLASH_BASE            ((u32)0x08000000) /*!< FLASH base address in the alias region */
#define FLASH_LENGTH          ((u32)0x00004000) /*!< FLASH base address in the alias region */


#define  FLASH_LATENCY_0                 ((u8)0x00)               /*!< Bit 0 */
#define  FLASH_LATENCY_1                 ((u8)0x01)               /*!< Bit 0 */
#define  FLASH_LATENCY_2                 ((u8)0x02)               /*!< Bit 1 */


STD_ERR Flash_WriteWord(void * Address, u32 Word);
STD_ERR Flash_WriteData(volatile void * DestAddress, volatile void * SrcAddress, u16 NumberOfHalfWords);
STD_ERR Flash_ErasePage(u32 PageAddress);
void Flash_EraseMass(void);
STD_ERR Flash_Unlock(void);
STD_ERR Flash_Lock(void);
void Flash_EnablePrefetchBuffer(void);
STD_ERR Flash_SetLatency(u8 Latency);


#endif /* MCAL_FLASH_FLASH_INTERFACE_H_ */
