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


int main(void) {
	DIO_vidSetPinDirection(APORT, PIN0, OUTPUT);
	DIO_vidSetPinDirection(DPORT, PIN2, INPUT);
	DIO_vidSetPinValue(DPORT, PIN2, HIGH);

	ExInterrupt_vidEnable(INT0, INT0_FALLING);

	while(1){

	}
	return 0 ;
}


ISR(VECT_INT0){
DIO_vidSetPinValue(APORT, PIN0, HIGH);
//_delay_ms(500);
//DIO_vidSetPinValue(APORT, PIN0, LOW);
}
