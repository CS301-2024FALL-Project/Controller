// HJ-RC������ ѭ��ʵ��ʵ�� 
//������߶��� ��1--��� ��2--�ں� ��1--�ں�  ��2--���
//ʵ�鷽ʽ ���Ժ�ѭ�������������س��򣬰���K1���������ڵ��濪ʼʵ��

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "IRSEARCH.h"
/*
void HJduino_run(int speed,int time);       //ǰ������
void HJduino_brake(int time);               //ɲ������
void HJduino_Left(int speed,int time);      //��ת����
void HJduin_Spin_Left(int speed,int time); //����ת����
void HJduino_Right(int speed,int time);     //��ת����
void HJduino_Spin_Right(int speed,int time);//����ת����
void HJduino_back(int speed,int time);      //���˺���

*/


 int main(void)
 {	
	 delay_init();
	 KEY_Init();
	 IRSearchInit();
	 TIM4_PWM_Init(7199,0);  //��ʼ��PWM
	 HJduino_brake(500);
	 keysacn();		
		while(1)
		{  
		 SearchRun();
			//BEEP_RESET;//������������
			BEEP_SET;		//������ֹͣ
		}
 }

