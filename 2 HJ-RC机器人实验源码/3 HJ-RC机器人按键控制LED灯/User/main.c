//HJ-RCʵ��� HJ-RC������ K1�������Ƶ���L1�����
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
