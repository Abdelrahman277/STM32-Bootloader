/*
 * Bit_Math.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Mohammed Ali
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))
#define TOG_BIT(VAR,BITNO) (VAR) ^=  (1 << (BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 1)
#define IS_BIT_SET(VAR,BITNO) ((VAR >> BITNO) & 1)
#define IS_BIT_CLR(VAR,BITNO) (!((VAR >> BITNO) & 1))

#endif /* LIB_BIT_MATH_H_ */
