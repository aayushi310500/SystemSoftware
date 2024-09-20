/*
============================================================================
Name : 6.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a simple program to create three threads.
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int t=0;

void* print_(void* vargp){
    printf("Thread number = %d\n", ++t);
}

int main(){
    int n=3;
    pthread_t t;

    for(int i=0;i<n;i++){
        pthread_create(&t, NULL, print_, NULL);
    }

    pthread_exit(NULL);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Thread number = 2
Thread number = 1
Thread number = 3
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/


