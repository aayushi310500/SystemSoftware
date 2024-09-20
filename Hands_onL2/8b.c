/*
============================================================================
Name : 8b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using signal system call to catch the following signals.
              b. SIGINT
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h> // for sleep

void signalHandler(int signal_num){
    printf("\nCaught Signal with signal number as : %d\n",signal_num);
    printf("ctrl+c is encountered\n");
    exit(1);
}

int main(int argc, char *argv[]){
    signal(SIGINT, signalHandler);
    sleep(10);
    printf("No ctrl+c caught.\n");
    return 0;
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 8b.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
^C
Caught Signal with signal number as : 2
ctrl+c is encountered
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
