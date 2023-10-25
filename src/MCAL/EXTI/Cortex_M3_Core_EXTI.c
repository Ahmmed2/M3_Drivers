/*
 * Cortex_M3_Core_EXTI.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */


/***************Include Start ***************/

#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
#include "MCAL/EXTI/Cortex_M3_Core_EXTI.h"

/***************Include End ***************/





/* ISR Handle */
static void (* EXTI0_CallBack)  (void) = NULL ;
static void (* EXTI1_CallBack)  (void) = NULL ;



/**
 * Brief : Choose Interrupt sense Mode
 *
 * Parameters[in] :
 *
 *Return :
 *
 *
 * note
 *
 */

void MEXTI_voidInit()
{
	#if EXTI_MODE == RISING
	Set_bit(EXTI -> RSTR,EXTI_LINE);

	#elif EXTI_MODE == FALLING
	Set_bit(EXTI -> FTSR,EXTI_LINE);

	#elif EXTI_MODE == ONCHANGE
	Set_bit(EXTI -> RTSR,EXTI_LINE);
	Set_bit(EXTI -> FTSR,EXTI_LINE);

	#endif

	/* Disable the Interrupt */
	Clear_bit(EXTI ->IMR,EXTI_LINE);

}

/**
 * Brief : Enable Certain Line
 *
 * Parameters[in] :
 *
 *Return :
 * note
 *
 */

void MEXTI_voidEnableEXTI(uint8_t Copy_u8EXTILine)
{

	Set_bit(EXTI -> IMR,Copy_u8EXTILine);

}

/**
 * Brief : Disable Certain Line
 *
 * Parameters[in] :
 *
 *Return :
 * note
 *
 */

void MEXTI_voidDisableEXTI(uint8_t Copy_u8EXTILine)
{
	Clear_bit(EXTI -> IMR,Copy_u8EXTILine);
}



/**
 * Brief : Fire Software Interrupt
 *
 * Parameters[in] :
 *
 *Return :
 * note
 *
 */


void MEXTI_voidSWTrigger(uint8_t Copy_u8EXTILine)
{

	Set_bit(EXTI -> IMR , Copy_u8EXTILine)   ;
	Clear_bit(EXTI -> PR , Copy_u8EXTILine)  ;
	// SWIER returns to 0 when write 1 on the PR Reg
	Set_bit(EXTI -> SWIER , Copy_u8EXTILine) ;
}



/**
 * Brief : Change The Interrupt Sense Mode during The Run Time
 * 		   From failing to rising or on change and vice
 *
 * Parameters[in] :
 *
 *Return :
 * note
 *
 */

void MEXTI_voidSetSignalLatch(uint8_t Copy_u8EXTILine , uint8_t Copy_u8EXTIMode)
{
	switch(Copy_u8EXTIMode)
	{
		case RISING :
			Set_bit(EXTI->RSTR , Copy_u8EXTILine);
			break;

		case FALLING :
			Set_bit(EXTI-> FTSR , Copy_u8EXTILine);
			break;

		case ONCHANGE :
			Set_bit(EXTI -> RSTR , Copy_u8EXTILine);
			Set_bit(EXTI -> FTSR , Copy_u8EXTILine);
			break;
	}
	/* Activate Certain line I want */
	Set_bit(EXTI -> IMR , Copy_u8EXTILine);
}



/************** ISR Call Back **************/

void MEXTI0_voidSetCallBack(void (*ptr) (void))
{

	EXTI0_CallBack = ptr ;

}
void MEXTI1_voidSetCallBack(void (*ptr) (void))
{

	EXTI1_CallBack = ptr ;

}


void EXTI0_IRQHandler (void)
{

	EXTI0_CallBack();

	/* Clear PR Register to disable software interrupt at this line */
	Set_bit(EXTI -> PR , LINE0 ) ;

}

void EXTI1_IRQHandler (void)
{

	EXTI1_CallBack();

	/* Clear PR Register to disable software interrupt at this line */
	Set_bit(EXTI -> PR , LINE0 ) ;

}
