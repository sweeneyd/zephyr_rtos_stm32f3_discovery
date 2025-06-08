#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#include "disco_spi.h"

struct device *const spi_dev = DEVICE_DT_GET(SPI_DEV_NODE);

struct spi_config spi_dev_cfg0 = {
	.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) |
				 SPI_TRANSFER_MSB,
	.frequency = 8000000,
	.cs = {
        .gpio = SPI_CS_GPIOS_DT_SPEC_GET(SPI_CS0),
        .delay = 0,
	},
};

struct spi_config spi_dev_cfg1 = {
	.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) |
				 SPI_TRANSFER_MSB,
	.frequency = 8000000,
	.cs = {
        .gpio = SPI_CS_GPIOS_DT_SPEC_GET(SPI_CS1),
        .delay = 0,
	},
};

static struct spi_buf bufs[] = {
        {
                .buf = (uint8_t *)"Hello, Zephyr",
                .len = 13
        },
};

static struct spi_buf_set tx = {
        .buffers =  bufs,
        .count = 1
};

int write_spi0(void)
{
    int err = 0;
    err |= spi_write(spi_dev, &spi_dev_cfg0, &tx);
    return err;
}

int write_spi1(void)
{
    int err = 0;
    err |= spi_write(spi_dev, &spi_dev_cfg1, &tx);
    return err;
}