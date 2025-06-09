#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/devicetree.h>

void sampling_timer_handler(struct k_timer *dummy)
{

}

void adc_work_handler(struct k_work *work)
{
    uint16_t adc_value;
    read_adc_value(&adc_value);
    fftInput[current_index] = (float32_t)adc_value;
    current_index = (current_index + 1) % FFT_SIZE;
}