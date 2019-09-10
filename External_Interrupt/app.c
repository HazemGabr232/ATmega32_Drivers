/*
 * app.c
 *
 *  Created on: Aug 31, 2019
 *      Author: Hazem
 */

#include "STD_Types.h"
#include "macros.h"
#include "MCAL/ExInterrupt.h"
#include "MCAL/DIO.h"
#include <util/delay.h>

u8 flag=0;

void my_call_back(void){

DIO_vidSetPinValue(APORT, PIN0, flag);
_delay_ms(500);
flag ^= 1;
}

int main(void) {
	DIO_vidSetPinDirection(APORT, PIN0, OUTPUT);
	DIO_vidSetPinDirection(DPORT, PIN2, INPUT);
	DIO_vidSetPinValue(DPORT, PIN2, HIGH);

	ExInterrupt_setCallBackFun(INT0, my_call_back);
	ExInterrupt_vidEnable(INT0, INT0_RISING);

	while(1){

	}
	return 0 ;
}



