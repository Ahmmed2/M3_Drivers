/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed_Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 * Tested 		   : 18-10-2023
 ******************************************************************************
 */




/***************** Includes Start *****************/

#include "MCAL/RCC/Cortex_M3_Core_RCC.h"
#include "MCAL/GPIO/Cortex_M3_Core_GPIO.h"
#include "MCAL/SCB/Cortex_M3_Core_SCB.h"
#include "MCAL/NVIC/Cortex_M3_Core_NVIC.h"
#include "MCAL/Systick/Cortex_M3_Core_Systick.h"
#include "MCAL/AFIO/Cortex_M3_Core_AFIO.h"
#include "MCAL/EXTI/Cortex_M3_Core_EXTI.h"

/***************** Includes End *****************/



/***************** Global Variables Start *****************/
/* For Debugging */
uint8_t Counter1 ;
uint8_t Counter2 ;
/***************** Global Variables End   *****************/



/***************** Function Declaration  Start *****************/

/* Initiate the Clock Configurations */
void SystemClock_Config (void) ;

/* SysTick Handler Function */
void SysTickHandler_IRQ (void) ;

/* SysTick Handler Function */
void EXTI0Handler_IRQ (void) ;

/***************** Function Declaration	 End   *****************/


int main(void)
{
	/************************* Initialization Start  **************************/

	/* RCC Configurations */
	SystemClock_Config() ;
	/* SysTick Configurations */
	MSTK_voidInit() ;

	/************************* Initialization End    **************************/

	/* Enable Clock on Port A */
	MCAL_RCC_GPIOA_CLK_ENABLE() ;
	/* Enable Clock on Port B */
	RCC_Enable_Clock ( IOPBEN ) ;
	/* Enable Clock on AFIO */
	RCC_Enable_Clock ( AFIOEN ) ;

	/************************* Pin Modes Start  **************************/

	/* Pin A0 O/P */
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	/* Pin B12 O/P */
	MGPIO_VoidSetPinDirection(GPIOB,PIN12,OUTPUT_2MHZ_PP);

	/************************* Pin Modes End    **************************/


	/* Set Call Back for EXTI0 */
	MEXTI0_voidSetCallBack(EXTI0Handler_IRQ) ;
	/* AFIO Config */
	MAFIO_voidSetEXTIConfig ( LINE0 , AFIOA ) ;

	/* EXTI Initialize */
	 MEXTI_voidInit() ;

	 /* EXTI Line Clock */
	 MEXTI_voidSetSignalLatch(LINE0 , FALLING);
	 /* Enable Interrupt for EXTI0 */
	 NVIC_EnableIRQ(EXTI0_IRQ)	;
	 NVIC_SetPendingIRQ(EXTI0_IRQ) ;

while (1)
{
	/* LED Blink */
	MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
	MSTK_voidSetIntervalSingle(1000000, SysTickHandler_IRQ );
	MGPIO_VoidSetPinValue(GPIOA,PIN0,LOW);
	MSTK_voidSetIntervalSingle(1000000, SysTickHandler_IRQ );

}


	return 0 ;
}

void SystemClock_Config (void)
{
	/* User Data Types Initialization */
	MCAL_Status_t Return_Status = MCAL_OK ;
	RCC_Osc_t RCC_Init = {0} ;
	RCC_PreScaler_t RCC_PreScalerInit = {0} ;

	/* Configure Clock */
	RCC_Init . OscillatorType = RCC_HSE_Oscillator ;
	RCC_Init . HSE_State = RCC_HSE_ON ;
	Return_Status = RCC_OSC_Config (&RCC_Init) ;

	/* Configure Pre_Scaler */
	RCC_PreScalerInit.AHBCLKDIVIDER  = RCC_AHB_DIV_1 ;
	RCC_PreScalerInit.APB1CLKDIVIDER = RCC_APB1_DIV_1  ;
	RCC_PreScalerInit.APB2CLKDIVIDER = RCC_APB2_DIV_1 ;
	Return_Status = RCC_Clock_Config(&RCC_PreScalerInit) ;

	while (NULL == Return_Status);

}


void SysTickHandler_IRQ (void)
{

	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait(2000000);
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
	MSTK_voidSetBusyWait(2000000);
	MSTK_voidStopInterval() ;
}


/********************* ISR *********************/


void EXTI0Handler_IRQ (void)
{
	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait(2000000);
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
	MSTK_voidSetBusyWait(2000000);

}
