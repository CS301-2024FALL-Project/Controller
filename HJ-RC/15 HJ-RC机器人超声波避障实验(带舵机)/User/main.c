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

// 超声波转头函数
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
   Timerx_Init(5000,7199);                //10Khz的计数频率，计数到5000为500ms 
	 UltrasonicWave_Configuration();        //对超声波模块初始化
	 uart_init(115200);
	 TIM4_PWM_Init(7199,0);                 //初始化PWM
	 TIM5_PWM_Init(9999,143);               //不分频，PWM频率=72*10^6/(9999+1)/(143+1)=50Hz	 
	 HJduino_brake(500);
	 keysacn();		
	while(1)
	{  		
	//	Q_temp = front_detection();
	//  printf("测到的距离值为：%d\n",Q_temp);
		Q_temp = front_detection();
		if(Q_temp<60 && Q_temp>0) //测量距离值	
		{
			HJduino_brake(500);		
			HJduino_back(60,500);	
			HJduino_brake(1000);	
			
			L_temp=left_detection();//测量左边障碍物的距离值
			delay_ms(500);
			R_temp=right_detection();//测量右边障碍物的距离值
			delay_ms(500);
			
			if((L_temp < 60 ) &&( R_temp < 60 ))//当左右两侧均有障碍物靠的比较近
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



//     char buffer[50]; // 用于存储要发送的数据

//    // 构造距离信息 "D <distance>"
//    snprintf(buffer, sizeof(buffer), "D %.2f\n", distance);
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, strlen(buffer));

//    HAL_Delay(50); // 等待上一次发送完成

//    // 构造障碍物信息 "B <block>"
//    snprintf(buffer, sizeof(buffer), "B %d\n", block);
//    HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, strlen(buffer));
 
 

//#include "stm32f10x.h"
//#include "delay.h"
//#include "motor.h"
//#include "usart.h"
//#include "usart2.h"
//#include "string.h"	 
///*
//void HJduino_run(int speed,int time);       //前进函数
//void HJduino_brake(int time);               //刹车函数
//void HJduino_Left(int speed,int time);      //左转函数
//void HJduino_Spin_Left(int speed,int time); //左旋转函数
//void HJduino_Right(int speed,int time);     //右转函数
//void HJduino_Spin_Right(int speed,int time);//右旋转函数
//void HJduino_back(int speed,int time);      //后退函数

//*/


// int main(void)
// {	
//	 u8 reclen=0;
//	 delay_init();
//	 TIM4_PWM_Init(7199,0);  //初始化PWM
//	 uart_init(9600);
//	 USART2_Init(9600);	 
//	 HJduino_brake(500);
//	 while(1)
//		{  		
//		if(USART2_RX_STA&0X8000)	//接收到一次数据了
//		{
//			reclen=USART2_RX_STA&0X7FFF;	//得到数据长度
//			USART2_RX_BUF[reclen]=0;	 	//加入结束符
//			printf("USART2_RX_BUF:%s\n",USART2_RX_BUF);
//  		printf("reclen:%d\n",reclen);
//			if(reclen==3||reclen==4) 		//控制DS1检测
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

