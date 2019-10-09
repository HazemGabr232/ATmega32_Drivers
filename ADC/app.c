/*
 * app.c
 *
 *  Created on: Sep 30, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/ADC.h"
#include "MCAL/DIO.h"
#include "MCAL/Timer.h"
#include "HAL/LCD.h"

int main(void){
/*control servo using potentiometer*/
	u32 pos = 800;
	u32 x;
	DIO_vidSetPinDirection(DPORT, PIN5, OUTPUT);
	DIO_vidSetPinDirection(DPORT, PIN7, OUTPUT);
	DIO_vidSetPinDirection(APORT, A7, INPUT);
	Timer_vidEnableTimer(TIMER1, SCALER8, FAST_PWM);
	Timer_vidSetPWM(20000, pos);
	ADC_vidInit(DIVIDER16);
	ADC_vidStart(A7);
	LCD_vidInit();

	//LCD_vidsetCursorAt(2,0);
	//LCD_vidWriteChar('H');
	while(1){
	x = ADC_u32Read();
	Timer_vidSetPWM(20000, pos+x);
	/*print ADC reading on LCD to check*/	
	LCD_vidsetCursorAt(1,0);
	LCD_vidDisplayInt(x);
	
	}
}
