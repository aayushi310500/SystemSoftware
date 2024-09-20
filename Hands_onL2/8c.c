/*
============================================================================
Name : 8b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a separate program using signal system call to catch the following signals.
              c. SIGFPE
Date: 19/09/2024
============================================================================
*/

#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
#include<stdlib.h>

void signalHandler(int signal_num){
    printf("Caught SIGFPE Signal with signal number as : %d\n",signal_num);
    exit(1);
}

int main(){
	    // catches floating point exceptions
    signal(SIGFPE, signalHandler);
        int a = 5, b = 0;
        int c = a / b;
    

    // this will not be printed if argv[1]=='1'
    printf("Testing\n");
    return 0;
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 8c.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
Caught SIGFPE Signal with signal number as : 8
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
