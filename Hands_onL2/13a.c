/*
============================================================================
Name : 13a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
Date: 20/09/2024
============================================================================
*/

#include <signal.h> 
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void signalHandler(int sig_num)
{
    printf("Received SIGSTOP signal! with signal num : %d\n",sig_num);
    exit(1);
}

void main()
{
    printf("Process ID: %d\n", getpid());
    printf("Waiting for SIGSTOP or SIGCONT signal...\n");

  
    while (1) {
        pause();  // Suspend program execution until a signal is received
    }
   while(1){}
    
  }
  
  
  
/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./13
Process ID: 12287
Waiting for SIGSTOP or SIGCONT signal...


[1]+  Stopped                 ./13
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$


========================================================================================================
*/    
