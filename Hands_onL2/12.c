/*
============================================================================
Name : 12.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
              the parent process from the child process.
Date: 20/09/2024
============================================================================
*/

#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }
}
