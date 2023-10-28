/*
 * Cortex_M3_Core_SPI.c
 *
 *  Created on: Oct 26, 2023
 *      Author: Ahmed
 *
 *       Note : SPI1 only "PORTA"
 */

#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
#include "MCAL/SPI/Cortex_M3_Core_SPI.h"
#include "MCAL/GPIO/Cortex_M3_Core_GPIO.h"

/* Pointer To function for USART handler */
void (*SPI_PTRHandler)(u8) ;


/**
 * Brief : SPI Initialize
 *
 * Parameters[in] :
 *
 *Return :
 *
 * note : Node type is configured within .h file
 *
 */

void MSPI1_voidInit(void)
{
	uint16_t Copy_u16InitValue = 0x0000 ;

	/* 8-bit Data Format */
	Clear_bit(Copy_u16InitValue,DFF) ;

	/* MSB Tx First */
	Clear_bit(Copy_u16InitValue,LSBFIRST) ;

	/* Enable SPI */
	Set_bit(Copy_u16InitValue,SPE) ;


	/* Node Selection */

#if   SPI_NODE == SPI_MASTER

	/* Select Master */
	Set_bit(Copy_u16InitValue,MSTR) ;

	/* Baud Rate Control */
	Clear_bit(Copy_u16InitValue,BR_5) ;
	Clear_bit(Copy_u16InitValue,BR_4) ;
	Clear_bit(Copy_u16InitValue,BR_3) ;

	/* Software Slave Managmement Enable */
	Set_bit(Copy_u16InitValue,SSM) ;

	/* Internal Slave Select */
	Set_bit(Copy_u16InitValue,SSI) ;

#elif SPI_NODE == SPI_SLAVE

	/* Select Slave */
	Clear_bit(Copy_u16InitValue,MSTR) ;

	/* Software Slave Managmement Enable */
	Set_bit(Copy_u16InitValue,SSM) ;

	/* Internal Slave Select */
	Clear_bit(Copy_u16InitValue,SSI) ;

#endif



#if SPI_TXMODE == SPI_TXINTERRUPT

	/* Enable TXEIE "Tx buffer empty interrupt enable" */
	Set_bit(SPI1->CR2, TXEIE) ;

#elif SPI_RXMODE == SPI_RXINTERRUPT

	/* Enable RXNEIE "RX buffer not empty interrupt enable" */
	Set_bit(SPI1->CR2, RXNEIE) ;

#endif


	/* Clock Polarity "Idle HIGH " */
	Set_bit(Copy_u16InitValue,CPOL) ;

	/* Clock Phase "Write First then Read " */
	Set_bit(Copy_u16InitValue,CPHA) ;

	SPI1->CR1 = Copy_u16InitValue ;

}

/**
 * Brief : SPI Send  data
 *
 * Parameters[in] :
 *
 *Return :
 *
 * note : it is applicable to choose one of the Tx or Rx interrupt not both .
 *
 */


void MSPI1_voidSend(uint8_t Copy_u8DataToTransmit)
{


#if SPI_TXMODE == SPI_TXPOLLING

	/* Check if the tx Buffer Empty */
	while (Get_bit(SPI1 -> SR, 1) == 0);
	/* Send Data */
	SPI1->DR = Copy_u8DataToTransmit ;
	/* Wait Busy Flag to finish */
	while (Get_bit(SPI1 -> SR, BSY) == 1);


#endif

}


/**
 * Brief : SPI Receive data
 *
 * Parameters[in] :
 *
 *Return :
 *
 * note : it is applicable to choose one of the Tx or Rx interrupt not both .
 *
 */

void MSPI1_voidReceive(uint8_t *Copy_DataToReceive)
{


#if SPI_RXMODE == SPI_RXPOLLING

	while (Get_bit(SPI1 -> SR, RXNE) == 0) ;

	/* Return received data */
	*Copy_DataToReceive = SPI1 -> DR;

	/* Wait Busy Flag to finish */
	while (Get_bit(SPI1 -> SR, BSY) == 1);


#elif SPI_RXMODE == SPI_RXINTERRUPT

	/*  Return to the received data */
	*Copy_DataToReceive = SPI1 -> DR;

#endif



}


/******************************** ISR ************************************/

void MSPI1_voidSetCallBack(void (*ptr)(u8))
{
	SPI_PTRHandler = ptr ;
}


void SPI1_IRQHandler(void)
{
	/* Calling SPI1Handler in main */
	SPI_PTRHandler(SPI1 -> DR) ;
	/* Temporary Variable */
	volatile uint8_t Copy_u8DataRx ;
	Copy_u8DataRx ++ ;
	/* Read Data Register To Reset RXNEIE Flag */
	Copy_u8DataRx = SPI1 -> DR ;

}
