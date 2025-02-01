#include "stm32f10x.h"
#include "Delay.h"

int main(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	while(1){
		GPIO_ResetBits(GPIOB, GPIO_Pin_13);
		Delay_ms(500);
		GPIO_SetBits(GPIOB, GPIO_Pin_13);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB, GPIO_Pin_13, Bit_SET);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)1);
		Delay_ms(500);
	}
}
