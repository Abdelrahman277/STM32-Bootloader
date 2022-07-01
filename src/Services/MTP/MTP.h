/*
 * MTP.h
 *
 *  Created on: Dec 16, 2021
 *      Author: Mohammed Ali
 */

#ifndef SERVICES_MTP_MTP_H_
#define SERVICES_MTP_MTP_H_

typedef struct
{
	u8 ID;
	u8 * Buffer;
	u16 length;
} MTP_MSG_t;

void MTP_Init(void);
STD_ERR MTP_ReceiveData(MTP_MSG_t * msg, u32 CyclesToBreak);
STD_ERR MTP_SendData(MTP_MSG_t * msg);

#endif /* SERVICES_MTP_MTP_H_ */
