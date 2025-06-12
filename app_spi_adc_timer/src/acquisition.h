#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/devicetree.h>

#include "disco_spi.h"
#include "disco_adc.h"
#include "demux.h"

#define INTERVAL 50

int setup_acquisition(void);
int do_acquisition_work(void);
