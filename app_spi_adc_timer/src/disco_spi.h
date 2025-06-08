#include <stdio.h>
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SPI_DEV_NODE DT_NODELABEL(spi1)
#define SPI_CS0 DT_NODELABEL(spitest0)
#define SPI_CS1 DT_NODELABEL(spitest1)

int write_spi0(void);
int write_spi1(void);