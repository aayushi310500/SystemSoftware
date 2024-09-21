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
    int pid1 = fork();

    if (pid1 == -1)
        perror("Error :");
    else if (!pid1)
    {
        // Child
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        int killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error :");
    }
    else
    {
        // Parent 
        while (1);//keep running unlsess it will get killed
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Child PID: 12819
Parent PID: 12818
Successfully killed parent!
Killed
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ Child now exiting!


========================================================================================================
*/
