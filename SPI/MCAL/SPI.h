/*
 * SPI.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Hazem
 */

#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

#include "../STD_Types.h"

#define MASTER	0
#define SLAVE	1

void SPI_vidInit(u8 mode);
void SPI_vidSend(u8 data);
u8 SPI_u8read(void);

#endif /* MCAL_SPI_H_ */
