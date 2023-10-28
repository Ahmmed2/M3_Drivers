/*
 * Cortex_M3_Core_RCC.c

 *
 *  Created on: Oct 16, 2023
 *      Author: Ahmed
 */




/***************Include Start ***************/
#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
#include "MCAL/RCC/Cortex_M3_Core_RCC.h"
/***************Include END *****************/



/**
 * Brief : Determine Which Clock is operating
 *
 * Parameters[in] : Structure which determine the type of clock and it is ON/OFF
 *
 *Return : Indication if API work Correctly or not
 * note
 *
 */


MCAL_Status_t RCC_OSC_Config (RCC_Osc_t *RCC_Init)
{
	MCAL_Status_t Return_Status =  MCAL_OK ;

	if (NULL == RCC_Init)
	{
		Return_Status = MCAL_NOT_OK ;
	}
	else
	{
		/********************* HSE *********************/
		if (RCC_HSE_Oscillator == RCC_Init->OscillatorType)
		{
			if (RCC_HSE_ON == RCC_Init->HSE_State )
			{
				/* HSE ON */
				Set_bit  (RCC->CR  ,HSE_BIT_CR) ;
				Set_bit  (RCC->CFGR,HSE_BIT0_CFGR) ;
				Clear_bit(RCC->CFGR,HSE_BIT1_CFGR) ;
			}
			else
			{
				/* HSE OFF */
				Clear_bit(RCC->CR,HSE_BIT0_CFGR) ;
				Clear_bit  (RCC->CFGR,HSE_BIT0_CFGR) ;

			}

		}
		/********************* HSI *********************/
		else if (RCC_HSI_Oscillator == RCC_Init->OscillatorType)
		{
				/* TBD */
		}
		/********************* LSE *********************/
		else if (RCC_LSE_Oscillator == RCC_Init->OscillatorType)
		{
				/* TBD */
		}
		/********************* LSI *********************/
		else if (RCC_LSI_Oscillator == RCC_Init->OscillatorType )
		{
				/* TBD */
		}
		else
		{
			/* Nothing To Do */
		}
	}

	return Return_Status ;
}

/**
 * Brief : Determine Which Clock is operating
 *
 * Parameters[in] : Structure which determine the type of clock and it is ON/OFF
 *
 *Return : Indication if API work Correctly or not
 *
 * note
 *
 */

MCAL_Status_t RCC_Clock_Config (RCC_PreScaler_t *RCC_ClkInit)
{
	MCAL_Status_t Return_Status =  MCAL_OK ;


	if (NULL == RCC_ClkInit)
	{
		Return_Status = MCAL_NOT_OK ;
	}
	else
	{
		RCC->CFGR |= ((RCC_ClkInit->AHBCLKDIVIDER) | (RCC_ClkInit->APB1CLKDIVIDER) | (RCC_ClkInit->APB2CLKDIVIDER));
	}


	return Return_Status ;
}

/**
 * Brief : Enable Clock which choosed
 *
 * Parameters[in] : Structure which determine the type of clock and it is ON/OFF
 *
 *Return : Indication if API work Correctly or not
 *
 * note
 *
 */

MCAL_Status_t RCC_Enable_Clock (uint32_t Copy_PeripheralID )
{
	MCAL_Status_t Return_Status =  MCAL_OK ;



	if ( Copy_PeripheralID <= AHB_MAX )
	{
		Set_bit(RCC->AHBENR,Copy_PeripheralID);
	}
	else if (Copy_PeripheralID >= APB1_MIN && Copy_PeripheralID <= APB1_MAX )
	{
		Set_bit(RCC->APB1ENR,(Copy_PeripheralID-APB1_MIN));
	}
	else if (Copy_PeripheralID >= APB2_MIN && Copy_PeripheralID <= APB2_MAX )
	{
		Set_bit(RCC->APB2ENR,(Copy_PeripheralID-APB2_MIN));
	}
	else Return_Status = MCAL_NOT_OK ;


	return Return_Status ;



}
