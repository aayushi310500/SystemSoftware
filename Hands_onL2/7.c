/*
============================================================================
Name : 7.c
Author : Prajapati Aayushi Sadashivbhai
Description :  Write a simple program to print the created thread ids.
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int t=0;

void* printPid(void* vargp){
    printf("Thread id = %d and thread number =%d \n",getpid(),++t);
}

int main(){
    int n=3;
    pthread_t t;

    for(int i=0;i<n;i++){
        pthread_create(&t, NULL, printPid, NULL);
    }

    pthread_exit(NULL);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 7.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Thread id = 9737 and thread number =1 
Thread id = 9737 and thread number =2 
Thread id = 9737 and thread number =3 
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

========================================================================================================
*/
