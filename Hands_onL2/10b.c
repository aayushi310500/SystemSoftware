/*
============================================================================
Name : 10b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using sigaction system call to catch the following signals.
              b. SIGINT
Date: 19/09/2024
============================================================================
*/

#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 
#include<stdlib.h>

void signalHandler(int signal_num)
{
    printf("\nCaught Signal with signal number as : %d\n",signal_num);
    printf("ctrl+c is encountered\n");
    exit(1);
}

void main()
{
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

  int status=sigaction(SIGINT, &action, NULL);
  sleep(10);
    
    if (status== -1)
        perror("Error :");
    else
        {sleep(5);
        printf("No ctrl+c caught.\n");}
}



/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 10b.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
^C
Caught Signal with signal number as : 2
ctrl+c is encountered
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================

*/
