// HJ-RC������ ��������С��ʵ�� 
//������߶��� ��1--��� ��2--�ں� ��1--�ں�  ��2--���
//ʵ�ֹ�����ʾ ����K1 С��������FMͬʱ�ᷢ������

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
/*
void HJduino_run(int speed,int time);       //ǰ������
void HJduino_brake(int time);               //ɲ������
void HJduino_Left(int speed,int time);      //��ת����
void HJduino_Spin_Left(int speed,int time); //����ת����
void HJduino_Right(int speed,int time);     //��ת����
void HJduino_Spin_Right(int speed,int time);//����ת����
void HJduino_back(int speed,int time);      //���˺���

*/


 int main(void)
 {	
	 delay_init();
	 KEY_Init();
	 TIM4_PWM_Init(7199,0);  //��ʼ��PWM
	 HJduino_brake(500);
		while(1)
		{  
		 HJduino_brake(500);
		 keysacn();			
		 HJduino_back(70,1000);//����1s
		 HJduino_brake(500);//ֹͣ0.5S
     HJduino_run(70,1000);//ǰ��1S
		 HJduino_brake(500);//ֹͣ0.5S
     HJduino_Left(70,1000);//��ת1S
     HJduino_Right(70,1000);//��ת1S
  	 HJduino_Spin_Right(70,1000);//������ת2S
     HJduino_Spin_Left(70,1000);//������ת2S
     HJduino_brake(500);//ֹͣ0.5S 	
		}
 }


