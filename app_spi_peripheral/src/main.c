#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SPI_DEV_NODE DT_NODELABEL(spi1)
#define SPI_CS0 DT_NODELABEL(spitest0)
#define SPI_CS1 DT_NODELABEL(spitest1)

struct device *const spi_dev = DEVICE_DT_GET(SPI_DEV_NODE);

const struct spi_config spi_dev_cfg0 = {
	.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) |
				 SPI_TRANSFER_MSB,
	.frequency = 8000000,
	.cs = {
        .gpio = SPI_CS_GPIOS_DT_SPEC_GET(SPI_CS0),
        .delay = 0,
	},
};

const struct spi_config spi_dev_cfg1 = {
	.operation = SPI_OP_MODE_MASTER | SPI_WORD_SET(8) |
				 SPI_TRANSFER_MSB,
	.frequency = 8000000,
	.cs = {
        .gpio = SPI_CS_GPIOS_DT_SPEC_GET(SPI_CS1),
        .delay = 0,
	},
};

int main() {

    struct spi_buf bufs[] = {
            {
                    .buf = (uint8_t *)"Hello, Zephyr",
                    .len = 13
            },
    };

    struct spi_buf_set tx = {
            .buffers =  bufs,
            .count = 1
    };
    // const struct spi_dt_spec spidev_dev = SPI_DT_SPEC_GET(DT_NODELABEL(spidev), SPI_OP, 0);

    while (true) {
        printf("Writing to SPI0...\n");
        spi_write(spi_dev, &spi_dev_cfg0, &tx);

        printf("Writing to SPI1...\n");
        spi_write(spi_dev, &spi_dev_cfg1, &tx);

        k_sleep(K_MSEC(250));
    }

    return 0;
}