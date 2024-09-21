/*
============================================================================
Name : 27a.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to receive messages from the message queue.
             a. with 0 as a flag
Date: 20/09/2024
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
   

    message_size = msgrcv(msgid, &msgq, sizeof(msgq.message), msgq.mtype, 0);

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
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Message Type: 1
Message : done
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q          <--------------watch ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        32           1           

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Message Type: 1
Message : hii
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        0            0           
= 

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out    <<<----wait for msg




========================================================================================================
*/  
