/*
 * SPI.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Hazem
 */
#include "../STD_Types.h"
#include "../macros.h"
#include "SPI.h"
#include "SPI_CFG.h"
#include "DIO.h"
u8 flag = 0;
void SPI_vidInit(u8 mode){
	SET_BIT(SPCR, 6);
	CLEAR_BIT(SPCR, 5);
	switch(mode){
	case MASTER:
		DIO_vidSetPinDirection(BPORT, PIN4, OUTPUT);
		DIO_vidSetPinDirection(BPORT, PIN5, OUTPUT);
		DIO_vidSetPinDirection(BPORT, PIN7, OUTPUT);
		DIO_vidSetPinDirection(BPORT, PIN6, INPUT);
		SET_BIT(SPCR, 4);
		/*set prescaler 64*/
		SET_BIT(SPCR, 0);
		SET_BIT(SPCR, 1);
		SET_BIT(SPSR, 0);
		break;
	case SLAVE:
		DIO_vidSetPinDirection(BPORT, PIN4, INPUT);
		DIO_vidSetPinDirection(BPORT, PIN5, INPUT);
		DIO_vidSetPinDirection(BPORT, PIN7, INPUT);
		DIO_vidSetPinDirection(BPORT, PIN6, OUTPUT);
		CLEAR_BIT(SPCR, 4);
		break;
	}
}

void SPI_vidSend(u8 data){
	u8 flush;
	SPDR = data;
	while(GET_BIT(SPSR, 7)== 0);
	flush = SPDR;
}

u8 SPI_u8read(void){
	SPDR = 0xFF;
	while(GET_BIT(SPSR, 7)== 0);
	return SPDR;
}
