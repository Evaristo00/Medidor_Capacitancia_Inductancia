/* Main.c file generated by New Project wizard
 *
 * Created:   Tue Nov 9 2021
 * Processor: STM32F103T6
 * Compiler:  Keil for ARM
 */

#include <stm32f103x6.h>
#include <stdio.h>
void usart1_init(void);
void usart1_sendByte(unsigned char c);
void usart1_sendInt(unsigned int i);
void usart1_sendStr(char *str);

int main (void)
{ 
	/*
   RCC->APB2ENR |= 0xFC | (1<<9); // enable clocks for GPIO and ADC1
   GPIOA->CRL = 0x44444004; //PA1 and PA2 as analog input
   ADC1->CR2 = 1 //ADON = 1 (power-up)
	*/
	uint16_t t, t0;
	RCC->APB2ENR |= (0xFC| (1<<14)); /* enable GPIO clocks and USART1 clock */
	RCC->APB1ENR |= (1<<0); /* enable TIM2 clock */
	GPIOA->CRL = 0x44444844; /* PA2 (TIM2 CH3): input pull-up */
	GPIOA->ODR |= (1<<2);
	TIM2->CCMR2 = 0x001; /* Pin TIM2_CH3 as input for channel 3 */
	TIM2->CCER = (1<< 8); /*CC3P = 0 (rising), CC3E = 1 */
	TIM2->PSC = 7200-1;
	TIM2->ARR = 50000-1;
	TIM2->CR1 = 1; /* start counting up */
	usart1_init( );
	t = 0, t0 = 0;
while(1) {
	while((TIM2->SR &(1<<3)) == 0); /* wait until the CC3IF flag
	sets */
	t = TIM2->CCR3; /* read the captured value */
	usart1_sendInt(t - t0); /* send the difference */
	usart1_sendStr("\n\r"); /* go to new line */
	t0 = t;
	}
   return 0;
}   

void usart1_init( ) {
	GPIOA->ODR |= (1<<10); //pull-up PA10
	GPIOA->CRH = 0x444448B4; // RX1=input with pull-up, TX1=alt. func output
	USART1->CR1 = 0x200C;
	USART1->BRR = 7500; // 72MHz/9600bps = 7500
}
void usart1_sendByte(unsigned char c) {
	while((USART1->SR&(1<<6)) == 0); //wait until the TC flag is set
	USART1->DR = c;
}

void usart1_sendStr(char *str) {
	while(*str != 0) {
	usart1_sendByte(*str);
	str++;
	}
}
/* The function sends a number through USART1 */
void usart1_sendInt(unsigned int i) {
	char str[10];
	sprintf(str,"%d",i);
	usart1_sendStr(str);
}
