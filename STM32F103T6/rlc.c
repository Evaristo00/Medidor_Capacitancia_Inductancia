#include "rlc.h"


volatile float F = 0,L = 0,x1,x2,x3,t1,t0,T;

void RLC_init(){

	GPIOB->CRL = 0x44444443;
	GPIOA->CRL = 0x44444844; /* PA2 (TIM2 CH3): input pull-up */
	GPIOA->ODR |= (1<<2);

	TIM2->CCMR2 = 0x001; /* Pin TIM2_CH3 as input for channel 3 */
	TIM2->CCER = (0x1<< 8); /*CC3P = 0 (rising), CC3E = 1 */
	//TIM2->PSC = 7200-1;
	TIM2->ARR = 50000-1;
}
float RLC_measure(){
	GPIOB -> ODR|=(1<<0);
	TIM2->CR1 = 1; /* start counting up */
	while((TIM2->SR  & (1<<3)) == 0); /* wait until the CC3IF flag*/
	t0 = TIM2 -> CCR3;
	while((TIM2->SR  & (1<<3)) == 0); /* wait until the CC3IF flag*/
	t1 = TIM2 -> CCR3; /* read the captured value */
	GPIOB -> ODR&=~(1<<0);
	T = (t1-t0)/(8000000);
	F = 1/T;
	x1 = (F*2*PI);
	x2 = pow(x1,2);
	x3 = x2*0.00001;
	L = 1/x3;

	
return L;
}
