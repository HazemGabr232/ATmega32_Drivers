/*
 * USART_CFG.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Hazem
 */

#ifndef MCAL_USART_CFG_H_
#define MCAL_USART_CFG_H_
#include "../STD_Types.h"

#define UDR			*((volatile u8*)0x2C)
#define UCSRA		*((volatile u8*)0x2B)
#define UCSRB		*((volatile u8*)0x2A)
#define UCSRC		*((volatile u8*)0x40)
#define UBRRH		*((volatile u8*)0x40)
#define UBRRL		*((volatile u8*)0x29)


#endif /* MCAL_USART_CFG_H_ */
