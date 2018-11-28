#include"all.h"
uint count1,count2;
uint systick_cnt = 0;							//心跳时钟计数 
uint ms_10,ms_100,ms_500,ms_1000 = 0;			// 调用频率


void init()
{
 	TMOD=0x01;	    //定义定时器0工作方式1
	TH0=(65536-1000)/256;  	  // 12M时钟就是1ms的计时
	TL0=(65536-1000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void task(void)
{
	//读取火焰传感器与避障传感器
 	if(ms_10 == 1)
	{
		 ms_10 = 0;
		 detection_IO();
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

	}
	if(ms_1000 == 1)
	{
		 ms_1000 = 0;
		 display(machine_status);
	}
}
void main()
{

	init();
	P0=0x00;
	P1=0x00;
	P2=0x00;
	PWM1 = 1;
	PWM2 = 1;
	while(1)
	{
		// 任务调用
		task();
		
	}

}

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
