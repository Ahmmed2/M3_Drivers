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
#include "MCAL/USART/Cortex_M3_Core_USART.h"

/***************** Includes End *****************/



/***************** Global Variables Start *****************/

/* For Debugging */
uint8_t Counter1 ;
uint8_t Counter2 ;

////////////////////

/* USART */
/* Send Data */
uint8_t USART_Data[] = "Ahmed" ;
/* Receive Data */
uint8_t Global_USARTRX ;
/////////////////////////////

/***************** Global Variables End   *****************/



/***************** Function Declaration  Start *****************/

/* Initiate the Clock Configurations */
void SystemClock_Config (void) ;

/* SysTick Handler Function */
void SysTickHandler_IRQ (void) ;

/* SysTick Handler Function */
void EXTI0Handler_IRQ (void) ;

/* USART1 Handler Function */
void USART1Handler (uint8_t Copy_u8DataRx) ;

/***************** Function Declaration	 End   *****************/


int main(void)
{
	/************************* Initialization Start  **************************/

	/* RCC Configurations */
	SystemClock_Config() ;
	MSTK_voidInit() ;

	/************************* Initialization End    **************************/

	/* Enable Clock on Port A */
	MCAL_RCC_GPIOA_CLK_ENABLE() ;
	/* Enable Clock on Port B */
	MCAL_RCC_GPIOB_CLK_ENABLE() ;
	/* Call Back for USART1 */
	USART1_voidSetCallBack(USART1Handler) ;
	/* Enable Clock on USART */
	RCC_Enable_Clock ( USART1EN ) ;

	/* Enable Interrupt of USART1 */
	NVIC_EnableIRQ(USART1_IRQ) ;


	/************************* Pin Modes Start  **************************/

	/* PORTB PIN12 OUTPUT */
	MGPIO_VoidSetPinDirection(GPIOB,PIN12,OUTPUT_2MHZ_PP);
	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz(TX) */
	MGPIO_VoidSetPinDirection(GPIOA,PIN9,OUTPUT_50MHZ_AFPP);
	/* Setting A10:RX pin as input floating(RX) */
	MGPIO_VoidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	/************************* Pin Modes End    **************************/


	/* USART Configurations */
	MUSART1_voidInit() ;


while (1)
{
	MUSART1_voidTransmit(USART_Data) ;
	MUSART1_voidTransmit((uint8_t*)"\r\n") ;
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
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




void USART1Handler (uint8_t Copy_u8DataRx)
{
	if (Copy_u8DataRx == 'A')
	{
	/* Activate PB12 */
	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait( 2000000 ) ;

	}
}

/********************* ISR *********************/



void SysTickHandler_IRQ (void)
{

	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait(2000000);
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
	MSTK_voidSetBusyWait(2000000);
	MSTK_voidStopInterval() ;
}

void USART3_IRQHandler(void)
{
	/* Pin A0 as O/P HIGH */
	MGPIO_VoidSetPinValue(GPIOA,PIN0,HIGH);
	MSTK_voidSetBusyWait(2000000);
	Counter1 ++ ;
	/* Fire Interrupt of EXTI15_10_IRQ */
	NVIC_SetPendingIRQ(EXTI15_10_IRQ) ;

}

void EXTI15_10_IRQHandler(void)
{
	/* Pin B12 as O/P HIGH */
	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait(2000000);
	Counter2 ++ ;
}

void EXTI0Handler_IRQ (void)
{
	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	MSTK_voidSetBusyWait(2000000);
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
	MSTK_voidSetBusyWait(2000000);

}
