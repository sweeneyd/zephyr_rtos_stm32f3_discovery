#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/util.h>

#include "disco_adc.h"

#if !DT_NODE_EXISTS(DT_PATH(zephyr_user)) || \
	!DT_NODE_HAS_PROP(DT_PATH(zephyr_user), io_channels)
#error "No suitable devicetree overlay specified"
#endif

#define DT_SPEC_AND_COMMA(node_id, prop, idx) \
	ADC_DT_SPEC_GET_BY_IDX(node_id, idx),

/* Data of ADC io-channels specified in devicetree. */
static const struct adc_dt_spec adc_channels[] = {
	DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user), io_channels,
			     DT_SPEC_AND_COMMA)
};

static uint16_t buf;
static struct adc_sequence sequence = {
    .buffer = &buf,
    /* buffer size in bytes, not number of samples */
    .buffer_size = sizeof(buf),
};

int setup_adc_sequence()
{
	int err = 0;

	/* Configure channels individually prior to sampling. */
	for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) 
    {
		while(!adc_is_ready_dt(&adc_channels[i]));
		err |= adc_channel_setup_dt(&adc_channels[i]);
	}

    return err;
}

int read_adc_sequence(uint32_t *data_buffer)
{
	int err = 0;

    for (size_t i = 0U; i < ARRAY_SIZE(adc_channels); i++) 
    {
        (void)adc_sequence_init_dt(&adc_channels[i], &sequence);
        err |= adc_read_dt(&adc_channels[i], &sequence);
        data_buffer[i] = (int32_t)((int16_t)buf);
    
    }
    
    return err;
}