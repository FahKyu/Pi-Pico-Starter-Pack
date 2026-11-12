cmake_minimum_required(VERSION 3.12)

#Pull in Pico SDK (MUST BE BEFORE PROJECT)
include(pico_sdk_import.cmake)

project(OLED_sensor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

#Initialize SDK
pico_sdk_init()

add_executable(OLED_sensor
        main.c
        ssd1306.c
        )

#Pulls pico_stdlib
target_link_libraries(OLED_sensor pico_stdlib hardware_i2c)
target_link_directories(OLED_sensor PRIVATE ssd1306)

#display features
pico_enable_stdio_usb(OLED_sensor 1)
pico_enable_stdio_uart(OLED_sensor 0)

#create map/bin/hex file
pico_add_extra_outputs(OLED_sensor)
