#include"all.h"
uint count1,count2;
uint systick_cnt = 0;							//心跳时钟计数 
uint ms_10,ms_100,ms_500,ms_1000 = 0;			// 调用频率

uint PWM_Left = 20;
uint PWM_Right = 20;
uint PWM_Left_cnt = 0;
uint PWM_Right_cnt = 0;

void init()
{
 	TMOD=0x11;	    //定义定时器0工作方式1
	TH0=(65536-1000)/256;  	  // 12M时钟就是1ms的计时
	TL0=(65536-1000)%256;
	TH1=(65536-500)/256;  	  // 12M时钟就是1ms的计时
	TL1=(65536-500)%256;
	EA=1;
	ET0=1;
	TR0=1;
	ET1=1;
	TR1=1;
}

void task(void)
{
	//读取火焰传感器与避障传感器
 	if(ms_10 == 1)
	{
		 ms_10 = 0;
		 detection_IO();
		 display(voltage);
	}
	// 行驶逻辑
	if(ms_100 == 1)
	{
		ms_100 = 0;

		travel_task(10);
	}
	// ADC任务
	if(ms_500 == 1)
	{
		  ADC_task();
	}
	//led显示，也可以当做报警设置
	if(ms_1000 == 1)
	{
		 ms_1000 = 0;
		 
		 LED_task(machine_status);
	}
}
void main()
{
	
	init();
	P0=0x00;
	P1=0x00;
	P2=0x00;
	P2=0x00;
//	PWM1 = 1;
//	PWM2 = 1;
	Forward();
	while(1)
	{
		// 任务调用
		task();
		

	}

}
//这个中断最好不要修改
void  time0() interrupt 1
{
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	systick_cnt ++;

	if(systick_cnt %10 == 0)
		ms_10 = 1;
	if(systick_cnt % 100 == 0)
		ms_100 = 1 ;
	if(systick_cnt % 500 == 0)
		ms_500 = 1 ;
	if(systick_cnt % 1000 == 0)
		ms_1000 = 1 ;

}


void  time1() interrupt 3
{
	TH1=(65536-500)/256;
	TL1=(65536-500)%256;
	PWM_Left_cnt ++;
	PWM_Right_cnt++;

	if(PWM_Left_cnt > PWM_Left)
		PWM1 = 1;

	if(PWM_Left_cnt >= Full_PWM)
	{
	 	PWM_Left_cnt = 0;
		PWM1 = 0;
	}

	if(PWM_Right_cnt > PWM_Right)
		PWM2 = 1;

	if(PWM_Right_cnt >= Full_PWM)
	{
	 	PWM_Left_cnt = 0;
		PWM2 = 0;
	}

}
