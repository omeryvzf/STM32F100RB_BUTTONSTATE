#include "stm32f10x.h"                  // Device header
int16_t buttonState=0;
uint16_t flag=0;
void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	//LED 
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIOInitStructure);
	
	// BUTTON
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	
	GPIO_Init(GPIOC,&GPIOInitStructure);
	
	
}
void delay(uint32_t time){
	while(time--){
	}
}
int main(){
	gpioConfig();
	while(1){
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)!=0);
		if(buttonState==1){
			if(flag==0){
				flag=1;
				GPIO_SetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
			}
			else{
				flag=0;
				GPIO_ResetBits(GPIOB,GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2);
			}
			delay(7200000);
		}
	
	
	}


	
}
