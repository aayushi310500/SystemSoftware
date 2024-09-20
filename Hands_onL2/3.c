/*
============================================================================
Name : 3.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 19/09/2024
============================================================================
*/


#include<stdio.h>
#include<sys/resource.h>

int main(){
    struct rlimit rlim;
    printf("=======================================================	\n");
    getrlimit(RLIMIT_FSIZE, &rlim);
    printf("RLIMIT_FSIZE :\n");
    printf("soft limit : %ld\n", rlim.rlim_cur);
    printf("hard limit : %ld\n", rlim.rlim_max);

    rlim.rlim_cur = 50;
    //rlim.rlim_max=100;
    setrlimit(RLIMIT_FSIZE, &rlim);
    getrlimit(RLIMIT_FSIZE, &rlim);
    printf("after setrlimit  RLIMIT_FSIZE :\n");
    printf("soft limit : %ld\n", rlim.rlim_cur);
    printf("hard limit  : %ld\n", rlim.rlim_max);
    printf("========================================================\n");
    return 0;
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 3.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
=======================================================	
RLIMIT_FSIZE :
soft limit : -1
hard limit : -1
after setrlimit  RLIMIT_FSIZE :
soft limit : 50
hard limit  : -1
========================================================


========================================================================================================
*/
