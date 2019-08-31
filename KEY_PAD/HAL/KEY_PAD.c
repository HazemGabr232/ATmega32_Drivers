/*
 * KEY_PAD.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Hazem
 */
#include "../STD_Types.h"
#include "KEY_PAD.h"
#include "KEY_PAD_CFG.h"
#include "../MCAL/DIO.h"

#define NO_OF_ROWS	((u8)4)
#define NO_OF_COLMS	((u8)4)

u8 RAW_ARR[]={RAW_PIN0, RAW_PIN1, RAW_PIN2, RAW_PIN3};
u8 COL_ARR[]={COL_PIN0, COL_PIN1, COL_PIN2, COL_PIN3};

extern void KEYPAD_vidInit(void){
	u8 pin_num ;

	/*set col output*/
	for(pin_num=0; pin_num<4; pin_num++){

		/*Set columns as output*/
		DIO_vidSetPinDirection(COL_PORT,COL_ARR[pin_num],OUTPUT) ;

		/*Set Coloms HIGH*/
		DIO_vidSetPinValue(COL_PORT,COL_ARR[pin_num],HIGH);

		/*Set Rows as input*/
		DIO_vidSetPinDirection(RAW_PORT,RAW_ARR[pin_num],INPUT) ;

		/*Activate pull-up resistors */
		DIO_vidSetPinValue(RAW_PORT,RAW_ARR[pin_num],HIGH) ;
	}
}

KeyPadKey KEYPAD_u8GetPressedKey(void)
{
	u8 ColNo , RowNo , RetVal = 0 ;

	for (ColNo = 0 ; ColNo < NO_OF_COLMS ; ColNo++)
	{
		/*Activate column*/
		DIO_vidSetPinValue(COL_PORT , COL_ARR[ColNo] , LOW) ;

		for(RowNo=0 ; RowNo < NO_OF_ROWS ; RowNo++)
		{
			if (DIO_u8GetPinValue(RAW_PORT,RAW_ARR[RowNo] ) == LOW)
				{
					RetVal =  ( (RowNo * NO_OF_COLMS) + ColNo+1) ;
					/*wait to release the key*/
					while(DIO_u8GetPinValue(RAW_PORT,RAW_ARR[RowNo] ) == LOW);
				}
		}

		/*Deactivate column*/
		DIO_vidSetPinValue(COL_PORT , COL_ARR[ColNo] , HIGH) ;
	}

	return RetVal ;
}
