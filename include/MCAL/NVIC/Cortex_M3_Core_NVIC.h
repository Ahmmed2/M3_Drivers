/*
 * CortexM3_Core_NVIC.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Ahmed
 */

#ifndef CORTEXM3_CORE_NVIC_H_
#define CORTEXM3_CORE_NVIC_H_

/***************Include Start ***************/
#include "LIB/Std_Types.h"
/***************Include END *****************/

/***************Macros Definitions Start *****************/

#define NVIC_BASE     			 (0xE000E100UL)
#define NVIC         		 ((NVIC_Type*)NVIC_BASE)
#define POWER_REG_SIZE					5
#define REG_SIZE					   0x1F     			//31 in Decimal
#define NVIC_MC_PRI_SIZE				 4
/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

/* Register Definitions */
typedef struct
{
	volatile uint32_t ISER[8U] ;
	uint32_t RESERVED0[24U] ;
	volatile uint32_t ICER[8U] ;
	uint32_t RESERVED1[24U] ;
	volatile uint32_t ISPR[8U] ;
	uint32_t RESERVED2[24U] ;
	volatile uint32_t ICPR[8U] ;
	uint32_t RESERVED3[24U] ;
	volatile uint32_t IABR[8U] ;
	uint32_t RESERVED4[56U] ;
	volatile uint8_t IP[240U] ;
	uint32_t RESERVED5[644U] ;
	volatile uint32_t STIR ;

}NVIC_Type;


typedef enum
{


	NMI_IRQ 			      = -14      ,
	MemManage_IRQ  	          = -12      ,          /* Memory management */
	BusFault_IRQ		      = -11      ,          /* Pre-fetch fault, memory access faulT */
	UsageFault_IRQ		      = -10      ,          /* Undefined instruction or illegal st */
	SVC_IRQ			          = -5       ,          /* System service call via SWI instruc */
	DebugMon_IRQ		      = -4       ,          /* Debug Monitor */
	PendSV_IRQ		          = -2       ,          /* Pendable request for system service */
	SysTick_IRQ		          = -1       ,


	WWDG_IRQ			      =  0 		 ,          /* Window WatchDog              */
	PVD_IRQ			           			 ,          /* PVD through EXTI Line detection */
	TAMP_STAMP_IRQ		           		 ,          /* Tamper and TimeStamps through the E */
	RTC_WKUP_IRQ		           		 ,          /* RTC Wakeup through the EXTI line */
	FLASH_IRQ			                 ,          /* FLASH                        */
	RCC_IRQ			                     ,          /* RCC                          */
	EXTI0_IRQ			                 ,          /* EXTI Line0                   */
	EXTI1_IRQ	                         ,          /* EXTI Line1                   */
	EXTI2_IRQ		                     ,          /* EXTI Line2                   */
	EXTI3_IRQ			                 ,          /* EXTI Line3                   */
	EXTI4_IRQ			                 ,          /* EXTI Line4                   */
	DMA1_Stream0_IRQ	                 ,          /* DMA1 Stream 0                */
	DMA1_Stream1_IRQ	                 ,          /* DMA1 Stream 1                */
	DMA1_Stream2_IRQ	                 ,          /* DMA1 Stream 2                */
	DMA1_Stream3_IRQ                     ,          /* DMA1 Stream 3                */
	DMA1_Stream4_IRQ                     ,          /* DMA1 Stream 4                */
	DMA1_Stream5_IRQ                     ,          /* DMA1 Stream 5                */
	DMA1_Stream6_IRQ                     ,          /* DMA1 Stream 6                */
	ADC_IRQ			                     ,          /* ADC1, ADC2 and ADC3s         */
	CAN1_TX_IRQ		                     ,          /* CAN1 TX                      */
	CAN1_RX0_IRQ		                 ,          /* CAN1 RX0                     */
	CAN1_RX1_IRQ		                 ,          /* CAN1 RX1                     */
	CAN1_SCE_IRQ		                 ,          /* CAN1 SCE                     */
	EXTI9_5_IRQ		                     ,          /* External Line[9:5]s          */
	TIM1_BRK_TIM9_IRQ                    ,          /* TIM1 Break and TIM9          */
	TIM1_UP_TIM10_IRQ	                 ,          /* TIM1 Update and TIM10        */
	TIM1_TRG_COM_IRQ			         ,
	TIM1_CC_IRQ			  	             ,          /* TIM1 Capture Compare         */
	TIM2_IRQ				  	         ,          /* TIM2                         */
	TIM3_IRQ				  	         ,          /* TIM3                         */
	TIM4_IRQ		 	  	             ,          /* TIM4                         */
	I2C1_EV_IRQ                          ,          /* I2C1 Event                   */
	I2C1_ER_IRQ                          ,          /* I2C1 Error                   */
	I2C2_EV_IRQ                          ,          /* I2C2 Event                   */
	I2C2_ER_IRQ                          ,          /* I2C2 Error                   */
	SPI1_IRQ				             ,          /* SPI1                         */
	SPI2_IRQ				             ,          /* SPI2                         */
	USART1_IRQ				             ,          /* USART1                       */
	USART2_IRQ			                 ,          /* USART2                       */
	USART3_IRQ		         =  39		 ,          /* USART3                       */
	EXTI15_10_IRQ			             ,          /* External Line[15:10]s        */
	RTC_Alarm_IRQ			             ,          /* RTC Alarm (A and B) through EXTI Li */
	OTG_FS_WKUP_IRQ		                 ,          /* USB OTG FS Wakeup through EXTI line */
	TIM8_BRK_TIM12_IRQ		             ,          /* TIM8 Break and TIM12         */
	TIM8_UP_TIM13_IRQ		             ,          /* TIM8 Update and TIM13        */
	TIM8_TRG_COM_TIM14_IRQ	             ,          /* TIM8 Trigger and Commutation and TI */
	TIM8_CC_IRQ			                 ,          /* TIM8 Capture Compare         */
	DMA1_Stream7_IRQ		             ,          /* DMA1 Stream7                 */
	FSMC_IRQ				             ,          /* FSMC                         */
	SDIO_IRQ                             ,          /* SDIO                         */
	TIM5_IRQ                             ,          /* TIM5                         */
	SPI3_IRQ                             ,          /* SPI3                         */
	UART4_IRQ				  	         ,          /* UART4                        */
	UART5_IRQ				  	         ,          /* UART5                        */
	TIM6_DAC_IRQ			  	         ,          /* TIM6 and DAC1&2 underrun errors */
	TIM7_IRQ				  	         ,          /* TIM7                         */
	DMA2_Stream0_IRQ                     ,          /* DMA2 Stream 0                */
	DMA2_Stream1_IRQ                     ,          /* DMA2 Stream 1                */
	DMA2_Stream2_IRQ                     ,          /* DMA2 Stream 2                */
	DMA2_Stream3_IRQ                     ,          /* DMA2 Stream 3                */
	DMA2_Stream4_IRQ                     ,          /* DMA2 Stream 4                */
	ETH_IRQ                              ,          /* Ethernet                     */
	ETH_WKUP_IRQ                         ,          /* Ethernet Wakeup through EXTI line */
	CAN2_TX_IRQ                          ,          /* CAN2 TX                      */
	CAN2_RX0_IRQ                         ,          /* CAN2 RX0                     */
	CAN2_RX1_IRQ                         ,          /* CAN2 RX1                     */
	CAN2_SCE_IRQ                         ,          /* CAN2 SCE                     */
	OTG_FS_IRQ                           ,          /* USB OTG FS                   */

}IRQn_Type;


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/
void NVIC_EnableIRQ  		(IRQn_Type IRQn) ;
void NVIC_DisableIRQ 		(IRQn_Type IRQn) ;
void NVIC_SetPendingIRQ 	(IRQn_Type IRQn) ;
void NVIC_ClearPendingIRQ	(IRQn_Type IRQn) ;
uint32_t NVIC_GetActive		(IRQn_Type IRQn) ;
void NVIC_SetPriorityIRQ	(IRQn_Type IRQn , uint8_t Priority ) ;
uint8_t NVIC_GetPriorityIRQ	(IRQn_Type IRQn) ;
/***************Software Interfaces Definitions END   *****************/


#endif /* CORTEXM3_CORE_NVIC_H_ */
