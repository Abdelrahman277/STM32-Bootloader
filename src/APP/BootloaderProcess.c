/*
 * BootloaderProcess.c
 *
 *  Created on: Dec 18, 2021
 *      Author: Mohammed Ali
 */

/* Includes */
#include "STD_Types.h"
#include "MCAL/SCB/SCB_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/Flash/Flash_interface.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/Core/Core_interface.h"
#include "HAL/Interrupts/Interrupts_interface.h"

#include "Services/MTP/MTP.h"

#include "config.h"
#include "BootloaderProcess.h"
/* Private typedef */
/* Private define  */


/* Private macro */
/* Private variables */
u8 __attribute__((section (".BufferSection"))) buffer[CFG_DATA_BUFFER_SIZE];
MTP_MSG_t msg;
u8 CMD;
/* Private function prototypes */
static void JumpToApp(u32 address, u32 sp) __attribute__((naked));
static void Command_Process(void);
static void HardwareReset(void);
static void Reply(u8 msgID);
/* Private functions */

/**
**===========================================================================
**
**  Abstract: Command Interpreter Process
**
**===========================================================================
*/

void Bootloader_Main(void)
{

	Reply(REPLY_READY);

	while(1)
	{
		msg.Buffer = buffer;
		if(MTP_ReceiveData(&msg, 0x00077ADB) == NO_ERR)
		{
			CMD = msg.ID;
			Command_Process();
		}
		else
		{

		}
	}

}

void Command_Process(void)
{
	u32 address;
	u32 sp;
	switch (CMD)
	{
	case CMD_FLASH_LOCK:
		Flash_Lock();
		Reply(REPLY_ACK);
		break;

	case CMD_FLASH_UNLOCK:
		Flash_Unlock();
		Reply(REPLY_ACK);
		break;

	case CMD_DATA_WRITE:
		if(Flash_WriteData((void *)*(u32*)(&(msg.Buffer[0])), &(msg.Buffer[4]), ((msg.length - 4) / 2) +  1) == NO_ERR)
		{
			Reply(REPLY_ACK);
		}
		else
		{
			Reply(REPLY_ERR_WRITE_DATA);
		}
		break;

	case CMD_RAM_APP_EXEC:
		address = (u32)&buffer;
		sp = *((u32 *) address);
		__disable_irq();
		if((sp & 0xF0000000) == 0x20000000)
		{
			HardwareReset();

			SCB_SetVectorTableOffset(address);

			__enable_irq();

			JumpToApp(*((u32 *) (address + 4)), sp);
		}
		break;

	case CMD_SECTOR_ERASE:
		if(Flash_ErasePage(*(u32*)(&(msg.Buffer[0]))) == NO_ERR)
		{
			Reply(REPLY_ACK);
		}
		else
		{
			Reply(REPLY_NACK);
		}
		break;

	case CMD_JUMP:
		address = *(u32*)(&(msg.Buffer[0]));
		sp = *((u32 *) address);
		__disable_irq();
		if((sp & 0xF0000000) == 0x20000000)
		{
			HardwareReset();

			SCB_SetVectorTableOffset(address);

			JumpToApp(*((u32 *) (address + 4)), sp);
		}
		break;
	}
}

static void HardwareReset(void)
{
	RCC_ResetGPIOA();
	RCC_ResetUART();
	RCC_DisableGPIOA();
	RCC_DisableUART();
	RCC_DisableDMA();

	Interrupts_DisableIRQ(USART1_IRQn);
	Interrupts_DisableIRQ(DMA1_Channel4_IRQn);
	Interrupts_DisableIRQ(DMA1_Channel5_IRQn);
	RCCSystemInit();
}

static void JumpToApp(u32 address, u32 sp)
{
	__ASM("msr msp, r1");
	__ASM("bx r0");
}

static void Reply(u8 msgID)
{
	msg.ID = msgID;
	msg.length = 0;
	MTP_SendData(&msg);
}
