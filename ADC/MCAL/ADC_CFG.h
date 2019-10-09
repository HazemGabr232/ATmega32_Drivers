/*
 * ADC_CFG.h
 *
 *  Created on: Sep 30, 2019
 *      Author: Hazem
 */

#ifndef MCAL_ADC_CFG_H_
#define MCAL_ADC_CFG_H_

#include "../STD_Types.h"

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADC			*((volatile u16*)0x24)
#define SFIOR		*((volatile u8*)0x50)

#define VECT_ADC 	16

#endif /* MCAL_ADC_CFG_H_ */
