### App

```
west build -p always -b stm32f3_disco ./app
west flash
```

```
minicom -D /dev/ttyAMC0
```

## Example Code
- [How perform fast SPI ADC with Timer on NRF52840 and Zephyr](https://devzone.nordicsemi.com/f/nordic-q-a/103730/how-perform-fast-spi-adc-with-timer-on-nrf52840-and-zephyr)
- [Setting a counter in STM32](https://github.com/zephyrproject-rtos/zephyr/discussions/47033)