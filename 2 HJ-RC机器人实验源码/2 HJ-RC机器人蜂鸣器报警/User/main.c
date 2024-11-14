//HJ-ZE FM发声音实验 驱动PA8 引脚
//HJ-RC实验板 HJ-RC机器人蜂鸣器发声音代码
#include "stm32f10x.h"
 void Delay(u32 count)
 {
  u32 i=0;
  for(;i<count;i++);

 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PA端口时钟
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				       //FM-->PA.8 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //IO口速度为50MHz
  GPIO_Init(GPIOA, &GPIO_InitStructure);					      //根据设定参数初始化GPIOA.8
  GPIO_SetBits(GPIOA,GPIO_Pin_8);						            //PA.8 输出高 关声音
  
  while(1)
	{
	  GPIO_ResetBits(GPIOA,GPIO_Pin_8); //打开声音
		Delay(3000000);
		GPIO_SetBits(GPIOA,GPIO_Pin_8); //关声音
		Delay(3000000);
	}
 }

