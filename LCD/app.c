/*
 * app.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Hazem
 */
#define F_CPU 8000000UL
#include "MCAL/DIO.h"
#include "STD_Types.h"
#include "macros.h"
#include "HAL/LCD.h"
#include <util/delay.h>

#define  SCREEN_WIDTH	16
 int main() {
	 char* name ="HAZEM";
	// s32 num =300;
	 u8 flag = 0;
	 s8 col = 0;
	 u8 row = 1;
/*	 u8 pattern1[]={0b00010101,
			 	 0b00010101,
			 	 0b00010101,
			 	 0b00010101,
			 	 0b00010101,
			 	 0b00010101,
			 	 0b00010101,
				 0b00010101};

	 u8 pattern2[]={0b00000001,
			 	 0b00000001,
			 	 0b00000001,
			 	 0b00000001,
			 	 0b00000001,
			 	 0b00000001,
			 	 0b00000001,
				 0b00000001};

*/
	 LCD_vidInit();

	 //LCD_vidShiftCursor(SHIFT_RIGHT,2);
	 //LCD_vidWriteChar('a');
	 //LCD_vidShiftCursor(SHIFT_LEFT,2);
	 //LCD_vidWriteChar('h');
	 //LCD_vidShiftDisplay(SHIFT_RIGHT,6);
	 //LCD_vidClear();
	 //LCD_vidsetCursorAt(2,0);
	 LCD_vidWriteString(name);
	 //LCD_vidDisplayInt(num);
	 //LCD_vidCreatCustomPattern(pattern1, 0);
	 //LCD_vidCreatCustomPattern(pattern2, 1);
	 //LCD_vidWriteChar(1);

	 //LCD_vidWriteChar(2);

	 while(1){
		 _delay_ms(800);
		 LCD_vidClear();

		 if (row==1)
			 row=2;
		 else if(row==2)
			 row=1;

		 if (col >= SCREEN_WIDTH)
			 flag = 1;
		 if(col <= 0)
			 flag =0;

		 if(flag == 0)
			 LCD_vidsetCursorAt(row, col+=5);
		 else if(flag ==1)
			 LCD_vidsetCursorAt(row, col-=5);

		 LCD_vidWriteString(name);

	 }


	return 0;
}
