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

// ������תͷ����
int front_detection()
{

//HJduino_brake(0);
	SetJointAngle(90);
	delay_ms(100);
	return UltrasonicWave_StartMeasure();
}
int left_detection()
{

//	HJduino_brake(0);
	SetJointAngle(175);
	delay_ms(300);
	return UltrasonicWave_StartMeasure();
}
int right_detection()
{

//	HJduino_brake(0);
	SetJointAngle(5);
	delay_ms(300);
	return UltrasonicWave_StartMeasure();
}
 int main(void)
 {	
   int Q_temp,L_temp,R_temp;
	 delay_init();
	 KEY_Init();
	 IRSearchInit();
	 IRAvoidInit();
   Timerx_Init(5000,7199);                //10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms 
	 UltrasonicWave_Configuration();        //�Գ�����ģ���ʼ��
	 uart_init(115200);
	 TIM4_PWM_Init(7199,0);                 //��ʼ��PWM
	 TIM5_PWM_Init(9999,143);               //����Ƶ��PWMƵ��=72*10^6/(9999+1)/(143+1)=50Hz	 
	 HJduino_brake(500);
	 keysacn();		
	while(1)
	{  		
	//	Q_temp = front_detection();
	//  printf("�⵽�ľ���ֵΪ��%d\n",Q_temp);
		Q_temp = front_detection();
		if(Q_temp<60 && Q_temp>0) //��������ֵ	
		{
			HJduino_brake(500);		
			HJduino_back(60,500);	
			HJduino_brake(1000);	
			
			L_temp=left_detection();//��������ϰ���ľ���ֵ
			delay_ms(500);
			R_temp=right_detection();//�����ұ��ϰ���ľ���ֵ
			delay_ms(500);
			
			if((L_temp < 60 ) &&( R_temp < 60 ))//��������������ϰ��￿�ıȽϽ�
			{
				HJduino_Spin_Left(60,1000);
			}				
      else if(L_temp > R_temp)
			{
				HJduino_Left(60,1000);
				HJduino_brake(500);
			}	
      else
			{
				HJduino_Right(60,1000);
				HJduino_brake(500);					
			}							
		}	
		else
		{
			HJduino_run(60,10);
		}
	}
 }



//     char buffer[50]; // ���ڴ洢Ҫ���͵�����

//    // ���������Ϣ "D <distance>"
//    snprintf(buffer, sizeof(buffer), "D %.2f\n", distance);
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, strlen(buffer));

//    HAL_Delay(50); // �ȴ���һ�η������

//    // �����ϰ�����Ϣ "B <block>"
//    snprintf(buffer, sizeof(buffer), "B %d\n", block);
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, strlen(buffer));
 
 

//#include "stm32f10x.h"
//#include "delay.h"
//#include "motor.h"
//#include "usart.h"
//#include "usart2.h"
//#include "string.h"	 
///*
//void HJduino_run(int speed,int time);       //ǰ������
//void HJduino_brake(int time);               //ɲ������
//void HJduino_Left(int speed,int time);      //��ת����
//void HJduino_Spin_Left(int speed,int time); //����ת����
//void HJduino_Right(int speed,int time);     //��ת����
//void HJduino_Spin_Right(int speed,int time);//����ת����
//void HJduino_back(int speed,int time);      //���˺���

//*/


// int main(void)
// {	
//	 u8 reclen=0;
//	 delay_init();
//	 TIM4_PWM_Init(7199,0);  //��ʼ��PWM
//	 uart_init(9600);
//	 USART2_Init(9600);	 
//	 HJduino_brake(500);
//	 while(1)
//		{  		
//		if(USART2_RX_STA&0X8000)	//���յ�һ��������
//		{
//			reclen=USART2_RX_STA&0X7FFF;	//�õ����ݳ���
//			USART2_RX_BUF[reclen]=0;	 	//���������
//			printf("USART2_RX_BUF:%s\n",USART2_RX_BUF);
//  		printf("reclen:%d\n",reclen);
//			if(reclen==3||reclen==4) 		//����DS1���
//			{
//				if(strcmp((const char*)USART2_RX_BUF,"ONA")==0)
//				{
//					u2_printf("go forward!"); 
//          HJduino_run(80,100);
//				}
//				else if(strcmp((const char*)USART2_RX_BUF,"ONB")==0)
//				{
//					u2_printf("go back!"); 
//          HJduino_back(80,100);
//				}
//				else if(strcmp((const char*)USART2_RX_BUF,"OND")==0)
//				{
//         u2_printf("go right!"); 
//         HJduino_Right(80,100);
//				}
//			  else if(strcmp((const char*)USART2_RX_BUF,"ONC")==0)
//				{
//					u2_printf("go left!"); 
//         HJduino_Left(80,100);
//				}
//			  else if(strcmp((const char*)USART2_RX_BUF,"ONF")==0)
//				{
//         u2_printf("Stop!"); 
//         HJduino_brake(100);
//				}
//				else if(strcmp((const char*)USART2_RX_BUF,"ONE")==0)
//				{
//         u2_printf("Stop!"); 
//         HJduino_brake(100);
//				}
//			}
//			USART2_RX_STA=0;		
//		}	
//	}
// }

