



#ifndef CORTEXM3_CORE_RCC_H_
#define CORTEXM3_CORE_RCC_H_


/***************Include Start ***************/
#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
/***************Include END *****************/

/***************Macros Definitions Start *****************/

#define RCC_BASE		(0x40021000UL)
#define RCC 			((RCC_Type*)RCC_BASE)

/* Bit Masking */
#define GPIOA_BIT_SHIFT				2
#define GPIOB_BIT_SHIFT				3
#define GPIOC_BIT_SHIFT				4
#define GPIOD_BIT_SHIFT				5

/* Oscillator Types */
#define RCC_NO_Oscillator          0x0U
#define RCC_HSE_Oscillator		   0X1U
#define RCC_HSI_Oscillator		   0X2U
#define RCC_LSE_Oscillator		   0X3U
#define RCC_LSI_Oscillator		   0X4U

/* Determine if Certain Oscillator is ON/OFF */
#define RCC_HSE_OFF				0X00
#define RCC_HSE_ON				0X01
#define RCC_LSE_OFF				0X00
#define RCC_LSE_ON				0X01
#define RCC_HSI_OFF				0X00
#define RCC_HSI_ON				0X01
#define RCC_LSI_OFF				0X00
#define RCC_LSI_ON				0X01

/* Modes Bits In Register */
#define HSE_BIT_CR					16
#define HSE_BIT0_CFGR				0
#define HSE_BIT1_CFGR				1

/*************************** AHB Pre_Scalers ***************************/

#define      RCC_AHB_DIV_1				0x00000000U
#define      RCC_AHB_DIV_2				0x00000080U
#define      RCC_AHB_DIV_4				0x00000090U
#define      RCC_AHB_DIV_8				0x000000A0U
#define      RCC_AHB_DIV_16				0x000000B0U
#define      RCC_AHB_DIV_64				0x000000C0U
#define      RCC_AHB_DIV_128			0x000000D0U
#define      RCC_AHB_DIV_256			0x000000E0U
#define      RCC_AHB_DIV_512			0x000000F0U

/*************************** APB1 Pre_Scalers ***************************/

#define      RCC_APB1_DIV_1			    0x00000000U
#define      RCC_APB1_DIV_2			    0x00000400U
#define      RCC_APB1_DIV_4			    0x00000500U
#define      RCC_APB1_DIV_8			    0x00000600U
#define      RCC_APB1_DIV_16		    0x00000700U

/*************************** APB2 Pre_Scalers ***************************/

#define      RCC_APB2_DIV_1			    0x00000000U
#define      RCC_APB2_DIV_2			    0x00002000U
#define      RCC_APB2_DIV_4			    0x00002800U
#define      RCC_APB2_DIV_8			    0x00003000U
#define      RCC_APB2_DIV_16		    0x00003800U

/* Bus Names */
#define		 AHB 			0
#define 	 APB1			1
#define 	 APB2			2
/* Buses Ranges To Control Peripherals */
#define	    AHB_MAX			16
#define		APB1_MIN		17
#define		APB1_MAX		46
#define		APB2_MIN		47
#define		APB2_MAX		61

/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/


/*************************** Enable Ports ****************************/

#define MCAL_RCC_GPIOA_CLK_ENABLE()			    (RCC->APB2ENR |= 1 << GPIOA_BIT_SHIFT)
#define MCAL_RCC_GPIOB_CLK_ENABLE()			    (RCC->APB2ENR |= 1 << GPIOB_BIT_SHIFT)
#define MCAL_RCC_GPIOC_CLK_ENABLE()			    (RCC->APB2ENR |= 1 << GPIOC_BIT_SHIFT)
#define MCAL_RCC_GPIOD_CLK_ENABLE()			    (RCC->APB2ENR |= 1 << GPIOD_BIT_SHIFT)


/*************************** Disable Ports ***************************/

#define MCAL_RCC_GPIOA_CLK_DISABLE()			(RCC->APB2ENR &= ~(1 << GPIOA_BIT_SHIFT))
#define MCAL_RCC_GPIOB_CLK_DISABLE()			(RCC->APB2ENR &= ~(1 << GPIOB_BIT_SHIFT))
#define MCAL_RCC_GPIOC_CLK_DISABLE()			(RCC->APB2ENR &= ~(1 << GPIOD_BIT_SHIFT))
#define MCAL_RCC_GPIOD_CLK_DISABLE()			(RCC->APB2ENR &= ~(1 << GPIOD_BIT_SHIFT))



/***************Macros Functions Definitions END   *****************/



/***************Data Type Definitions Start *****************/




/* Register Definitions */

typedef struct
{
	volatile uint32_t  CR  			;
	volatile uint32_t  CFGR  		;
	volatile uint32_t  CIR  		;
	volatile uint32_t  APB2RSTR  	;
	volatile uint32_t  APB1RSTR  	;
	volatile uint32_t  AHBENR	    ;
	volatile uint32_t  APB2ENR      ;
	volatile uint32_t  APB1ENR      ;
	volatile uint32_t  BDCR  		;
	volatile uint32_t  CSR  		;
	volatile uint32_t  AHBSTR  		;
	volatile uint32_t  CFGR2  		;

}RCC_Type;


/* Determine Type of Clock,ON/OFF */
typedef struct
{
	uint32_t OscillatorType ;  	/* !< Configured at @ref Oscillator Types  */
	uint8_t HSE_State       ;  	/* !< Configured at @ref ON/OFF  */
	uint8_t LSE_State       ; 	/* !< Configured at @ref ON/OFF  */
	uint8_t HSI_State       ;	/* !< Configured at @ref ON/OFF  */
	uint8_t LSI_State       ;	/* !< Configured at @ref ON/OFF  */
}RCC_Osc_t;


/* Determine pre_scaler of each Bus */
typedef struct
{
	uint32_t  AHBCLKDIVIDER   	; 	/* !< Configured at @ref AHB Pre_Scalers   */
	uint32_t  APB1CLKDIVIDER   	;	/* !< Configured at @ref APB1 Pre_Scalers  */
	uint32_t  APB2CLKDIVIDER   	;	/* !< Configured at @ref APB2 Pre_Scalers  */

}RCC_PreScaler_t;

enum
{
	/* AHB Peripherals !> Range from 0 to 16 */

	DMA1 			,
	DMA2			,
	SRAM			,
	RESERVED0 		,
	FLITFEN 		,
	RESERVED1 		,
	CRCEN			,
	OTGFSEN = 12	,
	RESERVED2 		,
	ETHMACEN 		,
	ETHMACTXEN 		,
	ETHMACRXEN = 16 ,

	/* APB1 Peripherals !> Range from 17 to 46 */

	TIM2EN   = 17	,
	TIM3EN			,
	TIM4EN			,
	TIM5EN			,
	TIM6EN			,
	TIM7EN			,
	WWDGEN	 = 28 	,
	SPI2EN 	 = 31 	,
	SPI3EN 			,
	USART2EN = 34 	,
	USART3EN 		,
	USART4EN 		,
	USART5EN 		,
	I2C1EN 			,
	I2C2EN 			,
	CAN1EN 	= 42 	,
	CAN2EN 			,
	BKPEN 			,
	PWREN 			,
	DACEN 	= 46 		,

	/* APB2 Peripherals !> Range from 47 to 61 */
	AFIOEN  = 47 	,
	IOPAEN  = 49 	,
	IOPBEN 			,
	IOPCEN 			,
	IOPDEN 			,
	IOPEEN 			,
	ADC1EN  = 56 	,
	ADC2EN 			,
	TIM1EN 			,
	SPI1EN 			,
	USART1EN = 61



}CLK_Peripheral_t;

/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/
MCAL_Status_t RCC_OSC_Config   (RCC_Osc_t *RCC_Init) ;
MCAL_Status_t RCC_Clock_Config (RCC_PreScaler_t *RCC_ClkInit) ;
MCAL_Status_t RCC_Enable_Clock (uint32_t Copy_PeripheralID ) ;
/***************Software Interfaces Definitions END   *****************/

#endif
