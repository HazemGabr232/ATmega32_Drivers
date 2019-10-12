/*
 * EEPROM.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */
#include "../STD_Types.h"
#include "EEPROM.h"
#include "../MCAL/I2C.h"

void EEPROM_Init(void)
{
	I2C_vidInit();
}

u8 EEPROM_WriteByte(u8 addr, u8 data)
{
  u8 state = 0;

  /* Start TWI*/
  I2C_vidStart();
  /* Get State*/
  state = I2C_u8GetStatus();
  /* Check if TWI Start*/
  if (state != TW_START)
  {
    return NOK;
  }
  /* Send Slave Address -> For EEPROM 24cXX Address of Chip is 0b1010
  * Set Action To Write -> 0
  * So, we need to send 0xA0
   */
  I2C_vidWrite(0xA0);
  // Get Status
  state = I2C_u8GetStatus();
  // Check if it is TW_MT_SLA_ACK
  if (state != TW_MT_SLA_ACK)
  {
    return NOK;
  }

  // Write the Rest of Location Address(8 Bits)
  I2C_vidWrite(addr);

  // Get State
  state = I2C_u8GetStatus();

  // check if it is TW_MT_DATA_ACK
  if (state != TW_MT_DATA_ACK)
  {
    return NOK;
  }

  // Send Data
  I2C_vidWrite(data);

  // Get Status
  state = I2C_u8GetStatus();

  // Check if it is TW_MT_DATA_ACK
  if (state != TW_MT_DATA_ACK)
  {
    return NOK;
  }

  // TWI Stop
  I2C_vidStop();
  // Return Done
  return OK;
}

u8 EEPROM_ReadByte(u8 addr, u8 *data)
{
  u8 state = 0;

  // Start TWI
  I2C_vidStart();

  // Get State
  state = I2C_u8GetStatus();

  /* Check if I2C_ Start*/
  if (state != TW_START)
    return NOK;

  /* Send Slave Address -> For EEPROM 24cXX Address of Chip is 0b1010
   * Set Action To Write -> 1
   * So, we need to send 0xA0
   */

  I2C_vidWrite(0xA0);

  // Get Status
  state = I2C_u8GetStatus();

  // Check if it is TW_MT_SLA_ACK
  if (state != TW_MT_SLA_ACK)
    return NOK;

  // Write the Rest of Location Address(8 Bits)
  I2C_vidWrite(addr);

  /*Get State*/
  state = I2C_u8GetStatus();

  /* check if it is TW_MT_DATA_ACK*/
  if (state != TW_MT_DATA_ACK)
    return NOK;

  // Now The Master Will Be Master Receiver

  // Now we need to Send Start Bit Again
  // Start I2C_
  I2C_vidStart();

  // Get State
  state = I2C_u8GetStatus();

  /* Check if TW_REP_START*/
  if (state != TW_REP_START)
    return NOK;

  /* Send Slave Address -> For EEPROM 24cXX Address of Chip is 0b1010
    * Set Action To Write -> 1
    * So, we need to send 0xA1
    */

  I2C_vidWrite(0xA1);
  // Get Status
  state = I2C_u8GetStatus();

  // Check if it is TW_MR_SLA_ACK
  if (state != TW_MR_SLA_ACK)
    return NOK;

  // Read Data
  *data = I2C_u8ReadData();

  // Get Status
  state = I2C_u8GetStatus();

  // Check if it's Ok
  if (state != TW_MR_DATA_ACK)
  {
    return NOK;
  }
  // I2C_ Stop
  I2C_vidStop();

  // Return Done
  return OK;
}


