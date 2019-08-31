#ifndef DIO_H_
#define DIO_H_

#include "../STD_Types.h"

/*direction registers*/
#define DDRA_REG	*((u8*)0x3A)
#define DDRB_REG	*((u8*)0x37)
#define DDRC_REG	*((u8*)0x34)
#define DDRD_REG	*((u8*)0x31)
/*output registers*/
#define PORTA_REG	*((u8*)0x3B)
#define PORTB_REG	*((u8*)0x38)
#define PORTC_REG	*((u8*)0x35)
#define PORTD_REG	*((u8*)0x32)
/* input registers*/
#define PINA_REG	*((u8*)0x39)
#define PINB_REG	*((u8*)0x36)
#define PINC_REG	*((u8*)0x33)
#define PIND_REG	*((u8*)0x30)

#define APORT	0
#define BPORT	1
#define CPORT	2
#define DPORT	3
/*Direction */
#define INPUT	0
#define OUTPUT	1

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

/* PIN Value */
#define HIGH   1
#define LOW    0
/*Port Handling */
#define ALL_INPUT  0x00
#define ALL_OUTPUT 0xFF

#define ALL_LOW  0x00
#define ALL_HIGH 0xFF

void DIO_vidSetPortDir(u8 PortName, u8 PortDir);
void DIO_vidSetPortValue(u8 PortName, u8 PortVal);
u8 DIO_u8GetPortValue(u8 PortName);

void DIO_vidSetPinDirection (u8 PortName, u8 PinNumber, u8 PinDirection);
void DIO_vidSetPinValue(u8 PortName , u8 PinNumber, u8 PinValue);
u8 DIO_u8GetPinValue(u8 PortName, u8 PinNumber);

#endif
