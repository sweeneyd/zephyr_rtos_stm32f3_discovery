#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159265359

int setup_demux();
int demux(uint32_t ch0_data, uint32_t ch1_data, uint32_t ch2_data, float_t *out);
