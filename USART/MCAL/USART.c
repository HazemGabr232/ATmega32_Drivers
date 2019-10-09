/*
 * USART.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Hazem
 */

#include "../STD_Types.h"
#include "../macros.h"
#include "USART.h"
#include "USART_CFG.h"

/*UCSRA */
#define RXC 	7	 	//USART Receive Complet flag
#define TXC		6	    //USART Transmit Complete flag
#define UDRE	5		//USART Data Register Empty	flag
#define FE		4	 	//Frame Error flag
#define DOR		3		//Data OverRun
#define PE		2  		//Parity Error
#define U2X		1 		//Double USART Transmission Rate
#define MPCM	0		//Multi-Processor Communication Mode
/*UCSRB */
#define RXCIE	7 		//RX Complete Interrupt Enable
#define TXCIE	6	   	//TX Complete Interrupt Enable
#define UDRIE	5     	//USART Data Register Empty Interrupt Enable
#define RXEN	4    	//Receiver Enable
#define TXEN	3   	//Transmitter Enable
#define UCSZ2	2  		//Character Size 2
#define RXB8	1 		//Receive Data Bit 8
#define	TXB8	0		//Transmit Data Bit 8
/*UCSRC */
#define URSEL	7	    //Register select
#define UMSEL	6	   	//USART Mode select
#define UBM1	5	  	//Parity Mode
#define UBM0	4    	//stop Bit Select
#define USBS	3   	//stop bit select
#define UCSZ1	2  		//Character Size 1
#define UCSZ0	1 		//Character Size 0
#define UCPOL	0		//Clock Polarity

#define VECT_RXC				13
#define VECT_TXC				15
#define VECT_DATA_REG_EMPTY		14

u8 data_rx_flag = 0;
u8 data_tx_flag = 0;
u8 data ;

void USART_vidInit(void)
{
	//u8 UCSRC_Value;
	/*Enable Receive */
	SET_BIT(UCSRB, RXEN);
	/*Enable Transmit*/
	SET_BIT(UCSRB, TXEN);
	/*Access UCSRC Reg	&& Character Size */
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	/*set Baud Rate 9600 */
	 UBRRL = 51;
	 UBRRH = 0;
	 /*ENABLE TX & RX INTERRUPTS*/
//	 SET_BIT(UCSRB, TXCIE);
	 SET_BIT(UCSRB, RXCIE);
	 GLOBAL_INTERRUPT_ENABLE();
}

u8 USART_u16Receive(u8* ret_vlaue_ptr){

	if (data_rx_flag){
		*ret_vlaue_ptr = data ;
		data_rx_flag = 0;
		return OK ;
	}
	else{
		return NOK;
	}

	/*
	//implementation using polling
	//wait till Receive Complete
	while(!(GET_BIT(UCSRA,RXC)));
	//Clear flag
	SET_BIT(UCSRA,RXC);
	return UDR;*/
}
void  USART_vidSend(u8 data)
{
	/*wait till data Register Empty */
	while(!(GET_BIT(UCSRA,UDRE)));
	UDR=data;
}

ISR(VECT_RXC){
	data_rx_flag = 1;
	data = UDR;
}

/*
 ISR(VECT_DATA_REG_EMPTY){

} */
