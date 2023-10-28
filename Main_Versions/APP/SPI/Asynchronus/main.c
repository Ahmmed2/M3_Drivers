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
#include "MCAL/SPI/Cortex_M3_Core_SPI.h"

/***************** Includes End *****************/

/***************** Defines Start *****************/


//#define Test_Node                0   		//Master

#define Test_Node            	 1  	 	//Slave

/***************** Defines End   *****************/

/***************** Global Variables Start *****************/

/* For Debugging */
uint32_t Counter1 ;
uint8_t Counter2 ;

////////////////////

/* USART */

/* USART Send Data */
uint8_t USART_Data[] = "Ahmed" ;
/* Receive Data */
uint8_t Global_USARTRX ;
/* SPI Send Data */
uint8_t SPI_Data = 'B' ;

/////////////////////////////

/***************** Global Variables End   *****************/



/***************** Function Declaration  Start *****************/

/* Initiate the Clock Configurations */
void SystemClock_Config (void) ;

/***************** Function Declaration	 End   *****************/


int main(void)
{

	/************************* Initialization Start  **************************/

	/* RCC Configurations */
	SystemClock_Config() ;
	/* Enable Interrupt SPI1 */
	NVIC_EnableIRQ(SPI1_IRQ);
	/* Enable Clock on SPI1 */
	RCC_Enable_Clock ( SPI1EN ) ;


	/************************* Initialization End    **************************/

	/* Enable Clock on Port A */
	MCAL_RCC_GPIOA_CLK_ENABLE() ;
	/* Enable Clock on Port B */
	MCAL_RCC_GPIOB_CLK_ENABLE() ;




	/************************* Pin Modes Start  **************************/

	/* Pin A0 O/P */
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_2MHZ_PP);
	/* Pin B12 O/P */
	MGPIO_VoidSetPinDirection(GPIOB,PIN12,OUTPUT_2MHZ_PP);


#if Test_Node == 0

	/* Pin A4 O/P  "SS" */
	//MGPIO_VoidSetPinDirection(GPIOA,PIN4,OUTPUT_50MHZ_AFPP);
	/* Pin A5 O/P "CLK" */
	MGPIO_VoidSetPinDirection(GPIOA,PIN5,OUTPUT_50MHZ_AFPP);
	/* Pin A6 I/P "MISO1*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN6,INPUT_FLOATING);
	/* Pin A7 O/P "MOSI" */
	MGPIO_VoidSetPinDirection(GPIOA,PIN7,OUTPUT_50MHZ_AFPP);



#elif Test_Node == 1

	/* Pin A4 I/P  "SS" */
	//MGPIO_VoidSetPinDirection(GPIOA,PIN4,INPUT_FLOATING);
	/* Pin A5 I/P "CLK" */
	MGPIO_VoidSetPinDirection(GPIOA,PIN5,INPUT_FLOATING);
	/* Pin A6 O/P "MISO1*/
	MGPIO_VoidSetPinDirection(GPIOA,PIN6,OUTPUT_50MHZ_AFPP);
	/* Pin A7 I/P "MOSI" */
	MGPIO_VoidSetPinDirection(GPIOA,PIN7,INPUT_FLOATING);


#endif

	/************************* Pin Modes End    **************************/

	MSPI1_voidInit() ;





while (1)
{



//	MSPI1_voidSend(SPI_Data) ;
/*	MSPI1_voidReceive(&Counter2);
	if (Counter2 == 'B' )
	{
		MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);

	}*/

/*	MSPI1_voidReceive(&Counter2 ) ;
	if (Counter2 == 'A')
	{
	MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	}
	else
	{
	MGPIO_VoidSetPinValue(GPIOB,PIN12,LOW);
	}*/


}
return 0 ;
}

void SystemClock_Config ()
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


/********************* ISR *********************/

void SPI1_IRQHandler(void)
{
	/* Pin A0 O/P HIGH */
	//MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	//MSTK_voidSetBusyWait(2000000);
	Counter1 ++ ;

	Counter2 = SPI1 -> DR ;
	if (Counter2 == 'B' )
	{
		MGPIO_VoidSetPinValue(GPIOB,PIN12,HIGH);
	}
	//Clear_bit(SPI1->CR2,6);

}

