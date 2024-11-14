
#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用							  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PB0和PD2为输出口.并使能这两个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PD端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //L1-->PB.0 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.0
 //GPIO_SetBits(GPIOB,GPIO_Pin_0);						 //PB.0 输出高
GPIO_ResetBits(GPIOB,GPIO_Pin_0);						 //PB.0 输出低

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //L2-->PD.2 端口配置, 推挽输出
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PD.2 输出高 
}
 
