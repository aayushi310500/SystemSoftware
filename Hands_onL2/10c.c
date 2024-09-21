/*
============================================================================
Name : 10c.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using sigaction system call to catch the following signals.
              c. SIGFPE
Date: 19/09/2024
============================================================================
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 
#include<stdlib.h>

void signalHandler(int signal_num)
{
    printf("Caught signal SIGFPE (%d)\n", signal_num);
    exit(1);
}

void main()
{
    struct sigaction action;
    
    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    int status = sigaction(SIGFPE, &action, NULL);
    
    if (status == -1)
        perror("Error while setting signal handler!");
    else{
        int a = 5, b = 0;
        int c = a / b;
        printf("Testing\n");
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 10c.c
\aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Caught signal SIGFPE (8)
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
