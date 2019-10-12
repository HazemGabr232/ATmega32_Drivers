/*
 * I2C_CFG.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Hazem
 */

#ifndef MCAL_I2C_CFG_H_
#define MCAL_I2C_CFG_H_

#define TWDR			*((volatile u8*)0x23)
#define TWAR			*((volatile u8*)0x22)
#define TWSR			*((volatile u8*)0x21)
#define TWBR			*((volatile u8*)0x20)
#define TWCR			*((volatile u8*)0x56)
#endif /* MCAL_I2C_CFG_H_ */
