/*
 * WDT.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Hazem
 */
#include "../STD_Types.h"
#include "../macros.h"
#include "WDT.h"
#include "WDT_CFG.h"

void WDT_vidInit(u8 prescaler){
	switch(prescaler){
					case SCALER16_3ms:
						CLEAR_BIT(WDTCR, 0);
						CLEAR_BIT(WDTCR, 1);
						CLEAR_BIT(WDTCR, 2);
						break;
					case SCALER32_5ms:
						SET_BIT(WDTCR, 0);
						CLEAR_BIT(WDTCR, 1);
						CLEAR_BIT(WDTCR, 2);
						break;
					case SCALER65ms:
						CLEAR_BIT(WDTCR, 0);
						SET_BIT(WDTCR, 1);
						CLEAR_BIT(WDTCR, 2);
						break;
					case SCALER0_13s:
						SET_BIT(WDTCR, 0);
						SET_BIT(WDTCR, 1);
						CLEAR_BIT(WDTCR, 2);
						break;
					case SCALER0_26s:
						CLEAR_BIT(WDTCR, 0);
						CLEAR_BIT(WDTCR, 1);
						SET_BIT(WDTCR, 2);
						break;
					case SCALER0_52s:
						SET_BIT(WDTCR, 0);
						CLEAR_BIT(WDTCR, 1);
						SET_BIT(WDTCR, 2);
						break;
					case SCALER1s:
						CLEAR_BIT(WDTCR, 0);
						SET_BIT(WDTCR, 1);
						SET_BIT(WDTCR, 2);
						break;
					case SCALER2_1s:
						SET_BIT(WDTCR, 0);
						SET_BIT(WDTCR, 1);
						SET_BIT(WDTCR, 2);
						break;
					}
	SET_BIT(WDTCR, 3);
}

void WDT_vidDisable(){
	WDTCR |= 0b00011000 ;
	CLEAR_BIT(WDTCR, 3);
}

