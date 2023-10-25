/*
 * Cortex_M3_Core_Systick.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */


/************ Includes Start ************/
#include "LIB/Std_Types.h"
#include "LIB/Macros.h"

#include "MCAL/Systick/Cortex_M3_Core_Systick.h"

/************ Includes End   *************/


/*********** Global Variable Start  ***********/

/* Variable for interval mode */
static uint8_t MSTK_u8ModeOfInterval;

/*********** Global Variable End    ***********/

/**
 * Brief : Initialize Systick
 *
 * Parameters[in] :
 *
 * Return :
 *
 * Note  :
 *
 */

void MSTK_voidInit(void)
{
#if MSTK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	MSTK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	MSTK -> CTRL = 0;
#endif
}

/**
 * Brief : Synchronous Delay Function
 *
 * Parameters[in] : Value of delay
 *
 * Return :
 *
 * Note  : it is preferred to make clock source ANH/8(1ms).
 *
 */

void MSTK_voidSetBusyWait( uint32_t Copy_u32Ticks )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	Set_bit(MSTK -> CTRL, 0);
	/* Wait till flag is raised */
	while( (Get_bit(MSTK -> CTRL,16)) == 0);
	/* Stop Timer */
	Clear_bit(MSTK -> CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

/**
 * Brief : Asynchronous Delay Function one Time then Execute ISR
 *
 * Parameters[in] : Value of delay
 * Parameters[in] : Pointer To Function to be Executed
 *
 * Return :
 *
 * Note  :
 *
 */

void MSTK_voidSetIntervalSingle  ( uint32_t Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	Set_bit(MSTK -> CTRL, 0);
	/* Save CallBack */
	MSTK_GlobalPtr = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	Set_bit(MSTK -> CTRL, 1);
}

/**
 * Brief : Asynchronous Delay Function Periodic then Execute ISR
 *
 * Parameters[in] : Value of delay
 * Parameters[in] : Pointer To Function to be Executed
 *
 * Return :
 *
 * Note  :
 *
 */

void MSTK_voidSetIntervalPeriodic( uint32_t Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks;
	/* Start Timer */
	Set_bit(MSTK -> CTRL, 0);
	/* Save CallBack */
	MSTK_GlobalPtr = Copy_ptr;
	/* Set Mode to PERIODIC */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	Set_bit(MSTK -> CTRL, 1);
}

/**
 * Brief : Stop timer for Periodic Asynchronous functions
 *
 * Parameters[in] :
 *
 * Return :
 *
 * Note  :
 *
 */

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	Clear_bit(MSTK -> CTRL, 1);
	/* Stop Timer */
	Set_bit(MSTK -> CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

/**
 * Brief : Get Counter Time (Elapsed Time )
 *
 * Parameters[in] :
 *
 * Return : Number of Ticks Counted
 *
 * Note  :
 *
 */


uint32_t  MSTK_u32GetElapsedTime(void)
{
	uint32_t Local_u32ElapsedTime;
	/* Counted Time = load - value   */
	Local_u32ElapsedTime = MSTK -> LOAD - MSTK -> VAL ;
	return Local_u32ElapsedTime;
}

/**
 * Brief : Get Remaining Ticks
 *
 * Parameters[in] :
 *
 * Return : Remaining Ticks
 *
 * Note  :
 *
 */

uint32_t  MSTK_u32GetRemainingTime(void)
{
	uint32_t Local_u32RemainTime;
	Local_u32RemainTime = MSTK -> VAL ;
	return Local_u32RemainTime;
}


/* SysTick ISR Handle */

void SysTick_Handler(void)
{
	volatile uint8_t Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		 Clear_bit(MSTK -> CTRL, 1);
		/* Stop Timer */
		 Set_bit(MSTK -> CTRL, 0);
		 MSTK -> LOAD = 0;
		 MSTK -> VAL  = 0;
	}

	/* Callback notification */
	MSTK_GlobalPtr();

	/* Clear interrupt flag */
	Local_u8Temporary = Get_bit(MSTK -> CTRL,16);
}
