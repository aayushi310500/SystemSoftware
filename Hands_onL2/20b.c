/*
============================================================================
Name : 20.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write two programs so that both can communicate by FIFO -Use one way communication.(read)
Date: 20/09/2024
============================================================================
*/


#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>     
#include <unistd.h>   
#include <stdio.h>     

void main()
{
          // File descriptor of the FIFO file
    char *filepath = "./20_fifo"; // Path name of the FIFO file
             
    char buff[100];               // Data from the FIFO file

    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        perror("Error :");
    else
    {
        int rb = read(fd, buff, 100);
        if (rb == -1)
            perror("Error :");
        else
        {
            printf("Data from the FIFO file - %s\n", buff);
        }
        close(fd);
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 20b.c -o ./20b
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./20b
Data from the FIFO file - hello
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

========================================================================================================
*/
