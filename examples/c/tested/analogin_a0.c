/*
 * Author: Nandkishor Sonar
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <unistd.h>
//! [Interesting]
#include "mraa/aio.h"
#include <sys/time.h>



int
main()
{
    mraa_aio_context* adc_a0;
    adc_a0 = (mraa_aio_context*)malloc(sizeof(mraa_aio_context));
    uint16_t adc_value = 0;
    float adc_value_float = 0.0;
    struct timeval tv, tv_old;
    unsigned long old_time, new_time;
    old_time = 0;

    *adc_a0 = mraa_aio_init(0);
    if (*adc_a0 == NULL) {
        return 1;
    }
    mraa_aio_set_bit(*adc_a0,12);
    

    for (;;) {
        adc_value = mraa_aio_read(*adc_a0);
        adc_value_float = mraa_aio_read_float(*adc_a0);
        gettimeofday(&tv,NULL);
        new_time = tv.tv_usec+tv.tv_sec*1000000;
        fprintf(stdout, "%d\n", adc_value);
        old_time = new_time;
        //usleep(500);
    }

    mraa_aio_close(*adc_a0);

    return MRAA_SUCCESS;
}
//! [Interesting]
