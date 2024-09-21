/*
============================================================================
Name : 23.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.    
Date: 20/09/2024
============================================================================
*/

#include <unistd.h>    
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>    


void main()
{
    char *filename = "23_fifo";
     mkfifo(filename, 0666);

  
        long long max_files = sysconf(_SC_OPEN_MAX);

        if (max_files == -1)
            perror("Error :");
        else
            printf("Maximum number of files that can be opened is: %lld\n", max_files);

        long long size_of_Pipe = pathconf(filename, _PC_PIPE_BUF);

        if (size_of_Pipe == -1)
            perror("Error :");
        else
            printf("Maximum size of pipe: %lld\n", size_of_Pipe);
   
}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 23.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 4096
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
