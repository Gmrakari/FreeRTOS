# 前言

在Ubuntu Linux 22.04环境下，模拟运行FreeRTOS

目前工作中使用的版本是V10.4.1，所以下载移植V10.4.1

[github下载链接](https://github.com/FreeRTOS/FreeRTOS/releases/download/V10.4.1/FreeRTOSv10.4.1.zip)

（注：FreeRTOSv10.4.1.zip才有Source，Source code.tar.gz是Source里面是空文件）

下载完成之后，解压可以得到FreeRTOSv10.4.1文件夹



# 准备

运行一个FreeRTOS需要

1.FreeRTOS配置文件

2.内核 include / src

3.接口 portable

4.用户文件 main.c 

5.编译脚本



# 1.FreeRTOS配置文件

FreeRTOSConfig.h 关于FreeRTOS的一些宏开关

FreeRTOSConfig.h

FreeRTOSv10.4.1/FreeRTOS/Demo/Posix_GCC/FreeRTOSConfig.h



# 2.内核 include / src

创建一个kernel目录，里面是内核头文件和一些实现

include 从

FreeRTOSv10.4.1/FreeRTOS/Source/include中将所有的文件拷贝



kernel源文件

从FreeRTOSv10.4.1/FreeRTOS/Source中*.c中拷贝

# 3.接口 portable

接口

portable从

FreeRTOS/Source/portable/ThirdParty/GCC/Posix下拷贝所有文件



# 4.用户文件 main.c 

在主目录下创建一个main.c

主要运行FreeRTOS demo



# 5.编译脚本

提供了Makefile和CMakeLists.txt

见源码



文件结构如下:

```
FreeRTOS_OS
├── CMakeLists.txt
├── FreeRTOSConfig.h
├── kernel
│   ├── croutine.c
│   ├── event_groups.c
│   ├── include
│   │   ├── atomic.h
│   │   ├── croutine.h
│   │   ├── deprecated_definitions.h
│   │   ├── event_groups.h
│   │   ├── FreeRTOS.h
│   │   ├── list.h
│   │   ├── message_buffer.h
│   │   ├── mpu_prototypes.h
│   │   ├── mpu_wrappers.h
│   │   ├── portable.h
│   │   ├── portmacro.h
│   │   ├── projdefs.h
│   │   ├── queue.h
│   │   ├── semphr.h
│   │   ├── stack_macros.h
│   │   ├── StackMacros.h
│   │   ├── stdint.readme
│   │   ├── stream_buffer.h
│   │   ├── task.h
│   │   └── timers.h
│   ├── list.c
│   ├── portable
│   │   ├── MemMang
│   │   │   ├── heap_1.c
│   │   │   ├── heap_2.c
│   │   │   ├── heap_3.c
│   │   │   ├── heap_4.c
│   │   │   ├── heap_5.c
│   │   │   └── ReadMe.url
│   │   ├── readme.txt
│   │   └── ThirdParty
│   │       └── GCC
│   │           └── Posix
│   │               ├── FreeRTOS-simulator-for-Linux.url
│   │               ├── port.c
│   │               └── utils
│   │                   ├── wait_for_event.c
│   │                   └── wait_for_event.h
│   ├── queue.c
│   ├── stream_buffer.c
│   ├── tasks.c
│   └── timers.c
├── main.c
├── Makefile
└── README.md
```



# 运行FreeRTOS

## 支持CMake和Makefile

### 1.CMake

mkdir build && cd build && cmake .. 

编译完成之后

cd ../bin/FreeRTOS_Posix

### 2.Makefile

直接在makefile所在目录，使用make，make没有报错之后

cd build && ./FreeRTOS_Posix.elf



# 附录

查看FreeRTOS版本

```shell
define tskKERNEL_VERSION_NUMBER       "V10.4.1"
```

## 