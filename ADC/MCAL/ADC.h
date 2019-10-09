/*
 * ADC.h
 *
 *  Created on: Sep 30, 2019
 *      Author: Hazem
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include "../STD_Types.h"
#include "../macros.h"

#define A0		0
#define A1		1
#define A2		2
#define A3		3
#define A4		4
#define A5		5
#define A6		6
#define A7		7

#define DIVIDER2		1
#define DIVIDER4		2
#define DIVIDER8		3
#define DIVIDER16	4
#define DIVIDER32	5
#define DIVIDER64	6
#define DIVIDER128	7

void ADC_vidInit(u8 prescaler);
void ADC_vidStart(u8 channel);
u32 ADC_u32Read(void);

#endif /* MCAL_ADC_H_ */
