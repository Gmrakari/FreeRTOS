cmake_minimum_required(VERSION 3.10)

project(FreeRTOS_Posix C)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/kernel/*.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/*.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/kernel/portable/MemMang/heap_4.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/kernel/portable/ThirdParty/GCC/Posix/port.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/kernel/portable/ThirdParty/GCC/Posix/utils/*.c)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/include
        ${CMAKE_CURRENT_SOURCE_DIR}/kernel/portable/ThirdParty/GCC/Posix/utils
        ${CMAKE_CURRENT_SOURCE_DIR}/
)

# Compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-pointer-sign")

# Debug build
if (DEBUG)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -gdwarf-2")
endif()

# Build type
if (OPT EQUAL 0)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
endif()

# Link libraries
set(LIBS -lm -lrt -pthread)

# Build executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
