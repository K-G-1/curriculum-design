#include "all.h"
#include<intrins.h>

uchar voltage;

sbit scl1=P1^1; //芯片的通信脉冲引脚
sbit sda1=P1^2;  //数据传输引脚
sbit px1=P1^5;  //片选引脚，即选择ADC0831和DS1302
sbit cs1=P1^0; //片选引脚


uchar readad0831() //本函数是按照ADC0831的协议编写的
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

