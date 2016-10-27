#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include "mraa.h"

#define CLOCKID CLOCK_REALTIME            //RT clock
#define SIG SIGRTMIN                      //Realtime signal in linux
#define PIN_NUMBER 13

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                       } while (0)

int val = 0;
mraa_gpio_context gpio; 

static void
handler(int sig, siginfo_t *si, void *uc)
{
   val = ~val;
   mraa_gpio_write(gpio, val);
}

int
main(int argc, char *argv[])
{
   timer_t timerid;           //For creating a timer
   struct sigevent sev;       //signal event handler
   struct itimerspec its;     //Timerspec for holding timerval and intervalval
   long long freq_nanosecs = 10;
   sigset_t mask;     
   struct sigaction sa;


   
   gpio = mraa_gpio_init(PIN_NUMBER);
   int n = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
   mraa_gpio_use_mmaped(gpio, 1);


   // Establish handler for timer signal 
   printf("Establishing handler for signal %d\n", SIG);
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = handler;
   sigemptyset(&sa.sa_mask);
   if (sigaction(SIG, &sa, NULL) == -1)
       errExit("sigaction");
   
   sigemptyset(&mask);
   sigaddset(&mask, SIG);
   if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1)    //Unblock signal incase it is blocked already
       errExit("sigprocmask");

   // Create the timer 
   sev.sigev_notify = SIGEV_SIGNAL;                   //Generated when the timer expires
   sev.sigev_signo = SIG;                             //Generate this signal when timer expires
   sev.sigev_value.sival_ptr = &timerid;              
   if (timer_create(CLOCKID, &sev, &timerid) == -1)
       errExit("timer_create");
   printf("timer ID is 0x%lx\n", (long) timerid);

   //Start the timer 
   freq_nanosecs = atoll(argv[2]);
   its.it_value.tv_sec = 0;
   its.it_value.tv_nsec = 100;
   its.it_interval.tv_sec = its.it_value.tv_sec;
   its.it_interval.tv_nsec = its.it_value.tv_nsec;
   if (timer_settime(timerid, 0, &its, NULL) == -1)   //Start timer
        errExit("timer_settime");
   while(1);
   exit(EXIT_SUCCESS);
}
