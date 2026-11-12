//standard pico library
#include "pico/stdlib.h"

//defines on and off
#define GPIO_ON 1
#define GPIO_OFF 0

//defines what pin LED is
#define LED_PIN 16

//initalizes program
int main() {

    //initalizes pin
    gpio_init(LED_PIN);
    //defines LED pin
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, GPIO_ON);
        sleep_ms(2000);
        gpio_put(LED_PIN, GPIO_OFF);
        sleep_ms(2000);
    }
}
