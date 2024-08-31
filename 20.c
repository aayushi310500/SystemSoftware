/*
============================================================================
Name : 20.c
Author : Prajapati Aayushi Sadashivbhai
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include <sys/resource.h>
int main(){
   int priority = getpriority(PRIO_PROCESS, 0);
    if (priority <0 ) {
        perror("Error:");
    }

    printf("priority before:  %d\n", priority);
    nice(10);
    int priority1 = getpriority(PRIO_PROCESS, 0);

    printf("priority after updating with nice command: %d\n",priority1);
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc nice_p20.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
priority before:  0
priority after updating with nice command: 10

=============================================================================*/
