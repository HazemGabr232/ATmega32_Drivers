/*
 * app.c
 *
 *  Created on: Oct 5, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/USART.h"
#include "MCAL/DIO.h"

int main(void){
	u8 val, state;
	USART_vidInit();
	DIO_vidSetPinDirection(CPORT, PIN0, OUTPUT);
	DIO_vidSetPinDirection(DPORT, PIN1, INPUT);
	//DIO_vidSetPinValue(CPORT, PIN0, HIGH);
	while(1){
		state =  USART_u16Receive(&val);
		if (state == OK){
			if (val == '2'){
				DIO_vidSetPinValue(CPORT, PIN0, HIGH);
			}
			if (val == '1'){
				DIO_vidSetPinValue(CPORT, PIN0, LOW);
			}
		}
	}
}
