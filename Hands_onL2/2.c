
/*
============================================================================
Name : 2.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to print the system resource limits. Use getrlimit system call.
Date: 19/09/2024
============================================================================
*/

#include <sys/resource.h>
  #include<stdio.h>
 struct rlimit rlim;

void print_(int resource,char* resource_name){
 if (getrlimit(resource, &rlim) == -1)
{
 perror("error:");
}
else{
printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
printf("%s Limits:\n", resource_name);
        printf("Soft Limit: ");
        if (rlim.rlim_cur == RLIM_INFINITY)
            printf("Unlimited\n");
        else
            printf("%ld\n", (long)rlim.rlim_cur);
            
        printf("Hard Limit: ");
        if (rlim.rlim_max == RLIM_INFINITY)
            printf("Unlimited\n");
        else
            printf("%ld\n", (long)rlim.rlim_max);
    } 
}


int main()
{
    print_(RLIMIT_CPU, "CPU Time");// RLIMIT_CPU = Amount of CPU time that the process can consume
    print_(RLIMIT_FSIZE, "File Size");//RLIMIT_FSIZE = Maximum size of files that  the  process  may  create
    print_(RLIMIT_DATA, "Data Segment Size");//Maximum size of the process's data segment
    print_(RLIMIT_STACK, "Stack Size");//RLIMIT_STACK = Maximum  size of the process stack
    print_(RLIMIT_CORE, "Core File Size"); // RLIMIT_CORE =  Max size of a core file
    print_(RLIMIT_NOFILE, "Number of Open Files");// RLIMIT_NOFILE = specifies a value one greater than the maximum file descriptor number that can be opened by this process
    print_(RLIMIT_AS, "Address Space Limit");// RLIMIT_AS = This  is  the maximum size of the process's virtual memory.
    print_(RLIMIT_NPROC, "Number of Processes");//RLIMIT_NPROC = Limit on the number of threads
    print_(RLIMIT_MEMLOCK, "Locked Memory");//RLIMIT_MEMLOCK = Maximum number of bytes of memory that may be locked into RAM
    print_(RLIMIT_NICE, "Process's Nice value");//RLIMIT_NICE = Ceiling of the process's nice value
    print_(RLIMIT_MSGQUEUE,"Bytes in Message Queues");// RLIMIT_MSGQUEUE = Maximum number of bytes that can be allocated for POSIX message queues
    print_(RLIMIT_MEMLOCK, "Limit on the number of virtual pages resident in the RAM");//RLIMIT_LOCKS -> Maximum number of locks that a process may establish
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
ayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 2.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
------------------------------------------------------------------------------------------------------------------------------------------
CPU Time Limits:
Soft Limit: Unlimited
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
File Size Limits:
Soft Limit: Unlimited
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
Data Segment Size Limits:
Soft Limit: Unlimited
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
Stack Size Limits:
Soft Limit: 8388608
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
Core File Size Limits:
Soft Limit: 0
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
Number of Open Files Limits:
Soft Limit: 1024
Hard Limit: 1048576
------------------------------------------------------------------------------------------------------------------------------------------
Address Space Limit Limits:
Soft Limit: Unlimited
Hard Limit: Unlimited
------------------------------------------------------------------------------------------------------------------------------------------
Number of Processes Limits:
Soft Limit: 30401
Hard Limit: 30401
------------------------------------------------------------------------------------------------------------------------------------------
Locked Memory Limits:
Soft Limit: 1005785088
Hard Limit: 1005785088
------------------------------------------------------------------------------------------------------------------------------------------
Process's Nice value Limits:
Soft Limit: 0
Hard Limit: 0
------------------------------------------------------------------------------------------------------------------------------------------
Bytes in Message Queues Limits:
Soft Limit: 819200
Hard Limit: 819200
------------------------------------------------------------------------------------------------------------------------------------------
Limit on the number of virtual pages resident in the RAM Limits:
Soft Limit: 1005785088
Hard Limit: 1005785088
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
