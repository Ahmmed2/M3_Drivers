/*
 * Cortex_M3_Core_AFIO.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */


/***************** Includes Start *****************/

#include "LIB/Std_Types.h"
#include "MCAL/AFIO/Cortex_M3_Core_AFIO.h"


/***************** Includes End *****************/

/**
 * Brief : Configure Certain pin on Certain Line as External Interrupt
 *
 * Parameters : Line Number , PortName
 *
 * Note : you are able only to activate only one pin in each line at a time.
 *
 */


void MAFIO_voidSetEXTIConfig ( uint8_t Copy_u8EXTLine , uint8_t Copy_u8PortMap )
{
	/* Determine Which EXTICR will Enter */
	uint8_t Local_u8RegIndex = 0 ;


	if(Copy_u8EXTLine <= LINE0_LAST_BIT_POSTION )
	{
	    Local_u8RegIndex = 0;
	}
	else if(Copy_u8EXTLine <= LINE1_LAST_BIT_POSTION)
	{
		Local_u8RegIndex = 1;


		Copy_u8EXTLine -= 4;
	}
	else if(Copy_u8EXTLine <= LINE2_LAST_BIT_POSTION)
	{
		Local_u8RegIndex = 2;
		Copy_u8EXTLine -= 8;

	}
	else if(Copy_u8EXTLine <= LINE3_LAST_BIT_POSTION)
	{
		Local_u8RegIndex = 3;
		Copy_u8EXTLine -= 12;
	}

	/* Reset First --> (avoiding overwrite)*/
	MAFIO->EXTICR[Local_u8RegIndex] &= ~((BIT_MASKING) << (Copy_u8EXTLine * LINE_BITS_NO));
	/* Write Desired Value */
	MAFIO->EXTICR[Local_u8RegIndex]  |= ((Copy_u8PortMap) << (Copy_u8EXTLine * LINE_BITS_NO));
}
