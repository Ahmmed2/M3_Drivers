/*
 * Cortex_M3_Core_USART.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed
 */


#ifndef USART_H
#define USART_H

/***************Include Start ***************/
#include "LIB/Std_Types.h"
/***************Include END *****************/

/***************Macros Definitions Start *****************/

/* Status Register bits */

#define 	PE			0
#define		FE			1
#define		NE			2
#define		ORE			3
#define		IDLE		4
#define		RXNE		5
#define		TC			6
#define		TXE			7
#define		LBD			8
#define		CTS			9


/* Control Register bits */

#define 	SBK 			0
#define 	RWU 			1
#define 	RE 				2
#define 	TE 				3
#define 	IDLEIE 			4
#define 	RXNEIE 			5
#define 	TCIE 			6
#define 	TXEIE 			7
#define 	PEIE 			8
#define 	PS	 			9
#define 	PCE 			10
#define 	WAKE 			11
#define 	M	 			12
#define 	UE	 			13



/* USART Modes */
#define USART_TXPOLLING						0
#define USART_TXINTERRUPT					1

#define USART_RXPOLLING						0
#define USART_RXINTERRUPT					1

#define USART_TXOPERATION_MODE        USART_TXPOLLING
#define USART_RXOPERATION_MODE        USART_RXINTERRUPT


/* Control Register Options */
#define USART_8_BIT_DATA					0
#define USART_9_BIT_DATA					1

#define USART_EVEN_PARITY					0
#define USART_ODD_PARITY					1

#define USART_PCE_DISABLED					0
#define USART_PCE_ENABLED					1

/* Baud Rates */
#define CPU_CLOCK 						  8000000
#define SAMPLES_NO							16
#define BAUD_4800						   0x683
#define BAUD_9600 						   0x341
#define BAUD_115200						   0x46

/* Options !> @ref Control Register Options */
#define USART_DATA_SIZE 			USART_8_BIT_WORD
#define USART_PE_CONFIG				USART_PCE_DISABLED
#define USART_PARITY_MODE			USART_EVEN_PARITY
#define USART_BAUD_RATE 			   BAUD_9600


/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

/* Register Definition */
typedef struct{
	volatile uint32_t SR;				// Status Register (All Flags)
	volatile uint32_t DR;				// Data Register
	volatile uint32_t BRR; 				// Baud Rate Register
	volatile uint32_t CR[3];			// Control Register
	volatile uint32_t GTPR;
}USART_Register;


#define 	USART1 		((USART_Register *) 0x40013800)



/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/

void MUSART1_voidInit(void);
void MUSART1_voidTransmit(uint8_t arr[]);
uint8_t MUSART1_u8Receive(void);
void USART1_voidSetCallBack(void (*ptr)(u8)) ;
/***************Software Interfaces Definitions END   *****************/


#endif
