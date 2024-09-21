/*
============================================================================
Name : 13b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
              will send the signal (using kill system call). Find out whether the first program is able to catch
              the signal or not.
Date: 20/09/2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int pid;

    //pid from first program
    printf("Enter the PID of the first program: ");
    scanf("%d", &pid);

    // Send SIGSTOP signal to the first program
    if (kill(pid, SIGSTOP) == -1) {
        perror("Error: ");
        exit(1);
    }

    printf("SIGSTOP signal sent to process %d\n", pid);

    while(1){}

    return 0;
}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./13b
Enter the PID of the first program: 12287
SIGSTOP signal sent to process 12287

^C
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/    
