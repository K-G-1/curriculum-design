#include"all.h"
uint count1,count2;
uint systick_cnt = 0;							//����ʱ�Ӽ��� 
uint ms_10,ms_100,ms_500,ms_1000 = 0;			// ����Ƶ��


void init()
{
 	TMOD=0x01;	    //���嶨ʱ��0������ʽ1
	TH0=(65536-1000)/256;  	  // 12Mʱ�Ӿ���1ms�ļ�ʱ
	TL0=(65536-1000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}

void task(void)
{
	//��ȡ���洫��������ϴ�����
 	if(ms_10 == 1)
	{
		 ms_10 = 0;
		 detection_IO();
	}
	// ��ʻ�߼�
	if(ms_100 == 1)
	{
		ms_100 = 0;
		travel_task(10);
	}
	// ADC����
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
		// �������
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
