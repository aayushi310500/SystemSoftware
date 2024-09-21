/*
============================================================================
Name : 24.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to create a message queue and print the key and message queue id.
Date: 20/09/2024
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>    
#include <unistd.h>   
#include<stdlib.h>

void main()
{
    key_t key = ftok(".", 1);

    if (key == -1)
    {
        perror("Error while computing key!");
        exit(1);
    }

    int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0700);
    if (msgid == -1)
    {
        perror("Error while creating Message Queue!");
        exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n", msgid);
}




/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 24.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Key: 17109248
Message Queue Identifier: 0


========================================================================================================
*/
