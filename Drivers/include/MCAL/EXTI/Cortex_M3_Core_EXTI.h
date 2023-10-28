




#ifndef CORTEXM3_CORE_EXTI_H_
#define CORTEXM3_CORE_EXTI_H_

/***************Include Start ***************/

#include "LIB/Std_Types.h"
#include "MCAL/EXTI/Cortex_M3_Core_EXTI.h"

/***************Include END *****************/

/***************Macros Definitions Start *****************/



/***************Macros Definitions END   *****************/

/***************Macros Functions Definitions Start *****************/

/******************* Lines  *******************/

#define EXTI  ((volatile EXTI_t *)0x40010400)

#define LINE0    0
#define LINE1    1
#define LINE2    2
#define LINE3    3
#define LINE4    4
#define LINE5    5
#define LINE6    6
#define LINE7    7
#define LINE8    8
#define LINE9    9
#define LINE10   10
#define LINE11   11
#define LINE12   12
#define LINE13   13
#define LINE14   14
#define LINE15   15


/** @ Options
 * RISING
 * FALLING
 * ONCHANGE
 */
#define EXTI_MODE  FAILLING

#define EXTI_LINE  LINE0

/******************* Modes  *******************/

#define RISING    0
#define FALLING   1
#define ONCHANGE  2

/***************Macros Functions Definitions END   *****************/


/***************Data Type Definitions Start *****************/

typedef struct
{
	volatile uint32_t IMR   ;   // Interrupt Mask Register
	volatile uint32_t EMR   ;   // Event Mask Register
	volatile uint32_t RSTR  ;   // Rising Trigger Selection Register
	volatile uint32_t FTSR  ;   // Falling Trigger Selection Register
	volatile uint32_t SWIER ;   // Software Interrupt Event Register
	volatile uint32_t PR    ;


}EXTI_t;


/***************Data Type Definitions END   *****************/


/***************Software Interfaces Definitions Start *****************/
void MEXTI_voidInit();
void MEXTI_voidEnableEXTI(uint8_t Copy_u8EXTILine);
void MEXTI_voidDisableEXTI(uint8_t Copy_u8EXTILine);
void MEXTI_voidSWTrigger(uint8_t Copy_u8EXTILine);
void MEXTI_voidSetSignalLatch(uint8_t Copy_u8EXTILine , uint8_t Copy_u8EXTIMode);
void MEXTI0_voidSetCallBack(void (*ptr) (void));
void MEXTI1_voidSetCallBack(void (*ptr) (void));
/***************Software Interfaces Definitions END   *****************/


#endif
