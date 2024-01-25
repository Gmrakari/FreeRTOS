#ifndef _APP_H
#define _APP_H

#include <stdio.h>

#define USE_DEBUG (1)

#if USE_DEBUG
    #define LOG_DEBUG(format, ...) printf("[%s][%d]"format"\r\n", __func__, __LINE__, ##__VA_ARGS__)
    #define LOG_ERROR(format, ...) printf("ERROR [%s][%d]"format"\r\n", __func__, __LINE__, ##__VA_ARGS__)
#endif

void app(void);

#endif // _APP_H