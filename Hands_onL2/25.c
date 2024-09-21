/*
============================================================================
Name : 25.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
            a. access permission
            b. uid, gid
            c. time of last message sent and received
            d. time of last change in the message queue
            e. size of the queue
            f. number of messages in the queue
            g. maximum number of bytes allowed
            h. pid of the msgsnd and msgrcv
Date: 20/09/2024
============================================================================
*/


#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h>  
#include <stdio.h>   
#include <unistd.h>   
#include <stdlib.h>   
void main()
{
                           
    struct msqid_ds msg_q_info;               

    key_t key = ftok(".", 1);

    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int msgid = msgget(key, IPC_CREAT | 0700);
    if (msgid == -1)
    {
        perror("Error while creating Message Queue!");
        exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", msgid);

    int status = msgctl(msgid, IPC_STAT, &msg_q_info);

    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Access Permission: %od\n", msg_q_info.msg_perm.mode);
    printf("UID: %d\n", msg_q_info.msg_perm.uid);
    printf("GID: %d\n", msg_q_info.msg_perm.gid);
    printf("Time of last message sent: %ld\n", msg_q_info.msg_stime);
    printf("Time of last message received: %ld\n", msg_q_info.msg_rtime);
    printf("Size of queue: %ld\n", msg_q_info.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", msg_q_info.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", msg_q_info.msg_qbytes);
    printf("PID of last sent message: %d\n", msg_q_info.msg_lspid);
    printf("PID of last received message: %d\n", msg_q_info.msg_lrpid);
}



/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 25.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Key: 17109248
Message Queue Identifier: 0

Access Permission: 700d
UID: 1000
GID: 1000
Time of last message sent: 0
Time of last message received: 0
Size of queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last sent message: 0
PID of last received message: 0


//after msg sent from msgqueues programs



aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 25.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Key: 17109248
Message Queue Identifier: 0

Access Permission: 700d
UID: 1000
GID: 1000
Time of last message sent: 1726857733
Time of last message received: 1726857755
Size of queue: 0
Number of messages in the queue: 0
Maximum number of bytes allowed in the queue: 16384
PID of last sent message: 33397
PID of last received message: 33412
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x01051100 0          aayushi312 700        0            0           

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/
