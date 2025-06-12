#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/devicetree.h>

#include "disco_spi.h"
#include "disco_adc.h"

#include "acquisition.h"
#include "demux.h"

struct k_timer sampling_timer;
uint32_t adc_buffer[3] = {0, 0, 0};

volatile bool flag_sample = false;
void sampling_handler(struct k_timer *dummy)
{
    flag_sample = true;
}

int setup_acquisition(void)
{
    setup_adc_sequence();

    k_timer_init(&sampling_timer, sampling_handler, NULL);
    k_timer_start(&sampling_timer, K_USEC(INTERVAL), K_USEC(INTERVAL));
    return 0;
}

int do_acquisition_work(void)
{
    if(!flag_sample)
    {
        return 0;
    }

    flag_sample = false;
    int err = 0;
    float_t dl_fpc = 0.;
    // err |= write_spi0();
    err |= write_spi1();
    err |= read_adc_sequence(adc_buffer);
    err |= demux(adc_buffer[0], adc_buffer[1], adc_buffer[2], &dl_fpc);
    printf("%d\n", (uint16_t)(dl_fpc*1.e9));
    // printf("%d, %d, %d\n", (uint16_t)adc_buffer[0], (uint16_t)adc_buffer[1], (uint16_t)adc_buffer[2]);
    return 0;
}