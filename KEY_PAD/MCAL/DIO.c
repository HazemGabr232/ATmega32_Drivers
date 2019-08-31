#include "../STD_Types.h"
#include "../macros.h"
#include "DIO.h"

/*
 *  0 -> PortA
 * 	1 -> PortB
 * 	2 -> PortC
 * 	3 -> PortD
 *
 * 	0 -> Input
 * 	1 -> Output
 *
 * 	0 -> LOW
 * 	1 -> HIGH
 * */

void DIO_vidSetPortDir(u8 PortName, u8 PortDir)
{
	switch(PortName)
	{
		case APORT :
			DDRA_REG = PortDir ;
			break ;
		case BPORT:
			DDRB_REG = PortDir ;
			break ;
		case CPORT:
			DDRC_REG = PortDir ;
			break ;
		case DPORT:
			DDRD_REG = PortDir ;
			break ;
		default :// Wrong
			break;
	}
}
void DIO_vidSetPortValue(u8 PortName, u8 PortVal)
{
	switch(PortName)
		{
			case APORT :
				PORTA_REG = PortVal ;
				break ;
			case BPORT:
				PORTB_REG = PortVal ;
				break ;
			case CPORT:
				PORTC_REG = PortVal ;
				break ;
			case DPORT:
				PORTD_REG = PortVal ;
				break ;
			default ://Wrong
				break;
		}
}
u8 DIO_u8GetPortValue(u8 PortName)
{
	u8 PortVal ;
	switch(PortName)
			{
				case APORT :
					PortVal=PINA_REG;
					break ;
				case BPORT:
					PortVal=PINB_REG;
					break ;
				case CPORT:
					PortVal=PINC_REG;
					break ;
				case DPORT:
					PortVal=PIND_REG;
					break ;
				default ://Wrong
					PortVal=-1;
					break;
			}
	return PortVal;
}
void DIO_vidSetPinDirection (u8 PortName, u8 PinNumber, u8 PinDirection)
{
	if( PinNumber>=PIN0 && PinNumber<=PIN7)
			{
				switch(PortName)
				{
					case APORT :
						if(PinDirection==OUTPUT)
							SET_BIT(DDRA_REG,PinNumber);
						else if(PinDirection==INPUT)
							CLEAR_BIT(DDRA_REG,PinNumber);
						else{
							//do nothing
						}
						break;
					case BPORT:
						if(PinDirection==OUTPUT)
							SET_BIT(DDRB_REG,PinNumber);
						else if(PinDirection==INPUT)
							CLEAR_BIT(DDRB_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					case CPORT:
						if(PinDirection==OUTPUT)
							SET_BIT(DDRC_REG,PinNumber);
						else if(PinDirection==INPUT)
							CLEAR_BIT(DDRC_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					case DPORT:
						if(PinDirection==OUTPUT)
							SET_BIT(DDRD_REG,PinNumber);
						else if(PinDirection==INPUT)
							CLEAR_BIT(DDRD_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					default ://Wrong
						break;
					}

			}
			else {
				//do nothing
			}
}
u8 DIO_u8GetPinValue(u8 PortName, u8 PinNumber)
{
	u8 bitValue;
	switch(PortName)
			{
				case APORT:
					bitValue=GET_BIT(PINA_REG,PinNumber);
					break;
				case BPORT:
					bitValue=GET_BIT(PINB_REG,PinNumber);
					break ;
				case CPORT:
					bitValue=GET_BIT(PINC_REG,PinNumber);
					break ;
				case DPORT:
					bitValue=GET_BIT(PIND_REG,PinNumber);
					break ;
				default ://Wrong
					return -1;
			}
	return bitValue;
}
void DIO_vidSetPinValue(u8 PortName , u8 PinNumber, u8 PinValue)
{
	if( PinNumber>=PIN0 && PinNumber<=PIN7)
		{
			switch(PortName)
			{
					case APORT :
						if(PinValue==HIGH)
							SET_BIT(PORTA_REG,PinNumber);
						else if(PinValue==LOW)
							CLEAR_BIT(PORTA_REG,PinNumber);
						else{
							//do nothing
						}
						break;
					case BPORT:
						if(PinValue==HIGH)
							SET_BIT(PORTB_REG,PinNumber);
						else if(PinValue==LOW)
							CLEAR_BIT(PORTB_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					case CPORT:
						if(PinValue==HIGH)
							SET_BIT(PORTC_REG,PinNumber);
						else if(PinValue==LOW)
							CLEAR_BIT(PORTC_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					case DPORT:
						if(PinValue==HIGH)
							SET_BIT(PORTD_REG,PinNumber);
						else if(PinValue==LOW)
							CLEAR_BIT(PORTD_REG,PinNumber);
						else{
							//do nothing
						}
						break ;
					default ://Wrong
						break;
				}

		}
		else {
			//do nothing
		}
}
