/*
 * CortexM3_Core_NVIC.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Ahmed
 */


#include <MCAL/NVIC/Cortex_M3_Core_NVIC.h>


/**
 * Brief : Enable Certain Interrupt
 *
 * Parameters : IRQn Device specific Interrupt number
 *
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

void NVIC_EnableIRQ (IRQn_Type IRQn)
{
		if ((uint32_t)IRQn >= 0 )
		{
			// Select which Register and which Line.
			NVIC->ISER [ ( ( (uint32_t)IRQn ) >> POWER_REG_SIZE ) ] = (1UL << ( ( (uint32_t)IRQn ) & REG_SIZE)) ;
		}
}


/**
 * Brief : Disable Certain Interrupt
 *
 * Parameters : IRQn Device specific Interrupt number
 *
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

void NVIC_DisableIRQ (IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0 )
	{
		// Select which Register and which Line.
		NVIC->ICER [ ( ( (uint32_t)IRQn ) >> POWER_REG_SIZE ) ] = (1UL << ( ( (uint32_t)IRQn ) & REG_SIZE)) ;
	}
}
/**
 * Brief : Set Pending Flag of Certain Interrupt
 *
 * Parameters : IRQn Device specific Interrupt number
 *
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

void NVIC_SetPendingIRQ 	(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0 )
	{
		// Select which Register and which Line.
		NVIC->ISPR [ ( ( (uint32_t)IRQn ) >> POWER_REG_SIZE ) ] = (1UL << ( ( (uint32_t)IRQn ) & REG_SIZE)) ;
	}
}
/**
 * Brief : Clear Pending Flag of Certain Interrupt
 *
 * Parameters : IRQn Device specific Interrupt number
 *
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

void NVIC_ClearPendingIRQ	(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0 )
	{
		// Select which Register and which Line.
		NVIC->ICPR [ ( ( (uint32_t)IRQn ) >> POWER_REG_SIZE ) ] = (1UL << ( ( (uint32_t)IRQn ) & REG_SIZE)) ;
	}

}

/**
 * Brief : Read Active Register
 *
 *Details : Determine if Interrupt is Being Served or Not
 *
 * Parameters : IRQn Device specific Interrupt number
 *
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

uint32_t NVIC_GetActive		(IRQn_Type IRQn)
{
	return ((NVIC->IABR [ ( ( (uint32_t)IRQn ) >> POWER_REG_SIZE ) ]) & (1UL << ( ( (uint32_t)IRQn ) & REG_SIZE))) != 0 ? 1UL : 0UL  ;
}

/**
 * Brief : Set Priority to Certain Peripheral
 *
 *Details :Set Priority to Certain Peripheral by putting the value in IR Register
 *
 * Parameters[in] : IRQn Device specific Interrupt number
 * Parameters[in] : Priority Device Priority
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */

void NVIC_SetPriorityIRQ	(IRQn_Type IRQn , uint8_t Priority )
{

	NVIC->IP[(uint32_t)IRQn ] = ((Priority << NVIC_MC_PRI_SIZE ) & (uint32_t) 0XFF )  ;

}


/**
 * Brief : Get Priority to Certain Peripheral
 *
 *Details :Get Priority to Certain Peripheral by Reading the value in IR Register
 *
 * Parameters[in] : IRQn Device specific Interrupt number
 * note IRQn must be non-Negative (NVIC Control only external Exception)
 *
 */
uint8_t NVIC_GetPriorityIRQ	(IRQn_Type IRQn)
{
	return ((NVIC->IP[(uint32_t)IRQn]) >> NVIC_MC_PRI_SIZE ) ;
}
