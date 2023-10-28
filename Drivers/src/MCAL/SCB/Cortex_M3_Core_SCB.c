/*
 * CortexM4_Core_SCB.c
 *
 *  Created on: Oct 15, 2023
 *      Author: Ahmed
 */

/**
 * Brief : Set the Group Priority
 *
 * Details : The parameter Priority_Group is assigned to AICR Reg , Only values from 0:7 is Available
 *
 * Parameter[in] : Priority Group Field
 */

#include <MCAL/SCB/Cortex_M3_Core_SCB.h>

void SCB_SetPriorityGroup (uint32_t Priority_Group)
{


	uint32_t PriorityGroupTemp ;
	/* Copy of Register Value */
	uint32_t RegisterValue = 0 ;

	/* Focus on the LSB 3 bits Only */
	PriorityGroupTemp = ((uint32_t) Priority_Group  &  (uint32_t) (0x07)) ;

	RegisterValue = ((SCB_WRITE_KEY << SCB_WRITE_READ_SHIFT ) | (PriorityGroupTemp << SCB_PRI_GROUP_SHIFT ) )  ;

	SCB-> AIRCR = RegisterValue  ;

}

/**
 * Brief : Get the Group Priority
 *
 * Details : Only values from 0:7 Will be Returned "From bit 8 to 10 "
 *
 * Parameter[in] : None
 */

uint8_t SCB_GetPriorityGroup (void)
{
	return ((SCB->AIRCR>>8) & SCB_LSB_3BITS) ;

}
