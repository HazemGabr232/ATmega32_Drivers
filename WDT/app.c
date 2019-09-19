/*
 * app.c
 *
 *  Created on: Sep 18, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "MCAL/DIO.h"
#include "MCAL/WDT.h"

int main(void){
	DIO_vidSetPinDirection(APORT, PIN7, OUTPUT);
	DIO_vidSetPinValue(APORT, PIN7, HIGH);
	WDT_vidInit(SCALER1s);
	while(1){

	}
	return 0;
}
