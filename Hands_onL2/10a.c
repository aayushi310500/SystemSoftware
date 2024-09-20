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

    int staus=sigaction(SIGSEGV, &action, NULL);
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
