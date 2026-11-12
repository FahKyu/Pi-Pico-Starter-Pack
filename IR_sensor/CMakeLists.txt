cmake_minimum_required(VERSION 3.12)

#Pull in Pico SDK (MUST BE BEFORE PROJECT)
include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#Initialize SDK
pico_sdk_init()

add_executable(IR_sensor
        IR_sensor.c
        )

#Pulls pico_stdlib
target_link_libraries(IR_sensor pico_stdlib)

#create map/bin/hex file
pico_add_extra_outputs(IR_sensor)
