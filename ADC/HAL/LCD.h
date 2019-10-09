/*
 * LCD.h
 *
 *  Created on: Aug 16, 2019
 *      Author: Hazem
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#define FONT_5X10		0
#define FONT_5X7		1

#define ONE_LINE		0
#define TWO_LINES		1

#define _4BIT_DATA		0
#define _8BIT_DATA		1

#define MOVE_RIGHT		1
#define MOVE_LEFT		0

#define SHIFT_LEFT		0
#define SHIFT_RIGHT		1

/*pass to LCD_vidCreatCustomPattern the pattern in array
 * for example: 	 u8 pattern1[]={0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
			 	 	 	 	 	 	 0b00010101,
				 	 	 	 	 	 0b00010101};
 *draw your pattern in the least significant 5 bits
 * and pass the position of that pattern starting from 0 to 7
 *
 * to display your custom pattern use LCD_vidWriteChar(//ptrn number)
 * with your pattern number starting from 1 to 8
 *
 * */

extern void LCD_vidInit(void);
extern void LCD_vidWriteChar(u8 ch);
extern void LCD_vidClear(void);
extern void LCD_vidWriteString(char * ptr);
extern void LCD_vidsetCursorAt(u8 row, u8 col);
extern void LCD_vidShiftDisplay(u8 direction,u8 shift_num);
extern void LCD_vidShiftCursor(u8 direction,u8 shift_num);
extern void LCD_vidDisplayInt(s32 number);
extern void LCD_vidCreatCustomPattern(u8 *pattern, u8 position);


#endif /* HAL_LCD_H_ */
