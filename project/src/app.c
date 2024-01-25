#include "app.h"

#include "FreeRTOS.h"
// #include "FreeRTOSConfig.h"
#include "queue.h"

typedef struct {
    void *msg;
    void *resp;
    void *issue;
    void *event;
} ark_rinoiot_queue_t;

typedef struct {
    ark_rinoiot_queue_t *ark_rinoiot_queue;
} private_t;

static private_t *private = NULL;

void app(void) { LOG_DEBUG();

    // private->ark_rinoiot_queue->msg = xQueueCreate(5, 10);

}