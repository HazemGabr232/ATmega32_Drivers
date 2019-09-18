/*
 * EXinterrupt_CFG.h
 *
 *  Created on: Sep 5, 2019
 *      Author: Hazem
 */

#ifndef MCAL_EXINTERRUPT_CFG_H_
#define MCAL_EXINTERRUPT_CFG_H_

//#define SREG	 		*((volatile u8*)0x5F)
#define MCUCR 			*((volatile u8*)0x55)
#define GICR 			*((volatile u8*)0x5B)
#define GIFR			*((volatile u8*)0x5A)
#define MCUCSR			*((volatile u8*)0x54)
//#define INT0_VECTOR 	*((volatile u8*)0x02)
//#define INT1_VECTOR 	*((volatile u8*)0x04)
//#define INT2_VECTOR 	*((volatile u8*)0x06)

#define VECT_INT0 	1
#define VECT_INT1 	2
#define VECT_INT2 	3

#endif /* MCAL_EXINTERRUPT_CFG_H_ */
