// Led at PORT C, PIN 13

//base address
#define PERIPH_BASE 	0x40000000UL
#define PORTC_OFFSET 	0x00011000UL
#define PORTC_BASE 		PERIPH_BASE + PORTC_OFFSET

#define RCC_OFFSET 		0x00021000UL
#define RCC_BASE 		PERIPH_BASE + RCC_OFFSET

//Register to enable clock to PORTC
#define RCC_APB2ENR 	(*(volatile unsigned int *)(RCC_BASE + 0x18UL))
#define GPIOC_EN 		1U<<4

//Register to set PORTC as output/input
#define GPIOC_CRH_OFFSET 0x04UL
#define GPIOC_CRH		(*(volatile unsigned int *)(PORTC_BASE + GPIOC_CRH_OFFSET))

//Register of PORTC Output data
#define GPIOC_ODR_OFFSET 0X0CUL
#define GPIOC_ODR		(*(volatile unsigned int *)(PORTC_BASE + GPIOC_ODR_OFFSET))

//To turn on PIN 13 Of PORTC
#define GPIOC_PIN_13 	1U<<13

/* */


int main(){
	//Enabling clock to PORTC
	RCC_APB2ENR |= GPIOC_EN;  //Setting only required bit

	//Setting PIN13 to Output
	GPIOC_CRH |= (1U<<20);
	GPIOC_CRH &= ~(1U<<21);

	while(1)
	{
		GPIOC_ODR |= GPIOC_PIN_13;
	}
}
