#ifndef __all_H__
#define __all_H__

#include"qudong.h"
#include"common.h"
#include<intrins.h>
#include"delay.h"
#include"pwm.h"
#include "read_io.h"
#include "display.h"
#include "ADC0832.h"


#define Full_PWM    20

sbit in1=P2^0;    
sbit in2=P2^1;	  						
sbit in3=P2^2;  
sbit in4=P2^3;


sbit led1=P3^0;
sbit led2=P3^1;
sbit led3=P3^2;
sbit led4=P3^3;

sbit PWM1=P2^4;
sbit PWM2=P2^5;

extern uint PWM_Left ,PWM_Right ,PWM_Left_cnt ,PWM_Right_cnt ;


sbit flame = P1^7;
sbit obstacle = P1^6;









#endif