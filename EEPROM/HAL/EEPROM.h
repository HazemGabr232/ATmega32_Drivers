/*
 * EEPROM.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */

#ifndef HAL_EEPROM_H_
#define HAL_EEPROM_H_
#include "../STD_Types.h"

void EEPROM_Init(void);
u8 EEPROM_WriteByte(u8 addr, u8 data);
u8 EEPROM_ReadByte(u8 addr, u8 *data);

#define OK  0
#define NOK	1

#endif /* HAL_EEPROM_H_ */
