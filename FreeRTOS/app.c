/*
 * app.c
 *
 *  Created on: Oct 19, 2019
 *      Author: Hazem
 *
 *      this application uses semaphore to synchronize between two tasks
 *      button task and led3 task  .
 *      There is led1 task to test periodic tasks, the LED should toggle
 *      every 800ms
 */
#include "STD_Types.h"
#include "macros.h"
#include "FreeRTOS/FreeRTOS.h"
#include "FreeRTOS/FreeRTOSConfig.h"
#include "FreeRTOS/task.h"
#include "FreeRTOS/semphr.h"
#include "MCAL/DIO.h"

void led1_task(void);
void led2_task(void);
void led3_task(void);
void button_task(void);

xSemaphoreHandle led_semaphor;

int main(){
	vSemaphoreCreateBinary(led_semaphor);
	xTaskCreate(led1_task, NULL, configMINIMAL_STACK_SIZE, NULL, 3, NULL);
	//xTaskCreate(led2_task, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(led3_task, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(button_task, NULL, configMINIMAL_STACK_SIZE, NULL, 0, NULL);
	vTaskStartScheduler();
	while(1){

	}
	return 0;
}

void led1_task(void){
	DIO_vidSetPinDirection(DPORT, PIN6, OUTPUT);
	u32 previos_wake_time ;
	previos_wake_time= xTaskGetTickCount();
	while(1){

		PORTD_REG ^= (1<<6);
		vTaskDelayUntil(&previos_wake_time ,800);

	}
}

void led2_task(void){
	DIO_vidSetPinDirection(DPORT, PIN5, OUTPUT);
	u32 previos_wake_time ;
	previos_wake_time= xTaskGetTickCount();
	while(1){
		PORTD_REG ^= (1<<5);
		vTaskDelayUntil(&previos_wake_time ,800);

	}
}

void led3_task(void){
	DIO_vidSetPinDirection(DPORT, PIN4, OUTPUT);
	xSemaphoreTake(led_semaphor, portMAX_DELAY);
	u16  state;

	while(1){
		state =xSemaphoreTake(led_semaphor, portMAX_DELAY);
		if (state ==1)
		PORTD_REG ^= (1<<4);

	}
}

void button_task(void){
	DIO_vidSetPinDirection(DPORT, PIN1, INPUT);
	DIO_vidSetPinValue(DPORT, PIN1, HIGH);
	while(1){
		if (DIO_u8GetPinValue(DPORT, PIN1)== LOW){
			xSemaphoreGive(led_semaphor);
		}
		vTaskDelay(200);
	}
}
