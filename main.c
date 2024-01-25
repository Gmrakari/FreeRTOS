#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "app.h"

typedef struct {
    TaskHandle_t send;
    TaskHandle_t recv;
} xTask_t;

static xTask_t xTask = { .send = NULL, .recv = NULL };

static void sendtask(void *pvParameters) {
    while (1) { LOG_DEBUG();
        
        vTaskDelay(1000);
    }
}

static void recvtask(void *pvParameters) {
    while (1) { LOG_DEBUG();
        vTaskDelay(1000);
    }
}

static void initTask(void *pvParameters) {
    app();
    vTaskDelete(NULL);
}


int main(void)
{
    BaseType_t xReturn = pdPASS;

    printf("Freertos v10.4.1\n");
    fflush(stdout);

    xReturn = xTaskCreate(  (TaskFunction_t )initTask,
                            (const char *   )"initTask",
                            (unsigned short )128,
                            (void *         )NULL,
                            (UBaseType_t    )1,
                            (TaskHandle_t * )NULL);

    xReturn = xTaskCreate(  (TaskFunction_t )sendtask,
                            (const char *   )"sendtask",
                            (unsigned short )128,
                            (void *         )NULL,
                            (UBaseType_t    )1,
                            (TaskHandle_t * )&xTask.send);

    if (pdPASS != xReturn){
        return -1;
    }

    xReturn = xTaskCreate(  (TaskFunction_t )recvtask,
                            (const char *   )"recvtask",
                            (unsigned short )128,
                            (void *         )NULL,
                            (UBaseType_t    )1,
                            (TaskHandle_t * )&xTask.recv);

    vTaskStartScheduler();

    char pub_topic[] = "rlink/v2/z2cushdnt5AXUZ/rn01CB6BbdD5065B/report_response";
    char sub_topic[] = "rlink/v2/z2cushdnt5AXUZ/rn01CB6BbdD5065B/report_response";

    while(1);
    return 0;
}

void vApplicationIdleHook(void)
{
  
}
void vApplicationTickHook(void)
{

}

void vApplicationMallocFailedHook(void)
{
    taskDISABLE_INTERRUPTS();
    for(;;);
}

void vApplicationDaemonTaskStartupHook(void);

void vApplicationDaemonTaskStartupHook(void) { return ;}