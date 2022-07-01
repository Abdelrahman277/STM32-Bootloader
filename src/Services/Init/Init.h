/*
 * Init.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_INIT_INIT_H_
#define SERVICES_INIT_INIT_H_

#define SYSCLK_FREQ_72MHz  72000000

#define VECT_TAB_OFFSET  0x0 /*!< Vector Table base offset field.
                                  This value must be a multiple of 0x200. */

extern void SystemInit(void);

#endif /* SERVICES_INIT_INIT_H_ */
