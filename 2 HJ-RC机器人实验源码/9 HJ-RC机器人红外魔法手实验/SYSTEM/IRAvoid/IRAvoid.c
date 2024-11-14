#include "IRAvoid.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "stm32f10x.h"                  // Device header

int SR_2;    //�ұߺ�����ϴ�����״̬
int SL_2;    //��ߺ�����ϴ�����״̬
void IRAvoidInit(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA , ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = AVOID_RIGHT_PIN;//����ʹ��GPIO�ܽ� PB4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(AVOID_RIGHT_PIN_GPIO , &GPIO_InitStructure); 
	
  GPIO_InitStructure.GPIO_Pin = AVOID_LEFT_PIN;//����ʹ��GPIO�ܽ� PB5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//����GPIOģʽ,��������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//����GPIO�˿��ٶ�
	GPIO_Init(AVOID_LEFT_PIN_GPIO , &GPIO_InitStructure); 
}


void AVoidRun(void)
{
	SR_2 = AVOID_RIGHT_IO;
	SL_2 = AVOID_LEFT_IO;
	if(SL_2 == 1 && SR_2 == 1)
	{
		 HJduino_run(60,10); //ǰ��
		 BEEP_SET;
     LED_D3_RESET;	//�͵�ƽ ����L1 
     LED_D4_SET;		//�ߵ�ƽ ��L2
	}
	else
	{
		 BEEP_RESET;  //FM������
     LED_D3_SET;	
		 LED_D4_RESET;	//�͵�ƽ ����L2
		 HJduino_back(60,10);//����
			
				
	}
	
}
