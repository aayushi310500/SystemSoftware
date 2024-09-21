/*
============================================================================
Name : 29.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to remove the message queue.
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

    key = ftok(".", 5);

    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int msgid = msgget(key, IPC_CREAT | 0700);
    if (msgid == -1)
    {
        perror("Error:");
        exit(0);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", msgid);

    int status = msgctl(msgid, IPC_RMID, NULL);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================


aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Key: 84218112
Message Queue Identifier: 6

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 777        0            0           
0x09051100 1          aayushi312 777        0            0           



========================================================================================================
*/
