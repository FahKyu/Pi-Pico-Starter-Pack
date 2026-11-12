#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

//defining SDA and SCL pins
#define SDA_PIN 16
#define SCL_PIN 17

int main(void){

//starts usb serial
stdio_init_all();

//sets up I2C
i2c_init(i2c0, 400*1000);
gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
gpio_pull_up(SDA_PIN);
gpio_pull_up(SCL_PIN);

//intializes display
ssd1306_t display;
display.external_vcc = false;
ssd1306_init(&display, 128, 64, 0x3c, i2c0);

while (true){
//drawing
    ssd1306_clear(&display);
    ssd1306_draw_string(&display, 0, 0, 1, "HELLO, WORLD!");
    ssd1306_draw_string(&display, 0, 16, 2, "How are you?");
    ssd1306_show(&display);
}
}