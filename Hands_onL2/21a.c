/*
============================================================================
Name : 21.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write two programs so that both can communicate by FIFO -Use two way communications.    
Date: 20/09/2024
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>   
#include <stdio.h>   
#include<stdlib.h>


void main()
{ 
    char buff[100];

   char *fifo1 = "./21_fifo_1";
   char *fifo2 = "./21_fifo_2";

     mkfifo(fifo1, 0666);
     mkfifo(fifo2, 0666); 
     int fifo1_fd = open(fifo1, O_WRONLY);
    if (fifo1_fd == -1)
    {
        perror("Error:");
        exit(1);
    }

    int fifo2_fd = open(fifo2, O_RDONLY);
    if (fifo2_fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    int wb = write(fifo1_fd, "msg from 21a to 21b", 19);

    if (wb == -1)
        perror("Error :");

    close(fifo1_fd);

    int rb = read(fifo2_fd, &buff, 100);

    if (rb == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Data from FIFO: %s\n", buff);

    close(fifo2_fd);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 21a.c -o ./21a
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./21a
Data from FIFO: msg from 21b to 21a
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/


