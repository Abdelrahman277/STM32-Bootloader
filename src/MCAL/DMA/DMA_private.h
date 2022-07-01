/*
 * DMA_private.h
 *
 *  Created on: Feb 27, 2022
 *      Author: Mohammed Ali
 */

#ifndef MCAL_DMA_DMA_PRIVATE_H_
#define MCAL_DMA_DMA_PRIVATE_H_


/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/

#define DMA1_BASE             (0x40020000 + 0x0000)


/*******************  Bit definition for DMA_ISR register  ********************/
#define  DMA_ISR_GIF1                        ((u32)0x00000001)        /*!< Channel 1 Global interrupt flag */
#define  DMA_ISR_TCIF1                       ((u32)0x00000002)        /*!< Channel 1 Transfer Complete flag */
#define  DMA_ISR_HTIF1                       ((u32)0x00000004)        /*!< Channel 1 Half Transfer flag */
#define  DMA_ISR_TEIF1                       ((u32)0x00000008)        /*!< Channel 1 Transfer Error flag */
#define  DMA_ISR_GIF2                        ((u32)0x00000010)        /*!< Channel 2 Global interrupt flag */
#define  DMA_ISR_TCIF2                       ((u32)0x00000020)        /*!< Channel 2 Transfer Complete flag */
#define  DMA_ISR_HTIF2                       ((u32)0x00000040)        /*!< Channel 2 Half Transfer flag */
#define  DMA_ISR_TEIF2                       ((u32)0x00000080)        /*!< Channel 2 Transfer Error flag */
#define  DMA_ISR_GIF3                        ((u32)0x00000100)        /*!< Channel 3 Global interrupt flag */
#define  DMA_ISR_TCIF3                       ((u32)0x00000200)        /*!< Channel 3 Transfer Complete flag */
#define  DMA_ISR_HTIF3                       ((u32)0x00000400)        /*!< Channel 3 Half Transfer flag */
#define  DMA_ISR_TEIF3                       ((u32)0x00000800)        /*!< Channel 3 Transfer Error flag */
#define  DMA_ISR_GIF4                        ((u32)0x00001000)        /*!< Channel 4 Global interrupt flag */
#define  DMA_ISR_TCIF4                       ((u32)0x00002000)        /*!< Channel 4 Transfer Complete flag */
#define  DMA_ISR_HTIF4                       ((u32)0x00004000)        /*!< Channel 4 Half Transfer flag */
#define  DMA_ISR_TEIF4                       ((u32)0x00008000)        /*!< Channel 4 Transfer Error flag */
#define  DMA_ISR_GIF5                        ((u32)0x00010000)        /*!< Channel 5 Global interrupt flag */
#define  DMA_ISR_TCIF5                       ((u32)0x00020000)        /*!< Channel 5 Transfer Complete flag */
#define  DMA_ISR_HTIF5                       ((u32)0x00040000)        /*!< Channel 5 Half Transfer flag */
#define  DMA_ISR_TEIF5                       ((u32)0x00080000)        /*!< Channel 5 Transfer Error flag */
#define  DMA_ISR_GIF6                        ((u32)0x00100000)        /*!< Channel 6 Global interrupt flag */
#define  DMA_ISR_TCIF6                       ((u32)0x00200000)        /*!< Channel 6 Transfer Complete flag */
#define  DMA_ISR_HTIF6                       ((u32)0x00400000)        /*!< Channel 6 Half Transfer flag */
#define  DMA_ISR_TEIF6                       ((u32)0x00800000)        /*!< Channel 6 Transfer Error flag */
#define  DMA_ISR_GIF7                        ((u32)0x01000000)        /*!< Channel 7 Global interrupt flag */
#define  DMA_ISR_TCIF7                       ((u32)0x02000000)        /*!< Channel 7 Transfer Complete flag */
#define  DMA_ISR_HTIF7                       ((u32)0x04000000)        /*!< Channel 7 Half Transfer flag */
#define  DMA_ISR_TEIF7                       ((u32)0x08000000)        /*!< Channel 7 Transfer Error flag */

/*******************  Bit definition for DMA_IFCR register  *******************/
#define  DMA_IFCR_CGIF1                      ((u32)0x00000001)        /*!< Channel 1 Global interrupt clear */
#define  DMA_IFCR_CTCIF1                     ((u32)0x00000002)        /*!< Channel 1 Transfer Complete clear */
#define  DMA_IFCR_CHTIF1                     ((u32)0x00000004)        /*!< Channel 1 Half Transfer clear */
#define  DMA_IFCR_CTEIF1                     ((u32)0x00000008)        /*!< Channel 1 Transfer Error clear */
#define  DMA_IFCR_CGIF2                      ((u32)0x00000010)        /*!< Channel 2 Global interrupt clear */
#define  DMA_IFCR_CTCIF2                     ((u32)0x00000020)        /*!< Channel 2 Transfer Complete clear */
#define  DMA_IFCR_CHTIF2                     ((u32)0x00000040)        /*!< Channel 2 Half Transfer clear */
#define  DMA_IFCR_CTEIF2                     ((u32)0x00000080)        /*!< Channel 2 Transfer Error clear */
#define  DMA_IFCR_CGIF3                      ((u32)0x00000100)        /*!< Channel 3 Global interrupt clear */
#define  DMA_IFCR_CTCIF3                     ((u32)0x00000200)        /*!< Channel 3 Transfer Complete clear */
#define  DMA_IFCR_CHTIF3                     ((u32)0x00000400)        /*!< Channel 3 Half Transfer clear */
#define  DMA_IFCR_CTEIF3                     ((u32)0x00000800)        /*!< Channel 3 Transfer Error clear */
#define  DMA_IFCR_CGIF4                      ((u32)0x00001000)        /*!< Channel 4 Global interrupt clear */
#define  DMA_IFCR_CTCIF4                     ((u32)0x00002000)        /*!< Channel 4 Transfer Complete clear */
#define  DMA_IFCR_CHTIF4                     ((u32)0x00004000)        /*!< Channel 4 Half Transfer clear */
#define  DMA_IFCR_CTEIF4                     ((u32)0x00008000)        /*!< Channel 4 Transfer Error clear */
#define  DMA_IFCR_CGIF5                      ((u32)0x00010000)        /*!< Channel 5 Global interrupt clear */
#define  DMA_IFCR_CTCIF5                     ((u32)0x00020000)        /*!< Channel 5 Transfer Complete clear */
#define  DMA_IFCR_CHTIF5                     ((u32)0x00040000)        /*!< Channel 5 Half Transfer clear */
#define  DMA_IFCR_CTEIF5                     ((u32)0x00080000)        /*!< Channel 5 Transfer Error clear */
#define  DMA_IFCR_CGIF6                      ((u32)0x00100000)        /*!< Channel 6 Global interrupt clear */
#define  DMA_IFCR_CTCIF6                     ((u32)0x00200000)        /*!< Channel 6 Transfer Complete clear */
#define  DMA_IFCR_CHTIF6                     ((u32)0x00400000)        /*!< Channel 6 Half Transfer clear */
#define  DMA_IFCR_CTEIF6                     ((u32)0x00800000)        /*!< Channel 6 Transfer Error clear */
#define  DMA_IFCR_CGIF7                      ((u32)0x01000000)        /*!< Channel 7 Global interrupt clear */
#define  DMA_IFCR_CTCIF7                     ((u32)0x02000000)        /*!< Channel 7 Transfer Complete clear */
#define  DMA_IFCR_CHTIF7                     ((u32)0x04000000)        /*!< Channel 7 Half Transfer clear */
#define  DMA_IFCR_CTEIF7                     ((u32)0x08000000)        /*!< Channel 7 Transfer Error clear */

/*******************  Bit definition for DMA_CCRx register  *******************/
#define  DMA_CCRx_EN                         ((u16)0x0001)            /*!< Channel enable*/
#define  DMA_CCRx_TCIE                       ((u16)0x0002)            /*!< Transfer complete interrupt enable */
#define  DMA_CCRx_HTIE                       ((u16)0x0004)            /*!< Half Transfer interrupt enable */
#define  DMA_CCRx_TEIE                       ((u16)0x0008)            /*!< Transfer error interrupt enable */
#define  DMA_CCRx_DIR                        ((u16)0x0010)            /*!< Data transfer direction */
#define  DMA_CCRx_CIRC                       ((u16)0x0020)            /*!< Circular mode */
#define  DMA_CCRx_PINC                       ((u16)0x0040)            /*!< Peripheral increment mode */
#define  DMA_CCRx_MINC                       ((u16)0x0080)            /*!< Memory increment mode */

#define  DMA_CCRx_PSIZE                      ((u16)0x0300)            /*!< PSIZE[1:0] bits (Peripheral size) */
#define  DMA_CCRx_PSIZE_0                    ((u16)0x0100)            /*!< Bit 0 */
#define  DMA_CCRx_PSIZE_1                    ((u16)0x0200)            /*!< Bit 1 */

#define  DMA_CCRx_MSIZE                      ((u16)0x0C00)            /*!< MSIZE[1:0] bits (Memory size) */
#define  DMA_CCRx_MSIZE_0                    ((u16)0x0400)            /*!< Bit 0 */
#define  DMA_CCRx_MSIZE_1                    ((u16)0x0800)            /*!< Bit 1 */

#define  DMA_CCRx_PL                         ((u16)0x3000)            /*!< PL[1:0] bits(Channel Priority level) */
#define  DMA_CCRx_PL_0                       ((u16)0x1000)            /*!< Bit 0 */
#define  DMA_CCRx_PL_1                       ((u16)0x2000)            /*!< Bit 1 */

#define  DMA_CCRx_MEM2MEM                    ((u16)0x4000)            /*!< Memory to memory mode */

/******************  Bit definition for DMA_CNDTRx register  ******************/
#define  DMA_CNDTRx_NDT                      ((u16)0xFFFF)            /*!< Number of data to Transfer */

/******************  Bit definition for DMA_CPARx register  *******************/
#define  DMA_CPARx_PA                        ((u32)0xFFFFFFFF)        /*!< Peripheral Address */

/******************  Bit definition for DMA_CMARx register  *******************/
#define  DMA_CMARx_MA                        ((u32)0xFFFFFFFF)        /*!< Memory Address */


typedef struct
{
  __IO u32 CCR;
  __IO u32 CNDTR;
  __IO u32 CPAR;
  __IO u32 CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  __IO u32 ISR;
  __IO u32 IFCR;
} DMA_TypeDef;

#define DMA1                ((DMA_TypeDef *) DMA1_BASE)

#endif /* MCAL_DMA_DMA_PRIVATE_H_ */
