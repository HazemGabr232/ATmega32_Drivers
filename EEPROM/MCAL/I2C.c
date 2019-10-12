/*
 * I2C.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */

#include "../STD_Types.h"
#include "../macros.h"
#include "I2C.h"
#include "I2C_CFG.h"
/*TWCR REGISTER BITS*/
#define TWIE	0
#define TWEN	2
#define TWWC	3
#define TWSTO	4
#define TWSTA	5
#define TWEA	6
#define TWINT	7

void I2C_vidInit(void)
{
  // TWI initialization
  // Bit Rate: 400.000 kHz
  TWBR = 10;//72;
  // Two Wire Bus Slave Address: 0x1
  // General Call Recognition: Off
  TWAR = 0x02;
  // Generate Acknowledge Pulse: On
  // TWI Interrupt: Off
  TWCR = 0x44;
//  TWSR = 0x00;
//  TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));
}

void I2C_vidStart(void)
{
  // Send Start Condition
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)));
  /*Clr start condition bit*/
//   clr_bit(TWCR , TWSTA) ;

}

void I2C_vidStop(void)
{
  // Send Stop Condition
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void I2C_vidWrite(u8 data)
{
  // Put data On TWI Register
  TWDR = data;
  // Send Data
  TWCR = (1 << TWINT) | (1 << TWEN);

  /*Clr start condition bit*/
//   clr_bit(TWCR , TWSTA) ;
   /*Clr INT flag*/
  // set_bit(TWCR,TWINT);


  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)));
}

u8 I2C_u8ReadData(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    //enable Ack

  /*Clr INT flag*/
//  set_bit(TWCR,TWINT);


  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)));


  // Read Data
  return TWDR;
}

u8 I2C_u8GetStatus(void)
{
  u8 status;
  status = TWSR & 0xF8;
  return status;
}

