//L1 L2��˸ʵ�� ����PB0 PD2 ����
//HJ-RCʵ��� HJ-RC������˫���Ʊ��ʵ�����
//���س���ʵ���L1 L2 ͬʱ����
#include "stm32f10x.h"
 void Delay(u32 count)
 {
  u32 i=0;
  for(;i<count;i++);

 }
 int main(void)
 {	
  GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOD, ENABLE);	 //ʹ��PB,PD�˿�ʱ��
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				       //L2 PD2�˿�����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		  //�������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		  //IO���ٶ�Ϊ50MHz
  GPIO_Init(GPIOD, &GPIO_InitStructure);					      //�����趨������ʼ��GPIOD3
  GPIO_SetBits(GPIOD,GPIO_Pin_2);						            //PD2 �����

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	    		 //LED1-->PB.0 �˿�����, �������
  GPIO_Init(GPIOB, &GPIO_InitStructure);	  				 //������� ��IO���ٶ�Ϊ50MHz
  GPIO_SetBits(GPIOB,GPIO_Pin_0); 						       //PB0 ����� 	�ص�	  
  while(1)
	{
	  GPIO_SetBits(GPIOB,GPIO_Pin_0);  //��L1
		GPIO_SetBits(GPIOD,GPIO_Pin_2);  //��L2
		Delay(3000000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0); //��L1
		GPIO_ResetBits(GPIOD,GPIO_Pin_2); //��L2
		Delay(3000000);
	}
 }

