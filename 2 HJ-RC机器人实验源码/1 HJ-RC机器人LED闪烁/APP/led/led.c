
#include "led.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ��							  
////////////////////////////////////////////////////////////////////////////////// 	   

//��ʼ��PB0��PD2Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PB,PD�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;				 //L1-->PB.0 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.0
 //GPIO_SetBits(GPIOB,GPIO_Pin_0);						 //PB.0 �����
GPIO_ResetBits(GPIOB,GPIO_Pin_0);						 //PB.0 �����

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //L2-->PD.2 �˿�����, �������
 GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
 GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PD.2 ����� 
}
 
