/*
============================================================================
Name : 10a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using sigaction system call to catch the following signals.
              a. SIGSEGV
Date: 19/09/2024
============================================================================
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 
#include<stdlib.h>

void signalHandler(int signal_num)
{
     printf("Caught Signal with signal number as : %d\n",signal_num);
    printf("Array index out of bounds occurred. Program will now exit.\n");
    exit(1);
}

void main()
{
    struct sigaction action;
    
    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    int status=sigaction(SIGSEGV, &action, NULL);
    if(status==-1){
     perror("Error: ");
    }
    else{
    int arr[2]={1,2};
    int var= arr[1000000];

    // this will not be printed 
    printf("Testing\n");
    }
    
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 10a.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Caught Signal with signal number as : 11
Array index out of bounds occurred. Program will now exit.

========================================================================================================
*/


