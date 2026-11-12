#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

//defining sensor
#define sensor_PIN 18

//defining display
#define SDA_PIN 16
#define SCL_PIN 17

int main(void){
    stdio_init_all();

    //I2C setup
    i2c_init(i2c0, 400*1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    //initalizing display
    ssd1306_t display;
    display.external_vcc = false;
    ssd1306_init(&display, 128, 64, 0x3c, i2c0);

    //initalizing sensor
    gpio_init(sensor_PIN);
    gpio_set_dir(sensor_PIN, GPIO_IN);

    while(true){
        ssd1306_clear(&display);
        ssd1306_draw_string(&display, 0, 0, 1, "Object Detection");

        if(gpio_get(sensor_PIN) == 0){
            ssd1306_clear_square(&display, 0, 16, 128, 16);
            ssd1306_clear_square(&display, 0, 32, 128, 16);
            ssd1306_draw_string(&display, 0, 16, 1, "Object");
            ssd1306_draw_string(&display, 0, 32, 1, "Detected");
            ssd1306_show(&display);
        }
        else{
            ssd1306_clear_square(&display, 0, 16, 128, 16);
            ssd1306_clear_square(&display, 0, 32, 128, 16);
            ssd1306_draw_string(&display, 0, 16, 1, "No Objects");
            ssd1306_draw_string(&display, 0, 32, 1, "Detected");
            ssd1306_show(&display);
        }
    }
}