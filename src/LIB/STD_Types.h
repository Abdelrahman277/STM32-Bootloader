/*
 * STD_Types.h
 *
 *  Created on: Aug 17, 2021
 *      Author: Mohammed Ali
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_

/* User Defined data types */
typedef __INT8_TYPE__ s8;
typedef __INT16_TYPE__ s16;
typedef __INT32_TYPE__ s32;
typedef __UINT8_TYPE__ u8;
typedef __UINT16_TYPE__ u16;
typedef __UINT32_TYPE__ u32;
typedef float f32;
typedef double f64;
typedef long long s64;
typedef long double f128;

#define   __I     volatile const       /*!< defines 'read only' permissions		 */
#define     __O     volatile             /*!< defines 'write only' permissions	 */
#define     __IO    volatile           /*!< defines 'read / write' permissions   */

#define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */
#define     __VOLATILE    volatile
#define     __ASM    asm

typedef enum {
 NO_ERR = 0,
 ERR	= 1
} STD_ERR;

typedef enum {RESET = 0, SET = !RESET} STD_Flag;

#define HIGH	1
#define LOW		0

#define TRUE	1
#define FALSE	0

#endif /* LIB_STD_TYPES_H_ */
