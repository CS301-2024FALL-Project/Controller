//HJ-RC实验板 HJ-RC机器人 K1按健控制点亮L1发光管
#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "keysacn.h"

 int main(void)
 {	
	 delay_init();
	 KEY_Init();
		while(1)
		{  
		 keysacn();			
		}
 }
