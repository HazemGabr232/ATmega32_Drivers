/*
 * Timer.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Hazem
 */

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_

#include "../STD_Types.h"

#define TIMER0		0
#define TIMER1		1
#define TIMER2		2

/*PRESCALER VALUES*/
#define SCALER64	0
#define SCALER256	1
#define SCALER1024	2

/*MODES*/
#define OVERFLOW	0
#define COMPARE 	1
#define COMPAREA	2
#define COMPAREB	3
#define CAPTURE		4


void Timer_vidEnableTimer(u8 timer_no, u8 prescaller, u8 mode);
void Timer_vidDisableTimer(u8 timer_no);
void Timer_setCallBackFun(u8 timer_no,u8 mode , void (*ptr)(void) );


#endif /* MCAL_TIMER_H_ */
