/*
 * LCD.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Hazem
 */

#include "../STD_Types.h"
#include "../macros.h"
#include "LCD.h"
#include "LCD_CFG.h"

#define F_CPU	8000000UL
#include "util/delay.h"
#include "../MCAL/DIO.h"

static void LOC_vidSendInstruction(u8 Ins);


#define	FUNCTION_SET	(0b00100000|(LCD_FONT<<2)|(LINE_NUM<<3)| (DATA_NUM<<4))
#define DISPLAY_CLEAR	0b00000001
#define DISPLAY_CONTROL 0b00001100  //DISPLAY ON
#define ENTRY_MODE_SET  (0b00000100|(CURSOR_MOVE<<1))
#define DDRAM_ADDRESS	0b10000000
#define DISPLAY_SHIFT   0b00011000
#define CURSOR_SHIFT    0b00010000
#define GCRAM_ADDRESS   0x48

/*private function*/
static void LOC_vidSendInstruction(u8 Ins)
{
	/*set RW=0*/
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	/*set RS=0*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,LOW);
	/*set D0~D7*/
	DIO_vidSetPortValue(LCD_DATAPORT,Ins);
	/*Enable Falling edge*/
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	_delay_ms(1);
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);
}


/*public functions*/
extern void LCD_vidInit(void)
{
	DIO_vidSetPortDir(LCD_DATAPORT,ALL_OUTPUT);
	DIO_vidSetPinDirection(LCD_RWPORT,LCD_RWPIN,OUTPUT);
	DIO_vidSetPinDirection(LCD_ENPORT,LCD_ENPIN,OUTPUT);
	DIO_vidSetPinDirection(LCD_RSPORT,LCD_RSPIN,OUTPUT);

	_delay_ms(30);
	LOC_vidSendInstruction(FUNCTION_SET);
	_delay_ms(2);
	LOC_vidSendInstruction(DISPLAY_CONTROL);
	_delay_ms(2);
	LOC_vidSendInstruction(DISPLAY_CLEAR);
	_delay_ms(2);
	LOC_vidSendInstruction(ENTRY_MODE_SET);
	_delay_ms(2);
}

extern void LCD_vidWriteChar(u8 ch)
{
	/*set RW=0*/
	DIO_vidSetPinValue(LCD_RWPORT,LCD_RWPIN,LOW);
	/*set RS=1*/
	DIO_vidSetPinValue(LCD_RSPORT,LCD_RSPIN,HIGH);
	/*set D0~D7*/
	DIO_vidSetPortValue(LCD_DATAPORT,ch);
	/*Enable Falling edge*/
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,HIGH);
	_delay_ms(1);
	DIO_vidSetPinValue(LCD_ENPORT,LCD_ENPIN,LOW);

}

extern void LCD_vidClear(void)
{

	//LOC_vidSendInstruction(DISPLAY_CLEAR);
	u8 i;
	LCD_vidsetCursorAt(1,0);
	for(i=0;i<16;i++)
		LCD_vidWriteChar(' ');
	LCD_vidsetCursorAt(2,0);
	for(i=0;i<16;i++)
		LCD_vidWriteChar(' ');

	LCD_vidsetCursorAt(1,0);
}

extern void LCD_vidWriteString(char * ptr)
{
	while(*ptr != '\0')
	{
		LCD_vidWriteChar(*ptr);
		ptr++;
	}
}

extern void LCD_vidsetCursorAt(u8 row , u8 col)
{
	u8 Address=0;

	switch(row)
	{
		case 1:
				/* for 1st col base address is 0x00 */
					Address = col | 0x00;
					break;
		case 2:
				/* for 2nd col base address is 0x40 */
					Address = col | 0x40;
					break;

	}
	LOC_vidSendInstruction(DDRAM_ADDRESS|Address);
}

extern void LCD_vidShiftDisplay(u8 direction,u8 shift_num)
{
	u8 i;

	for(i=0 ; i<shift_num ; i++){

		LOC_vidSendInstruction(DISPLAY_SHIFT|(direction<<2));
	}
	_delay_ms(2);

}

extern void LCD_vidShiftCursor(u8 direction,u8 shift_num)
{
	u8 i;

	for(i=0 ; i<shift_num ; i++){

		LOC_vidSendInstruction(CURSOR_SHIFT|((direction)<<2));
	}
	_delay_ms(2);

}

extern void LCD_vidDisplayInt(s32 n)
{
	char str[20];
    s32 i, i_rev, j, temp, sign;

    /*int to ascii*/
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    /*reverse string*/
    for (i_rev = 0, j = i-1; i_rev < j; i_rev++, j--) {
        temp = str[i_rev];
        str[i_rev] = str[j];
        str[j] = temp;
    }
	LCD_vidWriteString(str);
}

extern void LCD_vidCreatCustomPattern(u8 *pattern, u8 position){
	u8 i;

	LOC_vidSendInstruction(GCRAM_ADDRESS + (7*position));
	for(i=0; i<8; i++)
		LCD_vidWriteChar(pattern[i]);

	LOC_vidSendInstruction(DDRAM_ADDRESS);
	_delay_ms(2);

}
