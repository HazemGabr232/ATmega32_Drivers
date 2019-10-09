/*
 * USART.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Hazem
 */

#ifndef MCAL_USART_H_
#define MCAL_USART_H_
#include "../STD_Types.h"


#define OK		1
#define NOK		0

void USART_vidInit(void);
u8 USART_u16Receive(u8* ret_vlaue_ptr);
void  USART_vidSend(u8 data);

#endif /* MCAL_USART_H_ */
