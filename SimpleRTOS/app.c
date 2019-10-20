/*
 * app.c
 *
 *  Created on: Oct 18, 2019
 *      Author: Hazem
 *
 *      this app simulate a real time OS scheduler that  runs tasks
 *      periodically with in given time with tick time 1ms,
 *      the scheduler sets tasks priorities based on
 *      the assignment of the task to the scheduler
 *
 *      for ex: first task to assign takes highest priority
 */

#include "STD_Types.h"
#include "macros.h"
#include "OS.h"
#include "MCAL/DIO.h"

void task(){
	PORTD_REG ^= (1<<7);

}


int main(void){
	DIO_vidSetPinDirection(DPORT, PIN7, OUTPUT);
	OS_vidCreateTask(task, 800);
	OS_vidStart();
	while(1){

	}
}
