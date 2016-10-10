#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include "mraa.h"


static signal_recv_count;
int value = 0;
//int value2 = 0;
mraa_gpio_context gpio[4];
struct itimerval timer[4]={0};

void sigalrm_handler(int signum)
{
  mraa_gpio_write(gpio[0], value);
  value = ~value;
  printf("Value in struct:%lu\n",timer[0].it_value.tv_sec);
}


int main()
{
 
  char a[200];
  /* Initial timeout value */
  timer[0].it_value.tv_sec = 1;

  /* We want a repetitive timer */
  //timer[0].it_interval.tv_sec = 1;

  /* Initial timeout value */
  //timer[1].it_value.tv_sec = 1;

  /* We want a repetitive timer */
  //timer[1].it_interval.tv_sec = 1;


  //Initialize GPIO pin for toggling
  gpio[0] = mraa_gpio_init(2);
  mraa_gpio_use_mmaped(gpio[0], 1);

  gpio[1] = mraa_gpio_init(3);
  mraa_gpio_use_mmaped(gpio[1], 1);


  /* Register Signal handler
   * And register for periodic timer with Kernel*/
  signal(SIGALRM, &sigalrm_handler);
  setitimer(ITIMER_REAL, &timer[0], NULL);
  //setitimer(ITIMER_REAL, &timer[1], NULL);
  read(2, &a, 199);

}
