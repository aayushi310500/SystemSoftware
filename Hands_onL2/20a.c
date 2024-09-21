/*
============================================================================
Name : 20.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write two programs so that both can communicate by FIFO -Use one way communication.(write)
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
    char buff[50] ; // Data to be sent through the buffer'
    char * filepath="./20_fifo";
    if (mkfifo(filepath ,0666) == -1)
        perror("Error :");
    int fd = open(filepath, O_WRONLY);
    if (fd == -1)
        perror("Error :");
    else
    {
        printf("Enter data want to send in pipe:");
        scanf("%[^\n]",buff);
        int wb = write(fd, &buff, sizeof(buff));
        if (wb == -1)
            perror("Error :");
        close(fd);
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 20a.c -o ./20
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./20
Enter data want to send in pipe:hello
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/
