/*
 * Timer_CFG.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Hazem
 */

#ifndef MCAL_TIMER_CFG_H_
#define MCAL_TIMER_CFG_H_

#include "../STD_Types.h"

#define TCCR0		*((volatile u8*)0x53)
#define TCNT0		*((volatile u8*)0x52)
#define OCR0		*((volatile u8*)0x5C)
#define TIMSK		*((volatile u8*)0x59)

#define TCCR1A		*((volatile u8*)0x4F)
#define TCCR1B		*((volatile u8*)0x4E)
#define TCNT1		*((volatile u16*)0x4C)
#define OCR1A		*((volatile u16*)0x4A)
#define OCR1B		*((volatile u16*)0x48)
#define ICR1		*((volatile u16*)0x46)

#define TCCR2		*((volatile u8*)0x45)
#define TCNT2		*((volatile u8*)0x44)
#define OCR2		*((volatile u8*)0x43)

#define VECT_TIMER0_COMP	10
#define VECT_TIMER0_OVF		11

#define VECT_TIMER1_CAPT	6
#define VECT_TIMER1_COMPA	7
#define VECT_TIMER1_COMPB	8
#define VECT_TIMER1_OVF		9

#define VECT_TIMER2_COMP	4
#define VECT_TIMER2_OVF		5

#endif /* MCAL_TIMER_CFG_H_ */
