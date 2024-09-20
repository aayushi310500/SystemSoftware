/*
============================================================================
Name : 8f.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using signal system call to catch the following signals.
              f. SIGVTALRM (use setitimer system call)
Date: 19/09/2024
============================================================================
*/

#include <sys/time.h> 
#include <signal.h>   
#include <unistd.h>   
#include <stdio.h>   
#include<stdlib.h>

void signalHandler(int signal_num){
    printf("Signal Expired with signal number as : %d\n",signal_num);
    printf("Alarm signal caught! Time's up!\n");
    exit(1);
}

void main()
{
    signal(SIGVTALRM, signalHandler);
    struct itimerval timer;

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error:");
    }

  while (1) {
      //  pause();  // Suspend the program until a signal is caught
    }

}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 8f.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Signal Expired with signal number as : 26
Alarm signal caught! Time's up!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
