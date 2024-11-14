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
   Timerx_Init(5000,7199);                //10Khz的计数频率，计数到5000为500ms 
	 //UltrasonicWave_Configuration();        //对超声波模块初始化
	 //uart_init(115200);
	 TIM4_PWM_Init(7199,0);                 //初始化PWM
	 TIM5_PWM_Init(9999,143);               //不分频，PWM频率=72*10^6/(9999+1)/(143+1)=50Hz	 
	 //keysacn();		
	while(1)
	{ 
	HJduino_brake(500);	 //停止小车
		
	SetJointAngle(5); //0
	delay_ms(300);
		
		SetJointAngle(90); //舵机中间位置 85-95 
	delay_ms(100);	
		
			SetJointAngle(175); //舵机结束位置 180
	delay_ms(300);

	}
 }
