/*
 * CortexM3_Core_SCB.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Ahmed
 */




#ifndef CORTEXM3_CORE_SCB_H_
#define CORTEXM3_CORE_SCB_H_

/***************Include Start ***************/
#include "LIB/Std_Types.h"

/***************Include END *****************/

/***************Macros Definitions Start *****************/

#define SCB_BASE    		 	(0xE000ED00UL)
#define SCB     			 ((SCB_Type*)SCB_BASE)



#define SCB_WRITE_KEY		 					0X05FA
#define SCB_READ_KEY		 					0XFA05
#define SCB_PRI_GROUP_SHIFT				  		  8
#define SCB_WRITE_READ_SHIFT				  	  16
#define SCB_LSB_3BITS							   7
/* Modes */
#define SCB_GROUP_PRI_16_SUB_PRI_0		0b011
#define SCB_GROUP_PRI_8_SUB_PRI_2		0b100
#define SCB_GROUP_PRI_4_SUB_PRI_4		0b101
#define SCB_GROUP_PRI_2_SUB_PRI_8		0b110
#define SCB_GROUP_PRI_0_SUB_PRI_16		0b111


/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

/* Register Definition */
typedef struct
{
	volatile uint32_t		CPUID 	;
	volatile uint32_t       ICSR  	;
	volatile uint32_t		VTOR 	;
	volatile uint32_t		AIRCR 	;
	volatile uint32_t		SCR 	;
	volatile uint32_t		CCR 	;
	volatile uint32_t		SHPR1   ;
	volatile uint32_t		SHPR2	;
	volatile uint32_t		SHPR3	;
	volatile uint32_t		SHCSR	;
	volatile uint32_t		CFSR	;

}SCB_Type;


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/
void SCB_SetPriorityGroup (uint32_t Priority_Group) ;
uint8_t SCB_GetPriorityGroup (void) ;
/***************Software Interfaces Definitions END   *****************/


#endif
