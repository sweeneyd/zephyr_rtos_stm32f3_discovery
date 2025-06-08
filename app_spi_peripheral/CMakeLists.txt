
cmake_minimum_required(VERSION 3.13.0)

set(BOARD stm32f3_disco)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(app_spi_peripheral)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
