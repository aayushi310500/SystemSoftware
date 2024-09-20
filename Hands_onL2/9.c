/*
============================================================================
Name : 9.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<unistd.h>

int main(){
    printf("ignore: SIG_IGN\n");
    signal(SIGINT, SIG_IGN);
    sleep(10);
   
    printf(" default SIG_DFL: \n");
    signal(SIGINT, SIG_DFL);
    while(1);
}

/*
========================================================================================================
OUTPUT:
========================================================================================================



========================================================================================================
*/
