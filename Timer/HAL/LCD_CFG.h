/*
 * LCD_CFG.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Hazem
 */

#ifndef HAL_LCD_CFG_H_
#define HAL_LCD_CFG_H_

#include "LCD.h"

#define LCD_DATAPORT	DPORT
#define LCD_RSPORT		APORT
#define LCD_RSPIN		PIN2
#define LCD_RWPORT		APORT
#define LCD_RWPIN		PIN0
#define LCD_ENPORT		APORT
#define LCD_ENPIN		PIN1

/*USE FONT_5X10 OR FONT_5X7*/
#define LCD_FONT		FONT_5X7
/*USE ONE_LINE OR TWO_LINES*/
#define LINE_NUM		TWO_LINES
/*USE _4BIT_DATA OR _8BIT_DATA*/
#define DATA_NUM		_8BIT_DATA
/*USE MOVE_RIGHT OR MOVE_LEFT*/
#define CURSOR_MOVE		MOVE_RIGHT


#if ( LCD_FONT == _5x10 && LINE_NUM == TWO_LINES )
		#pragma GCC error "You cannot Have Two Lines LCD with 5 * 10"
#endif


#endif /* HAL_LCD_CFG_H_ */
