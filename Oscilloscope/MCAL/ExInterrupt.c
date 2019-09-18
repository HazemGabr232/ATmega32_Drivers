/*
 * interrupt.c
 *
 *  Created on: Sep 5, 2019
 *      Author: Hazem
 */
#include "../STD_Types.h"
#include "../macros.h"
#include "ExInterrupt.h"
#include "EXinterrupt_CFG.h"
#include "DIO.h"

#define INT0_EN 		0X40
#define INT1_EN 		0X80
#define INT2_EN 		0X20
#define INT0_DISABLE 	0XBF
#define INT1_DISABLE 	0X7F
#define INT2_DISABLE 	0XDF

void (*call_back_fun0)(void);
void (*call_back_fun1)(void);
void (*call_back_fun2)(void);

void ExInterrupt_vidEnable(u8 interrupt_number, u8 mode){
	GLOBAL_INTERRUPT_DISABLE();
	switch(interrupt_number)
	{
		case INT0:
			MCUCR &= 0xFC;	//CLEAR TWO BITS
			MCUCR |= (mode & 0x03);	//SET TWO BITS
			GICR |= INT0_EN; 		//SET TWO BITS
			break;
		case INT1:
			MCUCR &= 0xF3;
			MCUCR |= (mode & 0x0C);
			GICR |= INT1_EN;
			break;
		case INT2:
			MCUCSR &= 0xBF;
			MCUCSR |= (mode & 0x40);
			GICR |= INT2_EN;
			break;
	}
	GLOBAL_INTERRUPT_ENABLE();
}

void ExInterrupt_vidDisable(u8 interrupt_number){
	switch(interrupt_number)
	{
		case INT0:
			GICR &= INT0_DISABLE;
			break;
		case INT1:
			GICR &= INT1_DISABLE;
			break;
		case INT2:
			GICR &= INT2_DISABLE;
			break;
	}
}

void ExInterrupt_setCallBackFun(u8 interrupt_number, void (*ptr)(void) ){
	switch(interrupt_number)
		{
			case INT0:
				call_back_fun0 = ptr;
				break;
			case INT1:
				call_back_fun1 = ptr;
				break;
			case INT2:
				call_back_fun2 = ptr;
				break;
		}
}

ISR(VECT_INT0){
	call_back_fun0();
}

ISR(VECT_INT1){
	call_back_fun1();
}

ISR(VECT_INT2){
	call_back_fun2();
}

