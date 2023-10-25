/*
 * Std_Types.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Ahmed
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char 		uint8_t   ;
typedef unsigned short int 	uint16_t  ;
typedef unsigned long int 	uint32_t  ;
typedef signed char 		uints8_t  ;
typedef signed short int	uints16_t ;
typedef signed long int  	uints32_t ;
typedef float  				uintf32_t ;
typedef double 				uintf64_t ;


#define NULL				0

typedef enum
{
	MCAL_NOT_OK  ,
	MCAL_OK
}MCAL_Status_t;


#endif /* STD_TYPES_H_ */
