/*
 * Cortex_M3_Core_USART.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Ahmed
 */


/*********** Includes Start ***********/

#include "LIB/Std_Types.h"
#include "LIB/Macros.h"
#include "MCAL/USART/Cortex_M3_Core_USART.h"


/*********** Includes END   ***********/

/*********** Global Start   ***********/

/* Pointer To function for USART handler */
void (*USAR_PTRHandler)(u8) ;

/*********** Global END     ***********/



/**
 * Brief : UART Initialize
 *
 * Parameters[in] :
 *
 *Return :
 *
 * note :
 *
 */

void MUSART1_voidInit(void)
{
#if USART_TXOPERATION_MODE == USART_TXPOLLING

	/*	Baud rate = 9600  */
	USART1 -> BRR = USART_BAUD_RATE  ;
	/* Enabling Tx */
	Set_bit((USART1-> CR[0]), TE );
	/* Enabling Rx */
	Set_bit((USART1-> CR[0]), RE );
	/* Enabling USART */
	Set_bit((USART1-> CR[0]), UE );
	/* Clearing Status Register */
	USART1 -> SR = 0;

#elif USART_TXOPERATION_MODE == USART_TXINTERRUPT
	/*	Baud rate = 9600  */
	USART1 -> BRR = USART_BAUD_RATE  ;
	/* Enabling Tx */
	Set_bit((USART1-> CR[0]), TE );
	/* Enabling Rx */
	Set_bit((USART1-> CR[0]), RE );
	/* Enabling USART */
	Set_bit((USART1-> CR[0]), UE );
	/* Clearing Status Register */
	USART1 -> SR = 0;
	/* Enabling Transmission complete interrupt  */
	Set_bit((USART1-> CR[0]), TCIE );
#endif

#if USART_RXOPERATION_MODE == USART_RXPOLLING
	/*	Baud rate = 9600  */
	USART1 -> BRR = USART_BAUD_RATE  ;
	/* Enabling Tx */
	Set_bit((USART1-> CR[0]), TE );
	/* Enabling Rx */
	Set_bit((USART1-> CR[0]), RE );
	/* Enabling USART */
	Set_bit((USART1-> CR[0]), UE );
	/* Clearing Status Register */
	USART1 -> SR = 0;

#elif USART_RXOPERATION_MODE == USART_RXINTERRUPT
	/*	Baud rate = 9600  */
	USART1 -> BRR = USART_BAUD_RATE  ;
	/* Enabling Tx */
	Set_bit((USART1-> CR[0]), TE );
	/* Enabling Rx */
	Set_bit((USART1-> CR[0]), RE );
	/* Enabling USART */
	Set_bit((USART1-> CR[0]), UE );
	/* Clearing Status Register */
	USART1 -> SR = 0;

	/* RXNE interrupt enable  */
	Set_bit((USART1-> CR[0]), RXNEIE );

#endif
}


/**
 * Brief : Transmit String
 *
 * Parameters[in] : Array which have data as a string
 *
 *Return :
 *
 *
 * note
 *
 */

void MUSART1_voidTransmit(uint8_t USART_DATA[])
{
	uint8_t Local_IndexCounter = 0;

#if USART_TXOPERATION_MODE == USART_TXPOLLING

	while(USART_DATA[Local_IndexCounter] != '\0')
	{
		/* Transmit data register Empty */
		while((Get_bit((USART1 -> SR), TXE)) == 0);
		USART1 -> DR = USART_DATA[Local_IndexCounter];
		/* Transmission complete */
		//while((Get_bit((USART1 -> SR), TC)) == 0);
		Local_IndexCounter++;

	}

#elif USART_TXOPERATION_MODE == USART_TXPINTERRUPT
	while(USART_DATA[Local_IndexCounter] != '\0')
	{

		USART1 -> DR = USART_DATA[Local_IndexCounter];
		Local_IndexCounter++;

	}
#endif
}


/**
 * Brief : Receiving  Data.
 *
 * Parameters[in] :
 *
 *Return : Received Data.
 *
 *
 * note
 *
 */

uint8_t MUSART1_u8Receive(void)
{
#if USART_OPERATION_MODE == USART_POLLING
	uint8_t Loc_u8ReceivedData = 0;
	while((Get_bit((USART1 -> SR), RXNE)) == 0);
	Loc_u8ReceivedData = USART1 -> DR;
	return (Loc_u8ReceivedData);

#elif USART_OPERATION_MODE == USART_INTERRUPT
	return 0 ;

#endif

}

void USART1_voidSetCallBack(void (*ptr)(u8))
{
	USAR_PTRHandler = ptr ;
}


void USART1_IRQHandler(void)
{

	/* Calling USART1Handler in main */
	USAR_PTRHandler(USART1 -> DR ) ;

	/* Temporary Variable */
	volatile uint8_t Copy_u8DataRx ;
	Copy_u8DataRx ++ ;
	/* Read Data Register To Reset RXNEIE Flag */
	Copy_u8DataRx = USART1 -> DR ;


}


