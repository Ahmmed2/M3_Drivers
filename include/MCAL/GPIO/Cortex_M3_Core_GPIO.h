


#define GPIOA_Base_Address        0x40010800            // Base address of GPIO port A
#define GPIOB_Base_Address        0x40010C00            // Base address of GPIO port B
#define GPIOC_Base_Address        0x40011000            // Base address of GPIO port C

/*  Register Definitions for Port A (Base address + offset)  */

#define GPIOA_CRL         *((volatile uint32_t*)(GPIOA_Base_Address + 0x00))
#define GPIOA_CRH         *((volatile uint32_t*)(GPIOA_Base_Address + 0x04))
#define GPIOA_IDR         *((volatile uint32_t*)(GPIOA_Base_Address + 0x08))
#define GPIOA_ODR         *((volatile uint32_t*)(GPIOA_Base_Address + 0x0c))
#define GPIOA_BSRR        *((volatile uint32_t*)(GPIOA_Base_Address + 0x10))
#define GPIOA_BRR         *((volatile uint32_t*)(GPIOA_Base_Address + 0x14))
#define GPIOA_LCKR        *((volatile uint32_t*)(GPIOA_Base_Address + 0x18))


/*  Register Definitions for Port B (Base address + offset)  */

#define GPIOB_CRL         *((volatile uint32_t*)(GPIOB_Base_Address + 0x00))
#define GPIOB_CRH         *((volatile uint32_t*)(GPIOB_Base_Address + 0x04))
#define GPIOB_IDR         *((volatile uint32_t*)(GPIOB_Base_Address + 0x08))
#define GPIOB_ODR         *((volatile uint32_t*)(GPIOB_Base_Address + 0x0c))
#define GPIOB_BSRR        *((volatile uint32_t*)(GPIOB_Base_Address + 0x10))
#define GPIOB_BRR         *((volatile uint32_t*)(GPIOB_Base_Address + 0x14))
#define GPIOB_LCKR        *((volatile uint32_t*)(GPIOB_Base_Address + 0x18))


/*  Register Definitions for Port C (Base address + offset)  */

#define GPIOC_CRL         *((volatile uint32_t*)(GPIOC_Base_Address + 0x00))
#define GPIOC_CRH         *((volatile uint32_t*)(GPIOC_Base_Address + 0x04))
#define GPIOC_IDR         *((volatile uint32_t*)(GPIOC_Base_Address + 0x08))
#define GPIOC_ODR         *((volatile uint32_t*)(GPIOC_Base_Address + 0x0c))
#define GPIOC_BSRR        *((volatile uint32_t*)(GPIOC_Base_Address + 0x10))
#define GPIOC_BRR         *((volatile uint32_t*)(GPIOC_Base_Address + 0x14))
#define GPIOC_LCKR        *((volatile uint32_t*)(GPIOC_Base_Address + 0x18))

/*lock key bit*/
#define LCKK  16




#define HIGH   		 	1
#define LOW     		0

/* Port ID */
#define GPIOA   		0
#define GPIOB   		1
#define GPIOC   		2

/* Pin Id*/
#define PIN0    	 	0
#define PIN1     		1
#define PIN2     		2
#define PIN3     		3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7
#define PIN8            8
#define PIN9            9
#define PIN10           10
#define PIN11           11
#define PIN12           12
#define PIN13           13
#define PIN14           14
#define PIN15           15

/*Input mode with configuration*/
#define INPUT_ANALOG              0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

/*Output mode 10MHZ with configuration*/
#define OUTPUT_10MHZ_PP           0b0001     //push pull
#define OUTPUT_10MHZ_OD           0b0101     //open drain
#define OUTPUT_10MHZ_AFPP         0b1001     //Alternative function push pull
#define OUTPUT_10MHZ_AFOD         0b1101     //Alternative function open drain

/*Output mode 2MHZ with configuration*/
#define OUTPUT_2MHZ_PP            0b0010     //push pull
#define OUTPUT_2MHZ_OD            0b0110     //open drain
#define OUTPUT_2MHZ_AFPP          0b1010     //Alternative function push pull
#define OUTPUT_2MHZ_AFOD          0b1110     //Alternative function open drain

/*Output mode 50MHZ with configuration*/
#define OUTPUT_50MHZ_PP           0b0011     //push pull
#define OUTPUT_50MHZ_OD           0b0111     //open drain
#define OUTPUT_50MHZ_AFPP         0b1011     //Alternative function push pull
#define OUTPUT_50MHZ_AFOD         0b1111     //Alternative function open drain


/* Bit Masking */
#define CLEAR_VALUE 		0b1111
#define PIN_BITS_NO			  4
#define MAX_PIN_NO			  7
#define LSB_7PINS			  7
#define MSB_7PINS			  15

void MGPIO_VoidSetPinDirection(uint8_t Copy_u8Port , uint8_t Copy_u8Pin , uint8_t Copy_u8Mode);
void MGPIO_VoidSetPinValue(uint8_t Copy_u8Port , uint8_t Copy_u8Pin , uint8_t Copy_u8Value);
uint8_t MGPIO_u8GetPinValue(uint8_t Copy_u8Port , uint8_t Copy_u8Pin);
void MGPIO_VoidLockPin(uint8_t Copy_u8Port , uint8_t Copy_u8Pin);
