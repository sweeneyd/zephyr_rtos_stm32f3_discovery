#include <stdio.h>
#include <stdlib.h>

#include "disco_spi.h"
#include "disco_adc.h"

int main() {

    setup_adc_sequence();

    int err=0;
    uint32_t adc_buffer[2] = {0, 0};

    while (true) {
        err |= write_spi0();
        err |= write_spi1();
        err |= read_adc_sequence(adc_buffer);
        printf("%d, %d\n", (uint16_t)adc_buffer[0], (uint16_t)adc_buffer[1]);
        k_sleep(K_MSEC(250));
    }

    return 0;
}