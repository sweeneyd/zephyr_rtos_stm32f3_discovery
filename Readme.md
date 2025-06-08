## Multi-device SPI and Internal ADC setup for STM32F3 Discovery

### Project Manifest
-[Internal ADC](https://github.com/sweeneyd/zephyr_rtos_stm32f3_discovery/tree/main/app_adc)

-[Multi-Device SPI Bit-Bang](https://github.com/sweeneyd/zephyr_rtos_stm32f3_discovery/tree/main/app_bb) with multiple GPIO chip select (CS), MOSI, MISO, and CLK pins 

-[Multi-Device SPI Peripheral](https://github.com/sweeneyd/zephyr_rtos_stm32f3_discovery/tree/main/app_adc) with multiple GPIO chip select (CS) pins 

### STM32F3 Discovery Pinout
![STM32F3 Discovery Pinout](https://github.com/sweeneyd/zephyr_rtos_stm32f3_discovery/blob/main/_misc_/stm32f3_disco_pinout.png)
From https://arm-stm.blogspot.com/p/stm32f3discovery.html

### References
- [Zephyr RTOS profile of stm32f3-disco](https://docs.zephyrproject.org/latest/boards/st/stm32f3_disco/doc/index.html)

- [Nordic Semiconductor Forum: Struggling for several days to get SPI working w/ Zephyr](https://devzone.nordicsemi.com/f/nordic-q-a/96015/struggling-for-several-days-to-get-spi-working-w-zephyr)

-[Golioth IoT Blog: How to Use Generic SPI Devices with Zephyr](https://blog.golioth.io/how-to-use-generic-spi-devices-with-zephyr/)

-[Zephyr RTOS GitHub Forum: spi_transceive weird behaviour #65512](https://github.com/zephyrproject-rtos/zephyr/issues/65512)

-[disposedtrolly GitHub: spi-stm32-zephyr.md](https://gist.github.com/disposedtrolley/f0edbef0e65dbd7b56207e4ffc35c8d1)



### Setup & Installation
-[Zephyr RTOS](https://docs.zephyrproject.org/latest/develop/getting_started/index.html)

```
sudo apt install python3-venv
python3 -m venv ./.venv
source .venv/bin/activate
pip install west
west init .
west update
west zephyr-export
west packages pip --install
cd zephyr
west sdk install
```

### Git Setup

-[GitHub Keygen](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)

```
ssh-keygen -t ed25519 -C "dan.sweeney90@gmail.com"
```