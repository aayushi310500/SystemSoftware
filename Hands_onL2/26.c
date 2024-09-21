/*
============================================================================
Name : 26.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to send messages to the message queue. Check `ipcs -q`
Date: 20/09/2024
============================================================================
*/

#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>    
#include<stdlib.h>

void main()
{
    key_t key;        
    struct msgbuf
    {
        long mtype;     // Used to identify message type - should be > 0
        char message[20]; 
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
    printf("Enter the message:\n");
    scanf("%[^\n]",msgq.message);

    int status = msgsnd(msgid, &msgq, sizeof(msgq), 0);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Message sent! Check using `ipcs -q`\n");
}



/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 26.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Enter the message:
hello, there
Message sent! Check using `ipcs -q`
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        48           2           

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/  
