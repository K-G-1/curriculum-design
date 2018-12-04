#include"all.h"

//修改这三个宏定义 以控制小车的行驶距离
#define straight_Ver_Max 50
#define straight_Hoz_Max 30

#define Turn_Max 20


extern count1,count2;
uint run_status =0 ;
uint Vec_cnt , Hoz_cnt,Turn_cnt = 0;
uint travel_rate = 0;
uint travel_distance = 0;
void Forward()
{
      in1=1;			//左电机
	  in2=0;
	  in3=1;			  //右电机
	  in4=0;
}

void Back()
{
      in1=0;			//左电机
	  in2=1;
	  in3=0;			  //右电机
	  in4=1;
}

void Left()
{
      in1=0;
	  in2=0;
	  in3=1;
	  in4=0;
}

void Right()
{
      in1=1;
	  in2=0;
	  in3=0;
	  in4=0;
}

void Stop()
{
      in1=0;
	  in2=0;
	  in3=0;
	  in4=0;
}


void forward1()	//电机1前进
{
	in1=1;
	in2=0;
}
void forward2()	 //电机2前进
{
	in3=1;
	in4=0;
}

void speed(uint cnt1,uint sd1,uint cnt2,uint sd2)
{
		PWM_Left = cnt1;
		PWM_Right = cnt2;
}

//计算 行驶的距离和速率
void Distance_calculation(uint Feq)
{
									 	   //cm
	travel_rate = Falling_edge * Feq * (float)20.4; // 2.55 = 20.4 / 8 = 2.55 算出每一个脉冲的轮子走了多少距离
	travel_distance += travel_rate;   //计路程

}
void turn(uint cnt1,uint sd1,uint cnt2,uint sd2)
{
	forward1();
	forward2();
	speed(cnt1,sd1,cnt2,sd2);
}
// 100ms调用一次
void travel_logic_for_time(void)
{
// 状态 切换
//	display(PWM_Left);
	 if(run_status == 0)
	 {
	 		Vec_cnt ++;
	  	   if(Vec_cnt >= straight_Ver_Max)
		   	run_status ++;
	 }
	 if(run_status == 1)
	 {
	 		Turn_cnt ++;
	  	   if(Turn_cnt >= Turn_Max)
		   	run_status ++;
	 }
	 if(run_status == 2)
	 {
	 		Hoz_cnt ++;
	  	   	if(Hoz_cnt >=straight_Hoz_Max)
				run_status ++;
	 }
	 if(run_status == 3)
	 {
	 		Turn_cnt --;
	  	   if(Turn_cnt <= 0)
		   	run_status ++;
	 }
	 if(run_status == 4)
	 {
	  	   Vec_cnt --;
		   if(Vec_cnt <= 0)
		   	run_status ++;
	 }
	 if(run_status == 5)
	 {
	  	   Turn_cnt ++;
		   if(Turn_cnt >= Turn_Max)
		   	run_status ++;
	 }
	 if(run_status == 6)
	 {
	  	   Hoz_cnt --;
		   if(Hoz_cnt <= 0)
		   	run_status ++;
	 }

	if(mechine_flag ==1&&run_status%2!=0)
	{
		run_status ++;

		mechine_flag = 0;
	}

//正常运行
//	 if(run_status == 0)
//	 {
//	  	   Forward();
//	 }
//	 if(run_status == 1)
//	 {
//	  	   Left();
//	 }
//	 if(run_status == 2)
//	 {
//	  	   Forward();
//	 }
//	 if(run_status == 3)
//	 {
//	  	   Left();
//	 }
//	 if(run_status == 4)
//	 {
//	  	   Forward();
//	 }
//	 if(run_status == 5)
//	 {
//	  	   Left();
//	 }
//	 if(run_status == 6)
//	 {
//	  	   Forward();
//	 }
//	 if(run_status == 7)
//	 {
//	  	   Stop();
//	 }

	 if(run_status == 0)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 1)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 2)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 3)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 4)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 5)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 6)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 7)
	 {
	  	   speed(20,0,20,0);
	 }
}


// 根据行驶的距离调用
void travel_logic_for_distence(void)
{
// 状态 切换

//	if(travel_distance < straight_Ver_Max)
//	{
//		   run_status = 0;
//	}
//	else if((travel_distance > straight_Ver_Max)&&(travel_distance < straight_Ver_Max+Turn_Max))
//	{
//		   run_status = 1;
//	}
//	else if((travel_distance > straight_Ver_Max+Turn_Max)&&(travel_distance < straight_Ver_Max+Turn_Max+straight_Hoz_Max))
//	{
//		   run_status = 2;
//	}
//	else if((travel_distance > straight_Ver_Max+Turn_Max+straight_Hoz_Max)&&(travel_distance < straight_Ver_Max+ 2 * Turn_Max+straight_Hoz_Max))
//	{
//		   run_status = 3;
//	}
//	else if((travel_distance > straight_Ver_Max+ 2 * Turn_Max+straight_Hoz_Max)&&(travel_distance < 2*straight_Ver_Max+ 2 * Turn_Max+straight_Hoz_Max))
//	{
//		   run_status = 4;
//	}
//	else if((travel_distance > 2 * straight_Ver_Max+ 2 * Turn_Max+straight_Hoz_Max)&&(travel_distance < 2*straight_Ver_Max+ 3 * Turn_Max+straight_Hoz_Max))
//	{
//		   run_status = 5;
//	}
//	else if((travel_distance > 2 * straight_Ver_Max+ 3 * Turn_Max+straight_Hoz_Max)&&(travel_distance < 2*straight_Ver_Max+ 3 * Turn_Max+ 2 * straight_Hoz_Max))
//	{
//		   run_status = 6;
//	}
//	else if((travel_distance > 2 * straight_Ver_Max+ 3 * Turn_Max+ 2 * straight_Hoz_Max))
//	{
//		   run_status = 7;
//	}

	if(run_status == 0)
	 {
	 		Vec_cnt  = travel_distance;
	  	   if(Vec_cnt >= straight_Ver_Max)
		   {
		   	run_status ++;
			travel_distance = 0;
			}
	 }
	 if(run_status == 1)
	 {
		Turn_cnt =travel_distance;
		if(Turn_cnt >= Turn_Max)
		{
			run_status ++;
			travel_distance = 0;
		}
	 }
	 if(run_status == 2)
	 {
	 		Hoz_cnt  = travel_distance;
	  	   	if(Hoz_cnt >=straight_Hoz_Max)
			{
				run_status ++;
				travel_distance = 0;
			}
	 }
	 if(run_status == 3)
	 {
	 	
		if(Turn_cnt <= travel_distance)
		{
			run_status ++;
			travel_distance = 0;
		}
	 }
	 if(run_status == 4)
	 {
	  	   
		   if(Vec_cnt <= travel_distance)
		   {
		   	run_status ++;
			travel_distance = 0;
			}
	 }
	 if(run_status == 5)
	 {
	  	   Turn_cnt  = travel_distance;
		   if(Turn_cnt >= Turn_Max)
		   	run_status ++;
	 }
	 if(run_status == 6)
	 {
	  	   
		   if(Hoz_cnt <= travel_distance)
		   {
		   	run_status ++;
			travel_distance = 0;
			}
	 }


	if(mechine_flag ==1&&run_status%2!=0)
	{
		run_status ++;
		travel_distance = 0;
		mechine_flag = 0;
	}

//正常运行  修改PWM 控制方向

	 if(run_status == 0)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 1)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 2)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 3)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 4)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 5)
	 {
	  	   speed(20,0,5,0);
	 }
	 if(run_status == 6)
	 {
	  	   speed(5,0,5,0);
	 }
	 if(run_status == 7)
	 {
	  	   speed(20,0,20,0);
	 }
}


void travel_task(uchar Feq)
{
	travel_logic_for_time();
}