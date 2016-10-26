#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include "mraa.h"
#define HIGH 1
#define LOW 0
#define alarm_time 20
static signal_recv_count;
int value = 0;
mraa_gpio_context gpio;
struct itimerval timer={0};

int fp = -1;


void sigalrm_handler(int signum)
{
  write(fp, "a", 1);
}


int main()
{
 
  char a[200];
  
  fp = open("/home/root/test1", O_RDWR);
  printf("%d\n",fp);
  /* Initial timeout value */
  timer.it_value.tv_usec = alarm_time;

  /* We want a repetitive timer */
  timer.it_interval.tv_usec = alarm_time;

  //Initialize GPIO pin for toggling
  gpio = mraa_gpio_init(8);
  mraa_gpio_use_mmaped(gpio, 1);


  /* Register Signal handler
   * And register for periodic timer with Kernel*/
  signal(SIGALRM, &sigalrm_handler);
  setitimer(ITIMER_REAL, &timer, NULL);
  
  read(2, &a, 199);

}
