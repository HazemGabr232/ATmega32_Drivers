/*
 * ADC.c
 *
 *  Created on: Sep 30, 2019
 *      Author: Hazem
 */


#include "../STD_Types.h"
#include "../macros.h"
#include "ADC.h"
#include "ADC_CFG.h"

u16 x = 0;

void ADC_vidInit(u8 prescaler){
	/*set v-ref source */
	SET_BIT(ADMUX, 6);
	CLEAR_BIT(ADMUX, 7);
	/*SET PRESCALER*/
	ADCSRA &= 0xF8;
	ADCSRA |= prescaler;
	/*ADC Enable*/
	SET_BIT(ADCSRA, 7);

}
void ADC_vidStart(u8 channel){
	switch(channel){
	case A0:
		CLEAR_BIT(ADMUX, 0);
		CLEAR_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A1:
		SET_BIT(ADMUX, 0);
		CLEAR_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A2:
		CLEAR_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A3:
		SET_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		CLEAR_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A4:
		CLEAR_BIT(ADMUX, 0);
		CLEAR_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A5:
		SET_BIT(ADMUX, 0);
		CLEAR_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A6:
		CLEAR_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	case A7:
		SET_BIT(ADMUX, 0);
		SET_BIT(ADMUX, 1);
		SET_BIT(ADMUX, 2);
		CLEAR_BIT(ADMUX, 3);
		CLEAR_BIT(ADMUX, 4);
		break;
	}
	CLEAR_BIT(ADMUX, 5);
	/*START CONVERSION*/
	SET_BIT(ADCSRA, 6);
	/*ENABLE ADC INTERRUPT*/
	SET_BIT(ADCSRA, 3);
	GLOBAL_INTERRUPT_ENABLE();

}
u32 ADC_u32Read(void){
	/*returns reading with m-volt */
	return (u32)((x*5000)/1024) ;
}
ISR(VECT_ADC){
	x = 0x03FF & ADC ;
	ADC &= 0xFC00 ;

}
