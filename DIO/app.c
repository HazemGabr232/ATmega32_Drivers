/*
 * app.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Hazem
 */
#define F_CPU 8000000UL
#include "DIO.h"
#include "STD_TYPES.h"
#include "MACROS.h"
 int main() {
	 DIO_vidSetPortDir(APORT,ALL_OUTPUT);
	 while(1){

	 }


	return 0;
}
