#include"all.h"



void pwm_init(void)  //	 8位 PWM
{
	CMOD=0x02;//空闲模式下PCA计数器继续工作，定时器0的溢出脉冲
	CL=0x00;
	CH=0x00; //低八位CL和高八位CH，复位值为0

	CCAPM0=0x42;  //PCA模块0的比较/捕获寄存器
	CCAP0L=0x00;  //低位字节   模块0的捕获/比较寄存器
	CCAP0H=0x00;  //高位字节
	//PWM实现方法，因为是８位，CL基础计数器从0xFF递减到０x00,溢出后将CCAP0H
    //的值加载到CCAP0L，若CL递减过程中，若大于CCAP0L，则输出高电平，否则为低电平

    //CCON|=0X40;  //开启PCA计数器
	CR=1;  //开启PCA计数器
	//两种皆可开启
} 

void pwm_set(uchar x)//占空比设置	负占 空比
{
	CCAP0H=255-x;	//设置比较值
	CCAP0L=255-x;
}

