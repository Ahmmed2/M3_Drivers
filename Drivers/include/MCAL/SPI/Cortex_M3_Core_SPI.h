/*
 * Cortex_M3_Core_SPI.h
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed
 *
 *      Note : SPI1 only "PORTA"
 */

#ifndef SPI_H
#define SPI_H

/***************Include Start ***************/

#include "LIB/Std_Types.h"
#include "LIB/Macros.h"


/***************Include END *****************/


/***************Macros Definitions Start *****************/

#define SPI1_BASE_ADDRESS 					0x40013000
#define SPI1  						(( SPI_Register*)SPI1_BASE_ADDRESS)


/* CR1 Bits */

#define  DFF				11
#define	 SSM				 9
#define	 SSI				 8
#define	LSBFIRST			 7
#define  SPE				 6
#define	 BR_5				 5
#define  BR_4				 4
#define	 BR_3				 3
#define	 MSTR				 2
#define	 CPOL				 1
#define  CPHA				 0

/* SPI Nodes */

#define SPI_SLAVE			 0
#define SPI_MASTER			 1
#define SPI_NODE			SPI_SLAVE


/* SPI MODES */

#define SPI_TXPOLLING			0
#define SPI_TXINTERRUPT			1
#define SPI_RXPOLLING 			2
#define SPI_RXINTERRUPT 		3
#define SPI_TXMODE				SPI_TXPOLLING
#define SPI_RXMODE				SPI_RXINTERRUPT


/* CR2 Bits */

#define TXEIE					7
#define RXNEIE					6

/* SR Bits */

#define RXNE					0
#define TXE						1
#define BSY						7



/* Baud rate control */

#define CLK_2					0
#define CLK_4					1
#define CLK_8					2
#define CLK_16					3
#define CLK_32					4
#define CLK_64					5
#define CLK_128					6
#define CLK_256					7

#define CLK_SELECT 			  CLK_2
/* SPI1 Port,Pin */

#define SPI1_SLAVE_PIN   GPIOA,0

/***************Macros Definitions END   *****************/


/***************Macros Functions Definitions Start *****************/


/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

typedef struct
{
	volatile uint32_t CR1    ;
	volatile uint32_t CR2    ;
	volatile uint32_t SR     ;
	volatile uint32_t DR     ;
	volatile uint32_t CRCPR  ;
	volatile uint32_t RXCRCR ;
	volatile uint32_t TXCRCR ;
	volatile uint32_t I2SCFGR;
	volatile uint32_t I2SPR  ;

}SPI_Register;


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/

void MSPI1_voidInit(void);
void MSPI1_voidSendByte(uint8_t Copy_u8DataToTransmit);
void MSPI1_voidReceiveByte(uint8_t *Copy_DataToReceive);
void MSPI1_voidSendString(uint8_t *Copy_u8DataToTransmit);
void MSPI1_voidSetCallBack(void (*ptr)(u8)) ;

/***************Software Interfaces Definitions END   *****************/


#endif

