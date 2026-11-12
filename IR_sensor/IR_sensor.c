#include "pico/stdlib.h"

#define GPIO_OFF 0
#define GPIO_ON 1

#define LED_PIN 16
#define IR_PIN 18

int main(){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(IR_PIN);
    gpio_set_dir(IR_PIN, GPIO_IN);

    while (true){
        if(gpio_get(IR_PIN) == GPIO_ON){
            gpio_put(LED_PIN, GPIO_ON);
        }
        else{
            gpio_put(LED_PIN, GPIO_OFF);
        }
    }
}
