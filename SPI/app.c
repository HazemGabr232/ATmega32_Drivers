/*
 * app.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/SPI.h"

u8 x = 20;

int main(void){
	SPI_vidInit(MASTER);
	SPI_vidSend(x);

}
