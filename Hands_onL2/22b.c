/*
============================================================================
Name : 22b.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.    
Date: 20/09/2024
============================================================================
*/


#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <sys/time.h>  
#include <unistd.h>    
#include <stdlib.h>
#include <stdio.h>

void main()
{
    char buff[100];
    char *filepath = "./22_fifo";
    
    int fd = open(filepath, O_NONBLOCK | O_WRONLY);

    if (fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    int wb = write(fd, "Hello there...", 14);

    if (wb == -1)
        perror("Error :");

    close(fd);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 22b.c -o ./22b
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./22b


========================================================================================================
*/
