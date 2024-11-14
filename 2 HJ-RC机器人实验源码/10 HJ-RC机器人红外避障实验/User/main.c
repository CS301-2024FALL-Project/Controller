#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"
#include "IRSEARCH.h"
#include "IRAvoid.h"

 int main(void)
 {	
	 delay_init();
	 KEY_Init();
	 IRSearchInit();
	 IRAvoidInit();
	 TIM4_PWM_Init(7199,0);  //≥ı ºªØPWM
	 HJduino_brake(500);
	 keysacn();		
		while(1)
		{  
		 AVoidRun();  //±‹’œ∫Ø ˝
		}
 }

