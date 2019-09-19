/*
 * WDT.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Hazem
 */

#ifndef MCAL_WDT_H_
#define MCAL_WDT_H_

#include "../STD_Types.h"
#define SCALER16_3ms		0
#define SCALER32_5ms		1
#define SCALER65ms			2
#define SCALER0_13s			3
#define SCALER0_26s			4
#define SCALER0_52s			5
#define SCALER1s			6
#define SCALER2_1s			7

#define WDT_RESET()	__(asm)__ __(volatile)__ ("wdr")

void WDT_vidInit(u8 prescaler);
void WDT_vidDisable();


#endif /* MCAL_WDT_H_ */
