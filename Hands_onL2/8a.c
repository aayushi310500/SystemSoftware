/*
============================================================================
Name : 8a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using signal system call to catch the following signals.
              a. SIGSEGV
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>

void signalHandler(int signal_num){
    printf("Caught Signal with signal number as : %d\n",signal_num);
    printf("Array index out of bounds occurred.\n");
    exit(1);
}
  
int main(){
    signal(SIGSEGV, signalHandler);
int arr[2]={1,2};
int var= arr[1000000];

    // this will not be printed 
    printf("Testing\n");
    return 0;
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Caught Signal with signal number as : 11
Array index out of bounds occurred.
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
