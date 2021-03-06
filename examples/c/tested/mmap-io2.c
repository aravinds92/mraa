/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
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

#include "stdio.h"
#include <unistd.h>

#include "mraa.h"


#include <stdio.h>
#include <time.h>

int
main(int argc, char** argv)
{
    //! [Interesting]
    //fprintf(stdout, "hello mraa\n Version: %s\n", mraa_get_version());
    mraa_gpio_context gpio;
    struct timespec tim, tim2;
    gpio = mraa_gpio_init(8);
    int n = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
    mraa_gpio_use_mmaped(gpio, 1);
    tim.tv_sec = 0;
    tim.tv_nsec = 500;



    for (;;) {
        //mraa_gpio_write(gpio, 1);
        printf("On\n");
        if(nanosleep(&tim , NULL) < 0 )   
        {
            printf("Nano sleep system call failed \n");
            return -1;
        }
        //mraa_gpio_write(gpio, 0);
        printf("Off\n");
        //nanosleep(&tim , &tim2);
    }
    //! [Interesting]
}
