

#ifndef CORTEXM3_CORE_AFIO_H_
#define CORTEXM3_CORE_AFIO_H_



/***************Include Start ***************/

#include "LIB/Std_Types.h"

/***************Include END *****************/

/***************Macros Definitions Start *****************/

#define MAFIO  				((volatile AFIO_t *)0x40010000)
#define LINE_BITS_NO  					4
#define BIT_MASKING					0b1111

#define LINE0_LAST_BIT_POSTION		3
#define LINE1_LAST_BIT_POSTION		7
#define LINE2_LAST_BIT_POSTION		11
#define LINE3_LAST_BIT_POSTION		15

#define AFIOA   0b0000
#define AFIOB   0b0001
#define AFIOC   0b0010


/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	volatile uint32_t MAPR2;


}AFIO_t;


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/
void MAFIO_voidSetEXTIConfig ( uint8_t Copy_u8EXTLine , uint8_t Copy_u8PortMap ) ;
/***************Software Interfaces Definitions END   *****************/



#endif
