/*
============================================================================
Name : 9.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<unistd.h>

int main(){
    printf("Ignoring SIGINT (Ctrl+C): SIG_IGN\n");
    printf("ignore: SIG_IGN\n");
    if(signal(SIGINT, SIG_IGN)==SIG_ERR){
       perror("Error: ");
    }
    else{
      sleep(5);
    }
   
    printf(" default SIG_DFL: \n");
     if(signal(SIGINT, SIG_DFL)==SIG_ERR){
       perror("Error: ");
    }
    else{
      sleep(5);
    }
    while(1);
}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 9.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Ignoring SIGINT (Ctrl+C): SIG_IGN
ignore: SIG_IGN
^C^C^C^C^C^C^C^C^C^C^C default SIG_DFL: 
^C
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
