/*
 * Cortex_M3_Core_GPIO.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */


/*********************************************************************************/
/* Author    :                                                                   */
/* Version   : V01                                                               */
/* Date      : 29 NOV 2022                                                       */
/*********************************************************************************/



#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
#include "MCAL/GPIO/Cortex_M3_Core_GPIO.h"


/**
 * Brief : Determine Pin Direction
 *
 * Parameters : PORTName , Pin Number , Output_xMHZ(Input)
 *	Output -------> PUSHPULL , OPENDrain , AFPUSHPULL , AFOPENDrain
 *	Input --------> Analog , Floating , PULL_UP_DOWN
 * note
 *
 */


void MGPIO_VoidSetPinDirection(uint8_t Copy_uint8_tPort , uint8_t Copy_uint8_tPin , uint8_t Copy_uint8_tMode)
{
	switch(Copy_uint8_tPort)
	{
	case GPIOA:

		if(Copy_uint8_tPin <= LSB_7PINS )
		{
			GPIOA_CRL &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ));
			GPIOA_CRL |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO );
		}


		else if(Copy_uint8_tPin <= MSB_7PINS )
		{
			/* To Map the values to start from bit 0 */
			Copy_uint8_tPin = Copy_uint8_tPin - 8;
			GPIOA_CRH &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ) );
			GPIOA_CRH |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO );
		}

		break;

	case GPIOB:

		if(Copy_uint8_tPin <= LSB_7PINS )
		{

			GPIOB_CRL &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ) );    /*Reset or clear pin*/
			GPIOB_CRL |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO )  ;    /*apply mode on pin*/
		}


		else if(Copy_uint8_tPin <= MSB_7PINS )
		{
			Copy_uint8_tPin = Copy_uint8_tPin - 8;
			GPIOB_CRH &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ) );
			GPIOB_CRH |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO )  ;
		}

		break;

	case GPIOC:

		if(Copy_uint8_tPin <= LSB_7PINS )
		{
			GPIOC_CRL &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ) );// R M W
			GPIOC_CRL |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO )  ;
		}


		else if(Copy_uint8_tPin <= MSB_7PINS )
		{
			Copy_uint8_tPin = Copy_uint8_tPin - 8;
			GPIOC_CRH &= ~ (( CLEAR_VALUE )  << ( Copy_uint8_tPin * PIN_BITS_NO ) );
			GPIOC_CRH |= (Copy_uint8_tMode ) << ( Copy_uint8_tPin * PIN_BITS_NO )  ;
		}

		break;

	}
}

/**
 * Brief : Write Pin Value
 *
 * Parameters : PORTName , Pin Number , Value
 *
 * note : PORT C Source Current is zero.
 *
 */


void MGPIO_VoidSetPinValue(uint8_t Copy_uint8_tPort , uint8_t Copy_uint8_tPin , uint8_t Copy_uint8_tValue)
{
	switch(Copy_uint8_tPort)
	{
	case GPIOA:
		if( Copy_uint8_tValue == HIGH )
		{
			GPIOA_BSRR = (HIGH << Copy_uint8_tPin);
		}
		else if( Copy_uint8_tValue == LOW )
		{
			GPIOA_BRR = (HIGH << Copy_uint8_tPin);
		}
		break;

	case GPIOB:
		if( Copy_uint8_tValue == HIGH )
		{

			GPIOB_BSRR = (HIGH << Copy_uint8_tPin);
		}
		else if( Copy_uint8_tValue == LOW )
		{

			GPIOB_BRR = (HIGH << Copy_uint8_tPin);
		}
		break;

	case GPIOC:
		if( Copy_uint8_tValue == HIGH )
		{
			GPIOC_BSRR = (HIGH << Copy_uint8_tPin);
		}
		else if( Copy_uint8_tValue == LOW )
		{
			GPIOC_BRR = (HIGH << Copy_uint8_tPin);
		}
		break;

	}
}


/**
 * Brief : Read Pin Value
 *
 * Parameters : PORTName , Pin Number
 *
 *Return : Value of the pin
 *
 * note :
 *
 */


uint8_t MGPIO_uint8_tGetPinValue(uint8_t Copy_uint8_tPort , uint8_t Copy_uint8_tPin)
{
	uint8_t LOC_uint8_tResult = 0 ;   //return value

	switch(Copy_uint8_tPort)
	{
	case GPIOA:
		LOC_uint8_tResult = Get_bit( GPIOA_IDR , Copy_uint8_tPin );
		break;

	case GPIOB:
		LOC_uint8_tResult = Get_bit( GPIOB_IDR , Copy_uint8_tPin );
		break;

	case GPIOC:
		LOC_uint8_tResult = Get_bit( GPIOC_IDR , Copy_uint8_tPin );
		break;
	}

	return LOC_uint8_tResult;
}

/**
 * Brief : Toggle Pin Value
 *
 * Parameters : PORTName , Pin Number
 *
 *Return :
 *
 * note :
 *
 */


void MGPIO_VoidTogglePinValue(uint8_t Copy_uint8_tPort , uint8_t Copy_uint8_tPin )
{
	switch(Copy_uint8_tPort)
	{
	case GPIOA:
		Toggle_bit(GPIOA_ODR,Copy_uint8_tPin) ;
		break;

	case GPIOB:
		Toggle_bit(GPIOB_ODR,Copy_uint8_tPin) ;
		break;

	case GPIOC:
		Toggle_bit(GPIOC_ODR,Copy_uint8_tPin) ;
		break;

	}
}

