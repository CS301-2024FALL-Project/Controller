#include "stm32f10x.h"
#include "delay.h"
#include "motor.h"
#include "usart.h"
#include "remote.h"   
 int main(void)
 {	
	 u8 key;
	 delay_init();
	 TIM4_PWM_Init(7199,0);  //��ʼ��PWM
	// NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2	  
	// uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600  
	 Remote_Init();			//������ճ�ʼ��	
   HJduino_brake(500);	 
	 while(1)
		{  
		 	key=Remote_Scan();	
	//		printf("%d\n",key);
			switch(key)
			{    
				case 98:HJduino_run(60,100);break;	    
				case 2:HJduino_brake(100);break;		 	  
				case 194:HJduino_Right(60,100);break;	   
				case 34:HJduino_Left(60,100);break;		  
				case 224:HJduino_Spin_Left(60,100);break;		  
				case 168:HJduino_back(60,100);break;		   
				case 144:HJduino_Spin_Right(60,100);break;		    
			}
				
		}
 }

