/*
============================================================================
Name : 27b.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to receive messages from the message queue.
             b.IPC_NOWAIT
Date: 21  /09/2024
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
    ssize_t message_size; 

    struct msgbuf
    {
        long mtype;     // Used to identify message type - should be > 0
        char message[50]; 
    } msgq;

    key = ftok(".", 1);

    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int msgid = msgget(key, IPC_CREAT | 0700);

    if (msgid == -1)
    {
        perror("Error :");
        exit(1);
    }

    msgq.mtype = 1;
   

    message_size = msgrcv(msgid, &msgq, sizeof(msgq.message), msgq.mtype, IPC_NOWAIT);

    if (message_size == -1)
    {
        perror("Error :");
        exit(1);
    }
    printf("Message Type: %ld\n",msgq.mtype);
    printf("Message : %s\n", msgq.message);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        64           2           

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 27b.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Message Type: 1
Message : heeloo
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Message Type: 1
Message : okays
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        0            0           

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Error :: No message of desired type
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/  
