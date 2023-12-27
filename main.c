#include <stdio.h>
#include <stdlib.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void vApplicationDaemonTaskStartupHook(void);

void vApplicationDaemonTaskStartupHook(void) { return ;}

void vApplicationTickHook(void)
{
#if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 0 )
    {
        
    }
#endif 
}

static void vTask1( void *pvParameters );
static void vTask2( void *pvParameters );

int main()
{
    static xQueueHandle xTestQueue;
    xTestQueue = xQueueCreate( 10, ( unsigned portBASE_TYPE ) sizeof( unsigned short ) );
    xTaskCreate( vTask1, "vTask1", configMINIMAL_STACK_SIZE, ( void * ) &xTestQueue, tskIDLE_PRIORITY, NULL );
    xTaskCreate( vTask2, "vTask2", configMINIMAL_STACK_SIZE, ( void * ) &xTestQueue, tskIDLE_PRIORITY, NULL );

    vTaskStartScheduler();
    return 1;
}

static void vTask1( void *pvParameters )
{
unsigned short usValue = 0, usLoop;
xQueueHandle *pxQueue;
const unsigned short usNumToProduce = 3;
short sError = pdFALSE;

    pxQueue = ( xQueueHandle * ) pvParameters;

    for( ;; )
    {       
        for( usLoop = 0; usLoop < usNumToProduce; ++usLoop )
        {
            /* Send an incrementing number on the queue without blocking. */
            printf("Task1 will send: %d\r\n", usValue);
            if( xQueueSendToBack( *pxQueue, ( void * ) &usValue, ( portTickType ) 0 ) != pdPASS )
            {
                sError = pdTRUE;
            }
            else
            {
                ++usValue;
            }
        }
        vTaskDelay( 2000 );
    }
}
static void vTask2( void *pvParameters )
{
unsigned short usData = 0;
xQueueHandle *pxQueue;

    pxQueue = ( xQueueHandle * ) pvParameters;

    for( ;; )
    {       
        while( uxQueueMessagesWaiting( *pxQueue ) )
        {
            if( xQueueReceive( *pxQueue, &usData, ( portTickType ) 0 ) == pdPASS )
            {
                printf("Task2 received:%d\r\n", usData);
            }
        }
        vTaskDelay( 5000 );
    }
}

#if 0
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

void vApplicationIdleHook(void)
{
  
}
void vApplicationTickHook(void)
{
#if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 0 )
    {
        
    }
#endif 
}

void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    for(;;);
}

void vApplicationDaemonTaskStartupHook(void);

void vApplicationDaemonTaskStartupHook(void) { return ;}

static TaskHandle_t xTask = NULL;

static void task(void *p)
{
    int cnt = 0;

    for(;;)
    {
        printf("task %x\n", cnt++);
        vTaskDelay(1000);
    }
}


int main(void)
{
    BaseType_t xReturn = pdPASS;

    printf("Freertos v10.4.1\n");
    fflush(stdout);

    xReturn = xTaskCreate(  (TaskFunction_t )task,
                            (const char *   )"task",
                            (unsigned short )128,
                            (void *         )NULL,
                            (UBaseType_t    )1,
                            (TaskHandle_t * )&xTask);

    if (pdPASS != xReturn){
        return -1;
    }

    vTaskStartScheduler();

    while(1);
    return 0;
}
#endif