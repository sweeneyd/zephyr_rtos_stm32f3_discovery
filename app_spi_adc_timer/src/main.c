#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/devicetree.h>

#include "acquisition.h"

int main()
{

    setup_acquisition();

    while(true)
    {
        do_acquisition_work();
    }

    return 0;
}