#include "rlc.h"


volatile float F = 0,L = 0,x1,x2,x3,t,t0,T;
float RLC_measure(){
	GPIOB -> ODR|=(1<<0);
	TIM2->CR1 = 1; /* start counting up */
	while((TIM2->SR  & (1<<3)) == 0); /* wait until the CC3IF flag*/
	t0 = TIM2 -> CCR3;
	while((TIM2->SR  & (1<<3)) == 0); /* wait until the CC3IF flag*/
	t = TIM2 -> CCR3; /* read the captured value */
	GPIOB -> ODR&=~(1<<0);
	T = (t-t0)/(1000000);
	F = 1/T;
	x1 = (F*2*PI);
	x2 = pow(x1,2);
	x3 = x2*0.00001;
	//x = (float)(((f*2*PI)^2)*(0.00001));
	L = 1/x3;

	
return L;
}
