/*
============================================================================
Name : 25.c
Author : Prajapati Aayushi Sadashivbhai
Description : C Write a program to create three child processes. The parent should wait for a particular child (use 
              waitpid system call).
Date: 28th Aug, 2024.
============================================================================
*/




#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/wait.h>

int main(){
    int status;
    int pid1,pid2,pid3,pid; 
    if(!(pid1=fork())){
        printf("Process pid1 pid: %d started,  sleep for 1 second.\n", getpid());
        sleep(1);
        printf("Process pid1 pid: %d completed.\n", getpid());
    }
    else{
        if(!(pid2=fork())){
            printf("Process pid2 pid: %d started,  sleep for 5 second.\n", getpid());
            sleep(5);
            printf("Process pid2 pid: %d completed.\n", getpid());
        }
        else{
            if(!(pid3=fork())){
                printf("Process pid3 pid: %d started,  sleep for 10 second.\n", getpid());
                sleep(10);
                printf("Process pid3 pid: %d completed.\n", getpid());
            }
            else{
                printf("Parent process pid: %d waiting for process pid2 pid: %d.\n", getpid(), pid2);
                waitpid(pid1, NULL, 0);
                printf("Process pid1 pid: %d has finished.\n", pid1);

                waitpid(pid2, NULL, 0);
                printf("Process pid2 pid: %d has finished.\n", pid2);

                waitpid(pid3, NULL, 0);
                printf("Process pid3 pid: %d has finished.\n", pid3);

                printf("All child processes have completed. Parent process pid: %d terminating.\n", getpid());
            }
        }
    }
    return 0;
}












/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc waitpid_p25.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
Process pid1 pid: 22013 started,  sleep for 1 second.
Process pid2 pid: 22014 started,  sleep for 5 second.
Parent process pid: 22012 waiting for process pid2 pid: 22014.
Process pid3 pid: 22015 started,  sleep for 10 second.
Process pid1 pid: 22013 completed.
Process pid1 pid: 22013 has finished.
Process pid2 pid: 22014 completed.
Process pid2 pid: 22014 has finished.
Process pid3 pid: 22015 completed.
Process pid3 pid: 22015 has finished.
All child processes have completed. Parent process pid: 22012 terminating.

=============================================================================*/
