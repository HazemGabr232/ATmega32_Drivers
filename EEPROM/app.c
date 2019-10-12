/*
 * app.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "HAL/EEPROM.h"
#include "MCAL/DIO.h"
#include "util/delay.h"

int main(void){
	u8 data;
	EEPROM_Init();
	DIO_vidSetPortDir(DPORT, OUTPUT);
	if (EEPROM_WriteByte(0x00, 0xAA)== OK){
		_delay_ms(20);
		if(EEPROM_ReadByte(0x00, &data)==OK){
			if (data == 0xAA)
				//read == write
				DIO_vidSetPinValue(DPORT, PIN7, HIGH);
			else
				DIO_vidSetPinValue(DPORT, PIN6, HIGH);
		}
		else
			//read failed
			DIO_vidSetPinValue(DPORT, PIN5, HIGH);
	}
	else
		//write failed
		DIO_vidSetPinValue(DPORT, PIN4, HIGH);


	while (1){


	}
	return 0;
}


