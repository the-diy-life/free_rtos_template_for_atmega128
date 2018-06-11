# using FreeRTOS in ATMega128



## Getting Started

These instructions will give details on how to create simple template to use FreeRTOS in ATMega128

## Prerequisites

What software you need to install 


> 1- Download and install the latest version of atmel studio from [here](http://www.microchip.com/mplab/avr-support/atmel-studio-7)
 we are using in that project atmel studio 7.0
 

> 2-Download and install the latest full version of FreeRTOS source code from [here](https://www.freertos.org/a00104.html)
 we are using in this project FreeRTOSv10.0.1




## preparing atmel studio project
> 1- Create new project in AVRStudio5. For this we simply File->New Project and select AVR GCC C Executable Project. Enter proper location where your project will be stored.

> 2- Click OK. Then select Device “Atmega128” from device list

> 3- click right mouse button on project folder and select Add->New Folder and name it Source.

> 4- import to that created Source folder all files that are in Source directory from downloaded FreeRTOS package. here We have added only kernel C files

> 5- To include port files create folder named portable inside Source folder. And then in portable folder we create GCC folder. And in GCC we create folder named ATMega323. Then import porting files port.c and portmacro.h to this folder from FreeRTOS package.

> 6- to inclode memory management file heap_1.c, which takes care of allocating and freeing memory for tasks and queues. create MemMang folder in portable folder and add file from same folder in downloaded package

> 7- And lastly FreeRTOS needs FreeRTOSConfig.h configuration file that keeps all freeRTOS related settings. Just import it from FreeRTOS\Demo\AVR_ATMega323_WinAVR.

> 8- create another folder Drivers in project root directory. This will be used to store microcontroller peripheral drivers like USART, I2C, ADC, button, LED and so on.

> 9- configure the project by going to project then select properties
	 
  > * go to Build tab. then Select Configuration as Release. So wee need to generate .hex file
  > * In Toolchain tab and Optimization select -Os optimization
  > * in Directories you will need to include all directories containing .h files in your project
  > * Add GCC_MEGA_AVR in Defined Symbols to tell core that we are going to use GCC for AVR microcontroller
  
## FreeRTOS Configuration
* All predefined parameters are placed in FreeRTOSConfig.h file. AVR microcontroller is too small to use all features ofFreeRTOS because of limited RAM. So for our basic example we are using following settings:



		#define configUSE_PREEMPTION        1
		#define configUSE_IDLE_HOOK         0
		#define configUSE_TICK_HOOK         0
		#define configCPU_CLOCK_HZ          ( ( unsigned long ) 7372800 )
		#define configTICK_RATE_HZ          ( ( portTickType )1000 )
		#define configMAX_PRIORITIES        ( ( unsigned portBASE_TYPE ) 1 )
		#define configMINIMAL_STACK_SIZE    ( ( unsigned short ) 85 )
		#define configTOTAL_HEAP_SIZE       ( (size_t ) ( 3500 ) )
		#define configMAX_TASK_NAME_LEN     ( 8 )
		#define configUSE_TRACE_FACILITY    0
		#define configUSE_16_BIT_TICKS      1
		#define configIDLE_SHOULD_YIELD     1
		#define configQUEUE_REGISTRY_SIZE   0
		/* Co-routine definitions. */
		define configUSE_CO_ROUTINES       0
		define configMAX_CO_ROUTINE_PRIORITIES ( 2 )
		/* Set the following definitions to 1 to include the API function, or zero
		to exclude the API function. */
		
		#define INCLUDE_vTaskPrioritySet        0
		#define INCLUDE_uxTaskPriorityGet       0
		#define INCLUDE_vTaskDelete             0
		#define INCLUDE_vTaskCleanUpResources   0
		#define INCLUDE_vTaskSuspend            0
		#define INCLUDE_vTaskDelayUntil         1
		#define INCLUDE_vTaskDelay              0


## Refrences
for more information see 

* [Using FreeRTOS kernel in AVR projects](https://scienceprog.com/using-freertos-kernel-in-avr-projects/)


		
