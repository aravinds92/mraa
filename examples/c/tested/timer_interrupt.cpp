#include "mraa.h"  
#include <sys/time.h>  
#include <iostream>  
#include <fstream>  
#include <unistd.h>  
#include <signal.h>  
#include <string.h>  
  
using namespace std;  
  
struct itimerval timer;  
bool test = false;  
void sigalrm_handler(int signum);  
struct timespec startTime;  
struct timespec endTime;  
  
int main () {  
  cout<<"started"<<endl;  
  timer.it_value.tv_sec = 5;  
  timer.it_value.tv_usec = 0;  
  timer.it_interval.tv_sec = 5;  
  timer.it_interval.tv_usec = 0;  
  
  struct sigaction act;  
  memset(&act, '\0', sizeof(act));  
  act.sa_handler = &sigalrm_handler;  
  sigaction(SIGTERM, &act, NULL);  
  setitimer(ITIMER_REAL, &timer, NULL);  
  
  while(!test){  
  cout<<"working..."<<endl;  
  }  
  cout<<test<<endl;  
}  
void sigalrm_handler(int signum){  
  cout<<"handler executed"<<endl;  
  test = true;  
}  
