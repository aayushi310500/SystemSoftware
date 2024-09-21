/*
============================================================================
Name : 22.c
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
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char buff[100];

    fd_set readFDSet;
    struct timeval timer;
    char *filepath = "./22_fifo";
    
    mkfifo(filepath, 0666);
    
    int fd = open(filepath, O_NONBLOCK | O_RDONLY);

    if (fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    FD_ZERO(&readFDSet);
    FD_SET(fd, &readFDSet); // Adding FIFO file's descriptor to the set of file descriptors to read from

    // Setting the time to wait to 10s
    timer.tv_sec = 10;
    timer.tv_usec = 0;

    int  st = select(fd + 1, &readFDSet, NULL, NULL, &timer);

    if (st == -1)
        perror("Error :");
    else if (st)
    {
        int rb = read(fd, &buff, 100);

        if (rb == -1)
            perror("Error:");
        else
            printf("Data received : %s\n", buff);
    }
    else
        printf("You didn't send any data for 10 seconds! :(\n");

    close(fd);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./22a
Data received : Hello there...
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

========================================================================================================
*/
