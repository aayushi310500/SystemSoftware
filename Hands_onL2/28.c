/*
============================================================================
Name : 28.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to change the exiting message queue permission. (Use `msqid_ds` structure)
Date: 21/09/2024
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>  
#include <stdio.h>   
#include <stdlib.h>   

void main()
{
    key_t key;                          
    struct msqid_ds messageQueueInfo; 
                 

    key = ftok(".", 9);

    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int msgid = msgget(key, IPC_CREAT | 0600);
    if (msgid == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", msgid);

    int status = msgctl(msgid, IPC_STAT, &messageQueueInfo);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Current permissions: %o\n", messageQueueInfo.msg_perm.mode & 0777);
    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    status = msgctl(msgid, IPC_SET, &messageQueueInfo);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    
    status = msgctl(msgid, IPC_STAT, &messageQueueInfo);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }


    printf("New permissions: %o\n", messageQueueInfo.msg_perm.mode & 0777);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 28.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Key: 151326976
Message Queue Identifier: 1

Current permissions: 600
Press enter to change the permissions!

New permissions: 777
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

========================================================================================================
  


========================================================================================================
*/  
