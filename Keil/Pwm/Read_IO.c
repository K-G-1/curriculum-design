#include "all.h"

uchar flame_old,obstacle_old = 0;
uchar machine_status = 0;
uchar mechine_flag = 0;

uchar detection_IO(void)
{
	if(flame == 1&&flame_old == 0)
   	{
		 machine_status = 1;
		 mechine_flag  = 1;
	}

	if(obstacle == 1&&obstacle_old == 0)
	{
		machine_status = 2;
		mechine_flag = 1;
	}

 	if(flame != flame_old)
	{
	 	flame_old = flame;	
	}
	if(obstacle != obstacle_old)
	{
	 	obstacle_old = obstacle;	
	}

	if(flame == 0 && obstacle == 0 && voltage >=40)
	{
	 	machine_status = 0;
	}

	return 0;
}


