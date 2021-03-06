/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2014, 2015 Intel Corporation.
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
#include "mraa.h"
 #include <string.h>
#define num_char 3


int main(int argc, char** argv)
{
    mraa_uart_context uart;
    uart = mraa_uart_init(0);
    mraa_uart_set_baudrate(uart,9600);

    if (uart == NULL) {
        fprintf(stderr, "UART failed to setup\n");
        return EXIT_FAILURE;
    }

    char* buffer;

    //buffer = (char*)(malloc(num_char));
    //printf("Result of expression:%d\n",sizeof(char)*num_char);
    memset(buffer, '\0', sizeof(buffer));
    strcpy(buffer,"bad");
    buffer[3] = num_char;
    //printf("%d\n",sizeof(buffer));
    //printf("%c\n",buffer[3]);
    mraa_uart_write(uart, &buffer[3], 1);
    while(1)
    {
        mraa_uart_write(uart, buffer, num_char);
    }

    mraa_uart_stop(uart);

    mraa_deinit();

    return EXIT_SUCCESS;
}
