#include"all.h"

//�޸��������궨�� �Կ���С������ʻ����
#define straight_Ver_Max 50
#define straight_Hoz_Max 30

#define Turn_Max 20


extern count1,count2;
uint run_status =0 ;
uint Vec_cnt , Hoz_cnt,Turn_cnt = 0;


void Forward()
{
      in1=1;			//����
	  in2=0;
	  in3=1;			  //�ҵ��
	  in4=0;
}

void Back()
{
      in1=0;			//����
	  in2=1;
	  in3=0;			  //�ҵ��
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


void forward1()	//���1ǰ��
{
	in1=1;
	in2=0;
}
void forward2()	 //���2ǰ��
{
	in3=1;
	in4=0;
}

void speed(uint cnt1,uint sd1,uint cnt2,uint sd2)
{
   if(cnt1<sd1)		//���1	PWM����
   		PWM1=1;
	else
		PWM1=0;
	if(cnt2<sd2)//���2	PWM����
	   	PWM2=1;
	else
	    PWM2=0;
}
void turn(uint cnt1,uint sd1,uint cnt2,uint sd2)
{
	forward1();
	forward2();
	speed(cnt1,sd1,cnt2,sd2);
}
// 100ms����һ��
void travel_logic(void)
{
// ״̬ �л�
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

//��������
	 if(run_status == 0)
	 {
	  	   Forward();
	 }
	 if(run_status == 1)
	 {
	  	   Left();
	 }
	 if(run_status == 2)
	 {
	  	   Forward();
	 }
	 if(run_status == 3)
	 {
	  	   Left();
	 }
	 if(run_status == 4)
	 {
	  	   Forward();
	 }
	 if(run_status == 5)
	 {
	  	   Left();
	 }
	 if(run_status == 6)
	 {
	  	   Forward();
	 }
	 if(run_status == 7)
	 {
	  	   Stop();
	 }

}
void travel_task(uchar Feq)
{
	travel_logic();
}