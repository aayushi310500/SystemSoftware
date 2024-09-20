/*
============================================================================
Name : 1b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
              10micro second
              b. ITIMER_VIRTUAL
Date: 19/09/2024
============================================================================
*/

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include<string.h>

 void signalHandler(int signal_num){
    printf("Signal Expired with signal number as : %d\n",signal_num);
}

void main(int argc, char *argv[])
{

    struct itimerval timer;
   
    signal(SIGVTALRM, signalHandler);
    if (argc != 2)
    {
        printf("Pass s for 10s timer or ms for 10ms timer\n");

    }

    if (strcmp(argv[1], "s") == 0)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if (strcmp(argv[1], "ms") == 0)
    {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    int status = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (status == -1)
        { perror("Error :");
          }

    while(1){
     for (int i = 0; i < 100000; i++);
    }
  }
  
  

/*
========================================================================================================
OUTPUT:
========================================================================================================
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 1b.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out ms
Signal Expired with signal number as : 26
^C
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out s
Signal Expired with signal number as : 26
^C
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
