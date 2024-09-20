/*
============================================================================
Name : 8b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using signal system call to catch the following signals.
              d. SIGALRM (use alarm system call)
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void signalHandler(int signal_num){
    printf("Caught Signal with signal number as : %d\n",signal_num);
    printf("Alarm signal caught! Time's up!\n");
    exit(1);
}

int main(int argc, char *argv[]){
    signal(SIGALRM, signalHandler);
    alarm(2);
    // this will not be printed if argv[1]=='1'
    while(1){}//for signal catching
    printf("Testing\n");
    return 0;
}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 8d.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Caught Signal with signal number as : 14
Alarm signal caught! Time's up!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/
