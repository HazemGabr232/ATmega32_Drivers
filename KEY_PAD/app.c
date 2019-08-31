/*
 * Calculator.c
 *
 *  Created on: Aug 29, 2019
 *      Author: Hazem
 */


#define F_CPU 8000000UL
#include "MCAL/DIO.h"
#include "STD_Types.h"
#include "macros.h"
#include "HAL/KEY_PAD.h"
#include "HAL/LCD.h"
#include <util/delay.h>

void add(u8 num1, u8 num2);
void sub(u8 num1, u8 num2);
void div(u8 num1, u8 num2);

int main() {
	u8 num1, num2, check, flag=0, op ;
	u8 key_map[]={-1, 1, 2, 3, -1, 4, 5, 6, -1, 7, 8, 9, -1, -1, 0};

	LCD_vidInit();
	KEYPAD_vidInit();


	while(1){
		 check =KEYPAD_u8GetPressedKey();
		 if (check != 0){
			 if (flag == 0){
				 num1 = key_map[check];
				 LCD_vidDisplayInt(num1);
				 flag++;
			 }
			 else if(flag == 1){
				 op = check;
				 if (op == Key_A)
					 LCD_vidWriteChar('+');
				 else if(op == Key_B)
					 LCD_vidWriteChar('-');
				 else if(op == Key_C)
					 LCD_vidWriteChar('/');
				 flag++;
			 }
			 else if(flag == 2){
				 num2 = key_map[check];
				 LCD_vidDisplayInt(num2);
				 flag ++;
			 }
		 }
		 if (flag == 3){
			 switch (op){
							 case Key_A:
								 add(num1,num2);
								 break;
							 case Key_B:
								 sub(num1,num2);
								 break;
							 case Key_C:
								 div(num1,num2);
								 break;
			 }
			 flag = 0;
			 _delay_ms(1000);
			 LCD_vidClear();
		 }
	 }

	 return 0;
}

void add(u8 num1, u8 num2){
	LCD_vidWriteChar('=');
	LCD_vidDisplayInt(num1+num2);
}

void sub(u8 num1, u8 num2){
	LCD_vidWriteChar('=');
	LCD_vidDisplayInt(num1-num2);
}

void div(u8 num1, u8 num2){
	LCD_vidWriteChar('=');
	LCD_vidDisplayInt(num1/num2);
}
