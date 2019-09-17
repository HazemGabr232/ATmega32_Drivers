/*
 * app.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Hazem
 */
#define F_CPU 8000000UL

#include "STD_Types.h"
#include "macros.h"
#include "MCAL/Timer.h"
#include "MCAL/DIO.h"
#include <util/delay.h>

u16 pos =800;
int main(void){
	Timer_vidEnableTimer(TIMER1, SCALER8, FAST_PWM);
	Timer_vidSetPWM(20000, pos);
	DIO_vidSetPinDirection(DPORT, PIN5, OUTPUT);
	while(1){
		Timer_vidSetPWM(20000, pos+=5);
		if (pos >=2300){
			pos=1000;
			_delay_ms(500);
		}
		_delay_ms(50);
	}
	return 0;
}
