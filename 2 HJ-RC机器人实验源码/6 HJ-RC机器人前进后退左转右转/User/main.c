//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ��
//********************************************************************************
//////////////////////////////////////////////////////////////////////////////////  
// HJ-RC������ �Զ�����ʵ�� 
//������߶��� ��1--��� ��2--�ں� ��1--�ں�  ��2--���

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
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
	 TIM4_PWM_Init(7199,0);  //��ʼ��PWM
	 HJduino_brake(500);//ֹͣ0.5S
		while(1)
		{  

			 HJduino_run(70,3000);//ǰ��1S 
			 HJduino_brake(500);//ֹͣ0.5S			
			 HJduino_back(70,1000);//����1s
			 HJduino_brake(500);//ֹͣ0.5S
//			
       HJduino_Left(70,1000);//��ת1S
        HJduino_Right(70,1000);//��ת1S
////  	 
    		 HJduino_Spin_Right(70,1000);//������ת2S
 		    HJduino_Spin_Left(70,1000);//������ת2S
         HJduino_brake(5000);//ֹͣ0.5S 		
		}
 }

