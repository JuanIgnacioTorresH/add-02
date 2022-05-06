#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    printf("add-02");

    adc_init ();

    adc_gpio_init(26);
    adc_select_input(0);

    while (1) {
        const float tensionref = 3.3f / (1 << 12);
        uint16_t temperature = adc_read();
        printf("Raw Value: 0x%03x, Voltage: %.2f V, Temperatura: %.2f\n ", temperature, temperature * tensionref, (temperature * tensionref)/0,01);
        sleep_ms (500);
    
    }
}


