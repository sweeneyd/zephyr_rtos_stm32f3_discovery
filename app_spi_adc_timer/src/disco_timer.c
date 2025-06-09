#include <zephyr.h>
#include <zephyr/drivers/counter.h>

#include "disco_timer.h"

#define TIMER DT_NODELABEL(counters2)
const struct device *counter_dev = DEVICE_DT_GET(TIMER);

#define GEN_STACK_SIZE   500
#define GEN_PRIORITY     5

K_THREAD_DEFINE(gen_tid, GEN_STACK_SIZE,
                gen_thread, NULL, NULL, NULL,
                GEN_PRIORITY, 0, 0);

void gen_thread(void *arg1, void *arg2, void *arg3){
    ARG_UNUSED(arg1);
    ARG_UNUSED(arg2);
    ARG_UNUSED(arg3);

    if (!device_is_ready(counter_dev)) {
    printk("Error: Counter device %s is not ready\n",
          counter_dev->name);
      return;
    }

    while (1) {
		printk("Thread gen loopeando\n");
		k_sleep(K_MSEC(50));
	}
}