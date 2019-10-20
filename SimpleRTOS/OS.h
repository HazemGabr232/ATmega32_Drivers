/*
 * OS.h
 *
 *  Created on: Oct 18, 2019
 *      Author: Hazem
 */

#ifndef OS_H_
#define OS_H_
#include "STD_Types.h"

typedef struct{
	void (*taskPtr)(void);
	u32 periodicty;
} Task;

void OS_vidCreateTask(void (*pf)(void), u32 period);
void OS_vidStart();

#endif /* OS_H_ */
