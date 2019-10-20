/*
 * OS.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Hazem
 */

#include "OS.h"
#include "STD_Types.h"
#include "MCAL/Timer.h"

#define NO_OF_TASKS	5

u8 priority = 0;
Task tasks_arr[NO_OF_TASKS] = {0};
static u8 tick_flag = 0;
static u32 tick = 0;

void scheduler();
void tick_callback();

void OS_vidCreateTask(void (*pf)(void), u32 period){

	tasks_arr[priority].taskPtr = pf ;
	tasks_arr[priority].periodicty = period;
	priority++ ;
}

void OS_vidStart(){
	Timer_vidEnableTimer(TIMER1,SCALER8, COMPAREA);
	Timer_setCallBackFun(TIMER1, COMPAREA, tick_callback);
	while(1){
		if (tick_flag == 1){
			scheduler();
			tick_flag = 0;
		}
	}
}

void scheduler(){
	u32 i;
	for (i=0; i<NO_OF_TASKS; i++){
		if (tasks_arr[i].taskPtr != '\0' && tick % tasks_arr[i].periodicty == 0){
			tasks_arr[i].taskPtr();
		}
	}
}

void tick_callback(){
	tick++;
	tick_flag = 1;
}
