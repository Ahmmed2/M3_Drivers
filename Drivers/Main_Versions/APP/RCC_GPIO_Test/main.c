/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Ahmed_Mahmoud
 * @brief          : Main program body
 ******************************************************************************
 * Tested 18-10-2023
 ******************************************************************************
 */




/***************** Includes Start *****************/
#include "MCAL/RCC/Cortex_M3_Core_RCC.h"
#include "MCAL/GPIO/Cortex_M3_Core_GPIO.h"
#include "MCAL/SCB/Cortex_M3_Core_SCB.h"
#include "MCAL/NVIC/Cortex_M3_Core_NVIC.h"

/***************** Includes End *****************/



/***************** Global Variables Start *****************/

/***************** Global Variables End   *****************/



/***************** Function Declaration  Start *****************/

/* Initiate the Clock Configurations */
void SystemClock_Config (void) ;

/***************** Function Declaration	 End   *****************/


int main(void)
{
	/* RCC Configurations */
	SystemClock_Config() ;

	/* Enable Clock on Port A */
	MCAL_RCC_GPIOA_CLK_ENABLE() ;
	//RCC_Enable_Clock ( IOPAEN ) ;

	/* Pin Modes */
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_2MHZ_PP);  //Pin A1 O/P
	uint8_t i ;
	while (1)
	{
		/* Pin A1 as O/P HIGH */
		MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);

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
