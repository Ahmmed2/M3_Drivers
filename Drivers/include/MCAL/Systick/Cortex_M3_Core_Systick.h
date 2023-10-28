/*
 * Cortex_M3_Core_Systick.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Ahmed
 */


#ifndef CORTEXM3_CORE_SYSTICK_H_
#define CORTEXM3_CORE_SYSTICK_H_


/***************Include Start ***************/
#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
/***************Include END *****************/

/***************Macros Definitions Start *****************/

/* Determine Type of Asynchronous Timer */
#define     MSTK    ((MSTK_t*) 0xE000E010)

#define     MSTK_SRC_AHB           0
#define     MSTK_SRC_AHB_8         1

#define     MSTK_SINGLE_INTERVAL    0
#define     MSTK_PERIOD_INTERVAL    1

/* Options: MSTK_SRC_AHB
			MSTK_SRC_AHB_8 */

#define MSTK_CLK_SRC     MSTK_SRC_AHB_8

/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

typedef struct
{
	volatile uint32_t CTRL  ;
	volatile uint32_t LOAD  ;
	volatile uint32_t VAL   ;

}MSTK_t;

/* Define Callback Global Variable */
static void(*MSTK_GlobalPtr)(void) = '\0';


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/


void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( uint32_t Copy_u32Ticks );
void MSTK_voidSetIntervalSingle   ( uint32_t Copy_u32Ticks , void (* Copy_ptr) (void)) ;
void MSTK_voidSetIntervalPeriodic ( uint32_t Copy_u32Ticks , void(* Copy_ptr)(void)) ;
void MSTK_voidStopInterval(void) ;
uint32_t MSTK_u32ElapsedTime (void);
uint32_t MSTK_u32RemainingTime (void);

/***************Software Interfaces Definitions END   *****************/


#endif

