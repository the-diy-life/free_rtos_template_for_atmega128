/*
 * test_free_rtos_atmega128.c
 *
 * Created: 6/9/2018 6:23:15 AM
 * Author : Ahmed Hosny
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
///////////////////////////////////////////
/* Priority definitions for most of the tasks in the demo application.  Some
tasks just use the idle priority. */



/////////////////////////////////////////

portSHORT main(void)
{
	//////////////////////////////////
	/* tasks creation can be here*/
	
	
	
	
	//////////////////////////////////
	
	//start scheduler
	vTaskStartScheduler();
	
	//you should never get here
	while(1)
	{
		
	}
	return 0;
}


