#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "IRSEARCH.h"
#include "IRAvoid.h"
#include "usart.h"
#include "UltrasonicWave.h"
#include "timer.h"
#include "Server.h"

 int main(void)
 {	
	 
   int Q_temp,L_temp,R_temp;
	 delay_init();
	// KEY_Init();
	 ///IRSearchInit();
	 //IRAvoidInit();
   Timerx_Init(5000,7199);                //10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms 
	 //UltrasonicWave_Configuration();        //�Գ�����ģ���ʼ��
	 //uart_init(115200);
	 TIM4_PWM_Init(7199,0);                 //��ʼ��PWM
	 TIM5_PWM_Init(9999,143);               //����Ƶ��PWMƵ��=72*10^6/(9999+1)/(143+1)=50Hz	 
	 //keysacn();		
	while(1)
	{ 
	HJduino_brake(500);	 //ֹͣС��
		
	SetJointAngle(5); //0
	delay_ms(300);
		
		SetJointAngle(90); //����м�λ�� 85-95 
	delay_ms(100);	
		
			SetJointAngle(175); //�������λ�� 180
	delay_ms(300);

	}
 }
