/*
============================================================================
Name : 21b.c
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
     
    int fifo1_fd = open(fifo1, O_RDONLY);
    if (fifo1_fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    int fifo2_fd = open(fifo2, O_WRONLY);
    if (fifo2_fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    int wb = write(fifo2_fd, "msg from 21b to 21a", 19);

    if (wb == -1)
        perror("Error :");

    close(fifo2_fd);

    int rb = read(fifo1_fd, &buff, 100);

    if (rb == -1)
    {
        perror("Error:");
        exit(1);
    }

    printf("Data from FIFO: %s\n", buff);

    close(fifo1_fd);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 21b.c -o ./21b
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./21b
Data from FIFO: msg from 21a to 21b
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

========================================================================================================
*/

