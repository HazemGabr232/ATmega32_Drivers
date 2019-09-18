/*
 * app.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Hazem
 */
#include "STD_Types.h"
#include "macros.h"
#include "MCAL/DIO.h"
#include "MCAL/ExInterrupt.h"
#include "MCAL/Timer.h"
#include "HAL/LCD.h"


u8 flag = 0;
float32 freq = 0;
s32 duty_cycle = 0;
float32 time_on = 0;
float32 time_off = 0;
void int_call_back(void){
	static u8 state = 0;
	switch(state){
	case 0:
		flag = 0;
		Timer_vidSetTimerStartValue(TIMER0, 0);
		ExInterrupt_vidEnable(INT0, INT0_FALLING);
		state = 1;
		break;

	case 1:
		time_on = Timer_u8GetTimerCounts(TIMER0);
		Timer_vidSetTimerStartValue(TIMER0, 0);
		ExInterrupt_vidEnable(INT0, INT0_RISING);
		state = 2;
		break;

	case 2:
		time_on = Timer_u8GetTimerCounts(TIMER0);//calculate t-off, t-on and set flags
		flag = 1;
		state = 0;
		break;

	}
}

void timer_callback(void){
//dummy fun to avoid the wild pointer of the isr call back fun
}
int main(){
	LCD_vidInit();
	Timer_vidEnableTimer(TIMER1, SCALER8, FAST_PWM);
	DIO_vidSetPinDirection(DPORT, PIN5, OUTPUT);
	Timer_vidSetPWM(20000, 2000);//test signal 50hz ,duty_cycle 0.1
	Timer_vidEnableTimer(TIMER0, SCALER1024, OVERFLOW);
	DIO_vidSetPinDirection(DPORT, PIN2, INPUT);
	ExInterrupt_vidEnable(INT0, INT0_RISING);
	ExInterrupt_setCallBackFun(INT0, int_call_back);
	Timer_setCallBackFun(TIMER0, OVERFLOW, timer_callback);

	while(1){
		if (flag == 1){
			duty_cycle = time_on/(time_on + time_off);
			freq = 1/((time_off *0.000128 + time_on *0.000128));
			LCD_vidsetCursorAt(1, 0);
			LCD_vidDisplayInt((s32)freq);
			LCD_vidsetCursorAt(2, 0);
			LCD_vidWriteChar('0');
			LCD_vidWriteChar('.');
			LCD_vidDisplayInt((s32)duty_cycle*1000);
			flag = 0;
		}
	}
}

