/*
 * interrupt.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Hazem
 */

#ifndef MCAL_EXINTERRUPT_H_
#define MCAL_EXINTERRUPT_H_

#include "../STD_Types.h"
#include "../macros.h"
#include "EXinterrupt_CFG.h"

/*MODES*/
#define INT0_LOW 		0x00
#define INT0_CHANGE 	0x01
#define INT0_FALLING 	0x02
#define INT0_RISING 	0x03

#define INT1_LOW 		0x00
#define INT1_CHANGE 	0x04
#define INT1_FALLING 	0x08
#define INT1_RISING 	0x0C

#define INT2_FALLING 	0x00
#define INT2_RISING 	0x40

#define INT0 		0
#define INT1		1
#define INT2		2


#define GLOBAL_INTERRUPT_ENABLE()   (SET_BIT(SREG,7))
#define GLOBAL_INTERRUPT_DISABLE()  (CLEAR_BIT(SREG,7))

void ExInterrupt_vidEnable(u8 interrupt_number, u8 mode);
void ExInterrupt_vidDisable(u8 interrupt_number);
void ExInterrupt_setCallBackFun(u8 interrupt_number, void (*ptr)(void) );


#endif /* MCAL_EXINTERRUPT_H_ */
