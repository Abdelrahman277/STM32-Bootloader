/*
 * Core_interface.h
 *
 *  Created on: Dec 19, 2021
 *      Author: Mohammed Ali
 */

#ifndef MCAL_CORE_CORE_INTERFACE_H_
#define MCAL_CORE_CORE_INTERFACE_H_

#if !defined __ASM
#define __ASM asm
#endif

#if !defined __INLINE
#define __INLINE inline
#endif

#if !defined __VOLATILE
#define __VOLATILE inline
#endif

static __INLINE void __enable_irq()               { __ASM volatile ("cpsie i"); }
static __INLINE void __disable_irq()              { __ASM volatile ("cpsid i"); }
static __INLINE void __enable_fault_irq()         { __ASM volatile ("cpsie f"); }
static __INLINE void __disable_fault_irq()        { __ASM volatile ("cpsid f"); }
static __INLINE void __NOP()                      { __ASM volatile ("nop"); }
static __INLINE void __WFI()                      { __ASM volatile ("wfi"); }
static __INLINE void __WFE()                      { __ASM volatile ("wfe"); }
static __INLINE void __SEV()                      { __ASM volatile ("sev"); }
static __INLINE void __ISB()                      { __ASM volatile ("isb"); }
static __INLINE void __DSB()                      { __ASM volatile ("dsb"); }
static __INLINE void __DMB()                      { __ASM volatile ("dmb"); }
static __INLINE void __CLREX()                    { __ASM volatile ("clrex"); }

#endif /* MCAL_CORE_CORE_INTERFACE_H_ */
