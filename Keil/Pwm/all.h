#ifndef __all_H__
#define __all_H__

#include"qudong.h"
#include"common.h"
#include"delay.h"
#include"pwm.h"
#include "read_io.h"
sbit in1=P2^0;    
sbit in2=P2^1;	  						
sbit in3=P2^2;  
sbit in4=P2^3;


sbit led1=P0^0;
sbit led2=P0^1;
sbit led3=P0^2;
sbit led4=P0^3;

sbit PWM1=P2^4;
sbit PWM2=P2^5;

sbit flame = P1^7;
sbit obstacle = P1^6;









#endif