#include "all.h"


uchar code table[]={0x3f,0x06,0x5b,//�������ʾ����ֵ
0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};


sbit wei1= P2^6;
sbit wei2= P2^7;
uchar tmpdata[]={0,0,0};
uchar readad0831();//����ú���Ϊ��ȡADC0831������

//void delay_nop()  //��ʱ�Ӻ���
//{
//	 _nop_();_nop_();_nop_();_nop_();_nop_();
//}

void display(uint dis_data) //��ʾ�Ӻ���
{
	uchar i;  //����ֲ�����
	uchar shi,ge   ;
//	P0=0x00;   //�˿�P0Ϊ�����
	if(dis_data <100)
	{
		shi = dis_data/10;
		ge = dis_data%10;
	}
	else return;
	
	wei1 = 1;
	wei2 = 0;
	P0=~table[shi]; //ѭ����ʾ
	delay_us(500);  //��ʱ�����ָ��
	wei1 = 0;
	wei2 = 1;
	P0=~table[ge]; //ѭ����ʾ
	delay_us(500);  //��ʱ�����ָ��

	_nop_();
}

void LED_task(uchar sta)
{
	if(sta == 0)
	{
	   led1 = 1;
	}

	if(sta == 1)
	{
		led1 = 0;
	   led2 = 1;
	}
	else led2= 0;

	if(sta == 2)
	{
		led1 = 0;
		led3 = 1 ;
	}
	else led3  = 0;

	if(sta == 3)
	{
		led1 = 0;
		led4 = 1 ;
	}
	else led4 = 0;


}