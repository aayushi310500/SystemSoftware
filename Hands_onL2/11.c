/*
============================================================================
Name : 11.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
             use sigaction system call.
Date: 19/09/2024
============================================================================
*/


#include <signal.h> 
#include <stdio.h> 
#include <unistd.h> 

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
}

void main()
{
    int status;
    struct sigaction action;

    // Ignore SIGINT
    printf("Ignoring SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);


    // Provide custom handler
    printf("Handling SIGINT for 5 seconds!\n");
    action.sa_handler = signalHandler;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error:");
    else
        sleep(5);

    // Setting default handler
    printf("Default action for SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_DFL;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error:");
    else
        sleep(5);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Ignoring SIGINT for 5 seconds!
^CHandling SIGINT for 5 seconds!
^CCaught signal SIGINT (2)
Default action for SIGINT for 5 seconds!


========================================================================================================
*/
