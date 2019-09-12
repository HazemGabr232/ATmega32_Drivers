/*
 * app.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Hazem
 */

#include "STD_Types.h"
#include "macros.h"
#include "MCAL/Timer.h"
#include "MCAL/DIO.h"

u8 flag =0 ;

void callbackfun(void){
	DIO_vidSetPinValue(APORT, PIN0, flag);
	flag ^= 1;
}

int main(void){
	DIO_vidSetPinDirection(APORT, PIN0, OUTPUT);
	Timer_vidEnableTimer(TIMER1, SCALER256, COMPAREA);
	Timer_setCallBackFun(TIMER1, COMPAREA, callbackfun);
	while(1){

	}
	return 0;
}
