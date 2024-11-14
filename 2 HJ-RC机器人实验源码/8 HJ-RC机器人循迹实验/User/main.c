// HJ-RC机器人 循迹实验实验 
//电机接线定义 左1--红黑 左2--黑红 右1--黑红  右2--红黑
//实验方式 调试好循迹传感器，下载程序，按下K1按健，放在地面开始实验

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "IRSEARCH.h"
/*
void HJduino_run(int speed,int time);       //前进函数
void HJduino_brake(int time);               //刹车函数
void HJduino_Left(int speed,int time);      //左转函数
void HJduin_Spin_Left(int speed,int time); //左旋转函数
void HJduino_Right(int speed,int time);     //右转函数
void HJduino_Spin_Right(int speed,int time);//右旋转函数
void HJduino_back(int speed,int time);      //后退函数

*/


 int main(void)
 {	
	 delay_init();
	 KEY_Init();
	 IRSearchInit();
	 TIM4_PWM_Init(7199,0);  //初始化PWM
	 HJduino_brake(500);
	 keysacn();		
		while(1)
		{  
		 SearchRun();
			//BEEP_RESET;//蜂鸣器发声音
			BEEP_SET;		//蜂鸣器停止
		}
 }

