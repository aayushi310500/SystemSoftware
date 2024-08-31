/*
============================================================================
Name : 21.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program, call fork and print the parent and child process id.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <unistd.h>

int main(){
	//printf("first line::");
	int id = fork();
	//printf("%d\n",id);
        switch(id){
            case -1:
               perror("fork");
               break;
           case 0:
               printf("Child is running..\n");
               printf("chlild pid : %d , parent pid %d \n",getpid(),getppid());
               printf("Child exiting.\n");
               break;
           default:
               printf("Parent is running..\n");
               printf("parent pid %d  child pid %d\n", getpid(), id);
               puts("Parent exiting.\n");
               break;

}	
}

/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc ppid_21.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
Parent is running..
parent pid 16428  child pid 16429
Parent exiting.

Child is running..
chlild pid : 16429 , parent pid 16428 
Child exiting.


=============================================================================*/
