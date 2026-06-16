#include <stdio.h>
#include "pico/stdlib.h"

int main(void) {

    stdio_init_all();
    
    sleep_ms(1000);

    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);
    
    gpio_init(7);
    gpio_set_dir(7, GPIO_OUT);
    
    gpio_init(8);
    gpio_set_dir(8, GPIO_OUT);

    
    gpio_init(20);
    gpio_set_dir(20, GPIO_IN);

    gpio_init(21);
    gpio_set_dir(21, GPIO_IN);

    gpio_init(22);
    gpio_set_dir(22, GPIO_IN);

    bool estado_anterior_21 = 1; 
    bool led_7_encendido = 0;

    while (true) {
        
        if (gpio_get(20) == 0) {
            gpio_put(6, 1);
        } else {
            gpio_put(6, 0); 
        }

            led_7_encendido = !led_7_encendido; 
            gpio_put(7, led_7_encendido);
            sleep_ms(50); 
        

        if (gpio_get(22) == 0) {
            gpio_put(8, 1);
            sleep_ms(250);
            gpio_put(8, 0);
            sleep_ms(250); 
        }
        
        sleep_ms(10);
    }
    return 0;
}