#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "usart.h"
#include "usart2.h"
#include "string.h"	 
/*
void HJduino_run(int speed,int time);       //前进函数
void HJduino_brake(int time);               //刹车函数
void HJduino_Left(int speed,int time);      //左转函数
void HJduino_Spin_Left(int speed,int time); //左旋转函数
void HJduino_Right(int speed,int time);     //右转函数
void HJduino_Spin_Right(int speed,int time);//右旋转函数
void HJduino_back(int speed,int time);      //后退函数

*/


 int main(void)
 {	
	 u8 reclen=0;
	 delay_init();
	 TIM4_PWM_Init(7199,0);  //初始化PWM
	 uart_init(9600);
	 USART2_Init(9600);	 
	 HJduino_brake(500);
	 while(1)
		{  		
		if(USART2_RX_STA&0X8000)	//接收到一次数据了
		{
			reclen=USART2_RX_STA&0X7FFF;	//得到数据长度
			USART2_RX_BUF[reclen]=0;	 	//加入结束符
			printf("USART2_RX_BUF:%s\n",USART2_RX_BUF);
  		printf("reclen:%d\n",reclen);
			if(reclen==3||reclen==4) 		//控制DS1检测
			{
				if(strcmp((const char*)USART2_RX_BUF,"ONA")==0)
				{
					u2_printf("go forward!"); 
          HJduino_run(80,100);
				}
				else if(strcmp((const char*)USART2_RX_BUF,"ONB")==0)
				{
					u2_printf("go back!"); 
          HJduino_back(80,100);
				}
				else if(strcmp((const char*)USART2_RX_BUF,"OND")==0)
				{
         u2_printf("go right!"); 
         HJduino_Right(80,100);
				}
			  else if(strcmp((const char*)USART2_RX_BUF,"ONC")==0)
				{
					u2_printf("go left!"); 
         HJduino_Left(80,100);
				}
			  else if(strcmp((const char*)USART2_RX_BUF,"ONF")==0)
				{
         u2_printf("Stop!"); 
         HJduino_brake(100);
				}
				else if(strcmp((const char*)USART2_RX_BUF,"ONE")==0)
				{
         u2_printf("Stop!"); 
         HJduino_brake(100);
				}
			}
			USART2_RX_STA=0;		
		}	
	}
 }

