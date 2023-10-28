/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed Mahmoud
 * @brief          : Main program body
 ******************************************************************************

 *
 ******************************************************************************
 */





#include "MCAL/NVIC/Cortex_M3_Core_NVIC.h"
#include "MCAL/SCB/Cortex_M3_Core_SCB.h"





uint32_t  Flag ;
uint32_t  Flag2 ;


int main(void)
{
	/* Select Number of Groups and Sub Groups */
	SCB_SetPriorityGroup (SCB_GROUP_PRI_4_SUB_PRI_4) ;

	/* Enable Interrupt */
	NVIC_EnableIRQ(USART3_IRQ)	;
	NVIC_EnableIRQ(EXTI15_10_IRQ)	;


	NVIC_SetPriorityIRQ	(USART3_IRQ    , 4 );
	NVIC_SetPriorityIRQ	(EXTI15_10_IRQ , 0 ) ;
	Flag = NVIC->IP[9] ;
	Flag2 = NVIC->IP[10] ;
	/* Interrupt is Fired */
	NVIC_SetPendingIRQ(USART3_IRQ) ;


    /* Loop forever */
	for(;;)
	{

	}
}

void USART3_IRQHandler(void)
{
	static uint32_t counter ;
	Flag = NVIC_GetPriorityIRQ(USART3_IRQ) ;
	NVIC_SetPendingIRQ(EXTI15_10_IRQ) ;
	counter ++ ;


}
void EXTI15_10_IRQHandler(void)
{
	static uint32_t counter2 ;
	counter2 ++ ;
	Flag2 = NVIC_GetPriorityIRQ (EXTI15_10_IRQ);
}

