#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/devicetree.h>

#include "disco_spi.h"
#include "disco_adc.h"

// int main() {

//     setup_adc_sequence();

//     int err=0;
//     uint32_t adc_buffer[2] = {0, 0};

//     while (true) {
//         err |= write_spi0();
//         err |= write_spi1();
//         err |= read_adc_sequence(adc_buffer);
//         printf("%d, %d\n", (uint16_t)adc_buffer[0], (uint16_t)adc_buffer[1]);
//         k_sleep(K_MSEC(10));
//     }

//     return 0;
// }

#define INTERVAL 50

struct k_timer sampling_timer;

volatile bool flag_sample = false;
void sampling_handler(struct k_timer *dummy)
{
    flag_sample = true;
}

int main()
{
    setup_adc_sequence();
    int err = 0;
    uint32_t adc_buffer[2] = {0, 0};

    k_timer_init(&sampling_timer, sampling_handler, NULL);
    k_timer_start(&sampling_timer, K_USEC(INTERVAL), K_USEC(INTERVAL));

    while(true)
    {
        while(!flag_sample){};

        flag_sample = false;
        err |= write_spi0();
        err |= write_spi1();
        err |= read_adc_sequence(adc_buffer);
        printf("%d, %d\n", (uint16_t)adc_buffer[0], (uint16_t)adc_buffer[1]);
        
    }

    return 0;
}