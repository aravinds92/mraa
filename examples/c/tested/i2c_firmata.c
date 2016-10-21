/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2016 Intel Corporation.
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

#include <mraa.h>
#include <sys/time.h>
#include "intel_edison_fab_c.h"


int
main(int argc, char** argv)
{
    mraa_init();
    mraa_add_subplatform(MRAA_GENERIC_FIRMATA, "/dev/ttyACM0");
    uint8_t address = 8;				//Slave address as set in the arduino code
    mraa_i2c_context i2c;
    i2c = mraa_i2c_init(6);				//Bus number for A4-A5 pins
    //mraa_intel_edison_i2c_freq(i2c, MRAA_I2C_HIGH);
    mraa_i2c_address(i2c, address);
    unsigned long new_time=0;
   
    char data[10];
    
    
    /*while(1)			//Write
    {
    	mraa_i2c_write_byte(i2c, 'a');
    	printf("Written\n");
    	sleep(1);
    }*/
    /*while(1)		//Read
    {
    	mraa_i2c_read(i2c, data, 1);
    	printf("%s\n",data);
    	usleep(100);
    }*/

    printf("Average time:%lu\n",new_time);
}
