/*
 * config.h
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohammed Ali
 */

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define CFG_DATA_BUFFER_SIZE		10240U


#define CMD_FLASH_LOCK			0x01
#define CMD_FLASH_UNLOCK		0x02
#define CMD_DATA_WRITE			0x03
#define CMD_RAM_APP_EXEC		0x04
#define CMD_SECTOR_ERASE		0x05
#define CMD_JUMP				0x06

#define REPLY_ACK					0x10
#define REPLY_NACK					0x11
#define REPLY_DATA					0x12
#define	REPLY_ERR_WRITE_DATA		0x13
#define REPLY_READY					0xFE

#endif /* APP_CONFIG_H_ */
