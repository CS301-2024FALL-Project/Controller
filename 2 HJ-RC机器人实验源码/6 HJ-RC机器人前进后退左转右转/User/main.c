//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用
//********************************************************************************
//////////////////////////////////////////////////////////////////////////////////  
// HJ-RC机器人 自动行走实验 
//电机接线定义 左1--红黑 左2--黑红 右1--黑红  右2--红黑

#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
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
	 delay_init();
	 TIM4_PWM_Init(7199,0);  //初始化PWM
	 HJduino_brake(500);//停止0.5S
		while(1)
		{  

			 HJduino_run(70,3000);//前进1S 
			 HJduino_brake(500);//停止0.5S			
			 HJduino_back(70,1000);//后退1s
			 HJduino_brake(500);//停止0.5S
//			
       HJduino_Left(70,1000);//左转1S
        HJduino_Right(70,1000);//右转1S
////  	 
    		 HJduino_Spin_Right(70,1000);//向右旋转2S
 		    HJduino_Spin_Left(70,1000);//向左旋转2S
         HJduino_brake(5000);//停止0.5S 		
		}
 }

