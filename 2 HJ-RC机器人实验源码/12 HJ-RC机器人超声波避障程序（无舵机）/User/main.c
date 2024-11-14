#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "IRSEARCH.h"
#include "IRAvoid.h"
#include "usart.h"
#include "UltrasonicWave.h"
#include "timer.h"

 int main(void)
 {	

	 delay_init();
	 KEY_Init();
	 IRSearchInit();
	 IRAvoidInit();
   Timerx_Init(5000,7199);   //10Khz的计数频率，计数到5000为500ms 
	 UltrasonicWave_Configuration();               //对超声波模块初始化
	 uart_init(115200);
	 TIM4_PWM_Init(7199,0);  //初始化PWM
	 HJduino_brake(500);
	 keysacn();		
		while(1)
		{  		
	 	  printf("测到的距离值为：%d\n",UltrasonicWave_StartMeasure());
			if(UltrasonicWave_StartMeasure()<80)
      {
     
				HJduino_brake(500);
				HJduino_back(70,1000);
				HJduino_brake(500);
        HJduino_Right(70,500);		
				
        //BEEP_SET;
      }
    else     
      {
        HJduino_run(70,1);
        //BEEP_RESET; 
      }			
		}
 }

