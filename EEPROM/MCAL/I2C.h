/*
 * I2C.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */

#ifndef MCAL_I2C_H_
#define MCAL_I2C_H_

#include "../STD_Types.h"

#define TW_MT_ARB_LOST   0x38
#define TW_MR_ARB_LOST   0x38
#define TW_START         0x08
#define TW_REP_START     0x10
#define TW_MT_SLA_ACK    0x18
#define TW_MT_DATA_ACK   0x28
#define TW_MR_DATA_NOT_ACK  0x58
#define TW_MR_SLA_NOT_ACK   0x48
#define TW_MT_SLA_NOT_ACK   0x20
#define TW_MT_DATA_NOT_ACK  0x30
#define TW_MR_DATA_ACK   0x50
#define TW_MR_SLA_ACK    0x40

void I2C_vidInit(void);
void I2C_vidStart(void);
void I2C_vidStop(void);
void I2C_vidWrite(u8 data);
u8 I2C_u8ReadData(void);
u8 I2C_u8GetStatus(void);

#endif /* MCAL_I2C_H_ */
