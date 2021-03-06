#include "sys.h" 
#include "delay.h"
#include "MOVE.h"
#include "Line_Patrol.h"

//循迹小车需要的移动方式有，90°直角左拐  			90°直角右拐
// 							左边微调		 		右边微调
// 							直线行驶				刹车
// 					PA0  PA1 左侧		
// 			TIM3 /CH1 PA6		PA6   		右侧		
// 			TIM3 /CH2 PA7		PA7							
//			TIM5 /CH1 PA0		PA0			左侧
//			TIM5 /CH2 PA1		PA1					
//			
//			
//			
//			
//			
//			
//			
//			
//			
//			
//			


/***************************************************/

/***************************************************/

void Wheel_On_Left(u8 type ,u8 speed)			//前进
{
	switch(type)
	{
		case 1: //前进
//			TIM_SetCompare2(TIM3,speed); 	//PA7 PWM1
//			TIM_SetCompare1(TIM3,0);    	//PA6 PWM2
	
			TIM_SetCompare1(TIM5,0); 		//PA0 PWM2
			TIM_SetCompare2(TIM5,speed);    //PA1 PWM1
			break;
		
		case 2:  //后退
			
//			TIM_SetCompare2(TIM3,0); 	//PA7 PWM1
//			TIM_SetCompare1(TIM3,speed);    	//PA6 PWM2
	
			TIM_SetCompare1(TIM5,speed); 		//PA0 PWM2
			TIM_SetCompare2(TIM5,0);    //PA1 PWM1
			break;
		case 3:	//刹车
//			TIM_SetCompare2(TIM3,0); 	//PA7 PWM1
//			TIM_SetCompare1(TIM3,0);    	//PA6 PWM2
	
			TIM_SetCompare1(TIM5,0); 		//PA0 PWM2
			TIM_SetCompare2(TIM5,0);    //PA1 PWM1
			break;
	}
}

/***************************************************/

void Wheel_On_Right(u8 type ,u8 speed)		//后退
{
		switch(type)
		{
		case 1: //前进
			TIM_SetCompare2(TIM3,0); 			//PA7 PWM1
			TIM_SetCompare1(TIM3,speed);    	//PA6 PWM2
	
//			TIM_SetCompare1(TIM5,speed); 		//PA0 PWM2
//			TIM_SetCompare2(TIM5,0);    		//PA1 PWM1
			break;
		
		case 2:  //后退
			
			TIM_SetCompare2(TIM3,speed); 	//PA7 PWM1
			TIM_SetCompare1(TIM3,0);    	//PA6 PWM2
	
//			TIM_SetCompare1(TIM5,0); 		//PA0 PWM2
//			TIM_SetCompare2(TIM5,speed);    //PA1 PWM1
			break;
		
		case 3:	//刹车
			TIM_SetCompare2(TIM3,0); 	//PA7 PWM1
			TIM_SetCompare1(TIM3,0);    	//PA6 PWM2
	
//			TIM_SetCompare1(TIM5,0); 		//PA0 PWM2
//			TIM_SetCompare2(TIM5,0);    //PA1 PWM1
			break;
		}
	
}

/***************************************************/
void Turn_Left(u8 speed)			//左转
{
	Wheel_On_Right(1,speed);
	Wheel_On_Left(2,speed);
}
/***************************************************/


void Turn_Right(u8 speed)			//右转
{
	Wheel_On_Right(2,speed);
	Wheel_On_Left(1,speed);
}
/***************************************************/

void Forward(u8 speed)					//前进
{
	Wheel_On_Right(1,speed);
	Wheel_On_Left(1,speed);
	
}

/***************************************************/
void Brake(void)					//刹车
{
	Wheel_On_Right(3,0);
	Wheel_On_Left(3,0);
	
}
/***************************************************/







/***************************************************/
void Forward_Turn_Right (u8 Aspeed,float adjust)		//前进 右偏
{														// 左侧速度 > 右侧速度
	Wheel_On_Left(1,Aspeed*(1+adjust));					//Wheel_On_Left();
	Wheel_On_Right(1,Aspeed*(1-adjust));				//Wheel_On_Right();
	
}

/***************************************************/


void Forward_Turn_Left(u8 Aspeed,float adjust)		//前进 左偏
{													//右边速度＞左边
	Wheel_On_Left(1,Aspeed*(1-adjust));					//Wheel_On_Left();
	Wheel_On_Right(1,Aspeed*(1+adjust));				//Wheel_On_Right();	
	
}



/***************************************************/

void Left_Turn_Ninety(void)		// 90°左转
{
	Turn_Left(30);
	delay_ms(500);
	while(1)
	{
		if(SLight_Lift == 0)
		{
			delay_ms(500);
			if(SLight_Lift == 0)
			{
				delay_ms(80);
				break;
			}
			
		}
		
	}
	
	
}

/***************************************************/

void Right_Turn_Ninety(void)	// 90°右转
{
	Turn_Right(30);
	delay_ms(500);
	while(1)
	{
		if(SLight_Right == 0)
		{
			delay_ms(500);
			if(SLight_Right == 0)
			{
				delay_ms(80);
				break;
			}
			
		}
		
	}
	
	
	
	
}

/***************************************************/