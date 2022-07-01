/*
 * SCB_private.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_SCB_SCB_PRIVATE_H_
#define MCAL_SCB_SCB_PRIVATE_H_

#define SCB_BASE            (0xE000E000UL +  0x0D00UL)

#define NVIC_PRIO_BITS          4

/* SCB Application Interrupt and Reset Control Register Definitions */
#define SCB_AIRCR_VECTKEY_Pos              16                                             /*!< SCB AIRCR: VECTKEY Position */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFUL << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY Mask */

#define SCB_AIRCR_VECTKEYSTAT_Pos          16                                             /*!< SCB AIRCR: VECTKEYSTAT Position */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT Mask */

#define SCB_AIRCR_ENDIANESS_Pos            15                                             /*!< SCB AIRCR: ENDIANESS Position */
#define SCB_AIRCR_ENDIANESS_Msk            (1UL << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS Mask */

#define SCB_AIRCR_PRIGROUP_Pos              8                                             /*!< SCB AIRCR: PRIGROUP Position */
#define SCB_AIRCR_PRIGROUP_Msk             (7UL << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP Mask */

#define SCB_AIRCR_SYSRESETREQ_Pos           2                                             /*!< SCB AIRCR: SYSRESETREQ Position */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1UL << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ Mask */

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1                                             /*!< SCB AIRCR: VECTCLRACTIVE Position */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1UL << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE Mask */

#define SCB_AIRCR_VECTRESET_Pos             0                                             /*!< SCB AIRCR: VECTRESET Position */
#define SCB_AIRCR_VECTRESET_Msk            (1UL << SCB_AIRCR_VECTRESET_Pos)               /*!< SCB AIRCR: VECTRESET Mask */


/** \brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  __I  u32 CPUID;                   /*!< Offset: 0x000 (R/ )  CPUID Base Register                                   */
  __IO u32 ICSR;                    /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register                  */
  __IO u32 VTOR;                    /*!< Offset: 0x008 (R/W)  Vector Table Offset Register                          */
  __IO u32 AIRCR;                   /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register      */
  __IO u32 SCR;                     /*!< Offset: 0x010 (R/W)  System Control Register                               */
  __IO u32 CCR;                     /*!< Offset: 0x014 (R/W)  Configuration Control Register                        */
  __IO u8  SHP[12];                 /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IO u32 SHCSR;                   /*!< Offset: 0x024 (R/W)  System Handler Control and State Register             */
  __IO u32 CFSR;                    /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register                    */
  __IO u32 HFSR;                    /*!< Offset: 0x02C (R/W)  HardFault Status Register                             */
  __IO u32 DFSR;                    /*!< Offset: 0x030 (R/W)  Debug Fault Status Register                           */
  __IO u32 MMFAR;                   /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register                      */
  __IO u32 BFAR;                    /*!< Offset: 0x038 (R/W)  BusFault Address Register                             */
  __IO u32 AFSR;                    /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register                       */
  __I  u32 PFR[2];                  /*!< Offset: 0x040 (R/ )  Processor Feature Register                            */
  __I  u32 DFR;                     /*!< Offset: 0x048 (R/ )  Debug Feature Register                                */
  __I  u32 ADR;                     /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register                            */
  __I  u32 MMFR[4];                 /*!< Offset: 0x050 (R/ )  Memory Model Feature Register                         */
  __I  u32 ISAR[5];                 /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register                   */
  	   u32 RESERVED0[5];
  __IO u32 CPACR;                   /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register                   */
} SCB_Type;

#define SCB                 ((SCB_Type *)SCB_BASE)   /*!< SCB configuration struct           */

#endif /* MCAL_SCB_SCB_PRIVATE_H_ */
