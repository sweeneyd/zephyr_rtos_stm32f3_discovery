#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "demux.h"

static volatile float_t gain0 = 1.;
static volatile float_t offset0 = 0.;

static volatile float_t gain1 = 1.;
static volatile float_t offset1 = 0.;

static volatile float_t gain2 = 1.;

static volatile float_t z0 = 0.;
static volatile float_t z_prev = 0.;

static volatile float_t z1 = 0.;
static volatile float_t z1_prev = 0.;

static volatile float_t z2 = 0.;
static volatile float_t z2_prev = 0.;
static volatile float_t z2_z0 = 0.;

static volatile float_t inv_tan = 0.;
static volatile float_t inv_sin = 0.;

int setup_demux()
{
    return 0;
}

int demux(uint32_t ch0_data, uint32_t ch1_data, uint32_t ch2_data, float_t *out)
{
    float_t compensation_ratio = gain2/(float_t)ch2_data;
    float_t A0 = (compensation_ratio*(float_t)ch0_data - offset0)/gain0;
    float_t A1 = (compensation_ratio*(float_t)ch1_data - offset1)/gain1;
    float_t R = A0 / A1;
    z1 = atan(inv_tan - inv_sin*R);
    z2_z0 = atan(R*inv_sin - inv_tan);
    z2 = z2_z0 - z0;

    if(abs(z2_z0) > abs(z1))
    {
        z_prev += z1 - z1_prev;
    }

    else
    {
        z_prev += z2 - z2_prev;
    }
    
    *out = z_prev;
    z1_prev = z1;
    z2_prev = z2;

    return 0;
}