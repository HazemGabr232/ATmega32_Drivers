/*
 * Timer.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Hazem
 */

#include "../STD_Types.h"
#include "../macros.h"
#include "Timer.h"
#include "Timer_CFG.h"
#include "DIO.h"

void (*call_back_fun0)(void);
void (*call_back_fun1)(void);
void (*call_back_fun2)(void);
void (*call_back_fun3)(void);
void (*call_back_fun4)(void);
void (*call_back_fun5)(void);
void (*call_back_fun6)(void);
void (*call_back_fun7)(void);

void Timer_vidEnableTimer(u8 timer_no, u8 prescaler, u8 mode){
	switch(timer_no){
	/*TIMER 0 CONFIG*/
	case TIMER0:
		switch(mode){
		case OVERFLOW:
			SET_BIT(TIMSK, 0);
			break;
		case COMPARE:
			SET_BIT(TIMSK, 1);
			break;
		}

		switch(prescaler){
		case SCALER64:
			SET_BIT(TCCR0, 0);
			SET_BIT(TCCR0, 1);
			CLEAR_BIT(TCCR0, 2);
			break;
		case SCALER256:
			CLEAR_BIT(TCCR0, 0);
			CLEAR_BIT(TCCR0, 1);
			SET_BIT(TCCR0, 2);
			break;
		case SCALER1024:
			SET_BIT(TCCR0, 0);
			CLEAR_BIT(TCCR0, 1);
			SET_BIT(TCCR0, 2);
			break;
		}


		break;
		/*TIMER 1 CONFIG*/
	case TIMER1:
		switch(mode){
		case OVERFLOW:
			SET_BIT(TIMSK, 2);
			break;
		case COMPAREA:
			SET_BIT(TIMSK, 4);
			OCR1A = 1000; //TODO take the value from the user
			CLEAR_BIT(TCCR1A, 0);  //WGM10
			CLEAR_BIT(TCCR1A, 1);	//WGM11
			SET_BIT(TCCR1B, 3);		//WGM12
			CLEAR_BIT(TCCR1B, 4);	//WGM13
			break;
		case COMPAREB:
			SET_BIT(TIMSK, 3);
			break;
		case CAPTURE:
			SET_BIT(TIMSK, 5);
			break;
		case FAST_PWM: 		//MODE 14 FAST PWM
			//ICR1 = 20000			//TOP VALUE
			//OCR1A =1000			//ON
			CLEAR_BIT(TCCR1A, 6);
			SET_BIT(TCCR1A, 7);
			CLEAR_BIT(TCCR1A, 0);
			SET_BIT(TCCR1A, 1);
			SET_BIT(TCCR1B, 3);
			SET_BIT(TCCR1B, 4);
		}

		switch(prescaler){
				case SCALER1:
					SET_BIT(TCCR1B, 0);
					CLEAR_BIT(TCCR1B, 1);
					CLEAR_BIT(TCCR1B, 2);
					break;
				case SCALER8:
					CLEAR_BIT(TCCR1B, 0);
					SET_BIT(TCCR1B, 1);
					CLEAR_BIT(TCCR1B, 2);
					break;
				case SCALER64:
					SET_BIT(TCCR1B, 0);
					SET_BIT(TCCR1B, 1);
					CLEAR_BIT(TCCR1B, 2);
					break;
				case SCALER256:
					CLEAR_BIT(TCCR1B, 0);
					CLEAR_BIT(TCCR1B, 1);
					SET_BIT(TCCR1B, 2);
					break;
				case SCALER1024:
					SET_BIT(TCCR1B, 0);
					CLEAR_BIT(TCCR1B, 1);
					SET_BIT(TCCR1B, 2);
					break;
				}


		break;

	case TIMER2:
		break;

	}
GLOBAL_INTERRUPT_ENABLE();
}

void Timer_vidDisableTimer(u8 timer_no){
	switch(timer_no){
	case TIMER0:
		CLEAR_BIT(TIMSK, 0);
		CLEAR_BIT(TIMSK, 1);
		break;
	case TIMER1:
		CLEAR_BIT(TIMSK, 2);
		CLEAR_BIT(TIMSK, 3);
		CLEAR_BIT(TIMSK, 4);
		CLEAR_BIT(TIMSK, 5);
		break;
	case TIMER2:
		CLEAR_BIT(TIMSK, 6);
		CLEAR_BIT(TIMSK, 7);
		break;
	}


}
void Timer_setCallBackFun(u8 timer_no,u8 mode , void (*ptr)(void) ){
	switch(timer_no)
		{
			case TIMER0:
				switch(mode){
				case COMPARE:
					call_back_fun0 = ptr;
					break;
				case OVERFLOW:
					call_back_fun1 = ptr;
					break;
				}
				break;

			case TIMER1:
				switch(mode){
				case CAPTURE:
					call_back_fun2 = ptr;
					break;
				case COMPAREA:
					call_back_fun3 = ptr;
					break;
				case COMPAREB:
					call_back_fun4 = ptr;
					break;
				case OVERFLOW:
					call_back_fun5 = ptr;
					break;
				}
				break;

			case TIMER2:
				switch(mode){
				case COMPARE:
					call_back_fun6 = ptr;
					break;
				case OVERFLOW:
					call_back_fun7 = ptr;
					break;
				}
				break;
		}
}

void Timer_vidSetPWM(u16 freq, u16 on_time){
//TODO map values here using equations
	ICR1 = freq ;
	OCR1A = on_time ;
}

u16 Timer_u8GetTimerCounts(u8 timer_no){
	switch(timer_no){
	case TIMER0:
		return TCNT0;
		break;
	case TIMER1:
		return TCNT1;
		break;
	case TIMER2:
		return TCNT2;
		break;
	}
	return 0;

}

void Timer_vidSetTimerStartValue(u8 timer_no, u16 start_value){
	switch(timer_no){
	case TIMER0:
		TCNT0 = (u8)start_value;
		break;
	case TIMER1:
		TCNT1 = start_value;
		break;
	case TIMER2:
		TCNT2 = (u8)start_value;
		break;
	}

}

ISR(VECT_TIMER0_COMP){
	call_back_fun0();
}

ISR(VECT_TIMER0_OVF){
	call_back_fun1();
}

ISR(VECT_TIMER1_CAPT){
	call_back_fun2();
}

ISR(VECT_TIMER1_COMPA){
	call_back_fun3();
}

ISR(VECT_TIMER1_COMPB){
	call_back_fun4();
}

ISR(VECT_TIMER1_OVF){
	call_back_fun5();
}

ISR(VECT_TIMER2_COMP){
	call_back_fun6();
}

ISR(VECT_TIMER2_OVF){
	call_back_fun7();
}
