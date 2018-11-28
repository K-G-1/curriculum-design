#include "all.h"
#include<intrins.h>

uchar voltage;

sbit scl1=P1^1; //оƬ��ͨ����������
sbit sda1=P1^2;  //���ݴ�������
sbit px1=P1^5;  //Ƭѡ���ţ���ѡ��ADC0831��DS1302
sbit cs1=P1^0; //Ƭѡ����


uchar readad0831() //�������ǰ���ADC0831��Э���д��
{
 char i=0,tmp=0;
 sda1=1;
 cs1=0;
 _nop_();
 _nop_();
 scl1=0;
 _nop_();
 _nop_();
 scl1=1;
 _nop_();
 _nop_();
 scl1=0;
_nop_();
 _nop_();
 scl1=1;
 _nop_();
 _nop_();
 scl1=0;
 _nop_();
 _nop_();
 for(i=0;i<8;i++)
 {
 tmp<<=1;
 if(sda1)
 tmp++;
  scl1=1;
  _nop_();
  _nop_();
  scl1=0;
  _nop_();
  _nop_();
 }
 cs1=1;
 return tmp;
}

void ADC_task()
{
 	uchar ADC_value = 0;
	

	ADC_value = readad0831();
	voltage = 	ADC_value*5*10/255;

	if(voltage <40)
		machine_status = 3;

}

