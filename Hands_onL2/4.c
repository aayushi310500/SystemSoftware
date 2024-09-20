/*
============================================================================
Name : 4.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
              system call. Use time stamp counter.
Date: 19/09/2024
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A" (dst));
}

int main(int argc, char const *argv[])
{
    unsigned long long start, end;
    int ppid;
    start = rdtsc();
    for(int i=0;i<100;i++){
        ppid = getppid();
    }
    end = rdtsc();

    printf("Time taken to execute 100 getppid system call is : %f\n",((end-start)/2.09));
    return 0;
}

/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 4.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Time taken to execute 100 getppid system call is : 40293.779904
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/



