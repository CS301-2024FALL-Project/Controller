//L1 L2闪烁实验 驱动PB0 PD2 引脚
//HJ-RC实验板 HJ-RC机器人双闪灯编程实验代码
//下载程序，实验板L1 L2 同时闪动
#include "stm32f10x.h"
 void Delay(u32 count)
 {
  u32 i=0;
  for(;i<count;i++);

 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PD端口时钟
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				       //L2 PD2端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //IO口速度为50MHz
  GPIO_Init(GPIOD, &GPIO_InitStructure);					      //根据设定参数初始化GPIOD3
  GPIO_SetBits(GPIOD,GPIO_Pin_2);						            //PD2 输出高

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	    		 //LED1-->PB.0 端口配置, 推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
  GPIO_SetBits(GPIOB,GPIO_Pin_0); 						       //PB0 输出高 	关灯	  
  while(1)
	{
	  GPIO_SetBits(GPIOB,GPIO_Pin_0);  //关L1
		GPIO_SetBits(GPIOD,GPIO_Pin_2);  //关L2
		Delay(3000000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0); //开L1
		GPIO_ResetBits(GPIOD,GPIO_Pin_2); //开L2
		Delay(3000000);
	}
 }

