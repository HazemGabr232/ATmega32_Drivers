/*
 * SPI_CFG.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Hazem
 */

#ifndef MCAL_SPI_CFG_H_
#define MCAL_SPI_CFG_H_

#include "../STD_Types.h"

#define SPCR		*((volatile u8*)0x2D)
#define SPSR		*((volatile u8*)0x2E)
#define SPDR		*((volatile u8*)0x2F)

#endif /* MCAL_SPI_CFG_H_ */
