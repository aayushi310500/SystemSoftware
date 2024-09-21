/*
============================================================================
Name : 32d.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to implement semaphore to protect any critical section.
              d. remove the created semaphore
              
Date: 21/09/2024
============================================================================
*/


#include <sys/types.h> 
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <stdlib.h>   
#include <stdio.h>     

void main()
{
    key_t sem_key;
    int status;

    sem_key = ftok(".", 1);
    if (sem_key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int sem_id = semget(sem_key, 1, IPC_CREAT | 0777);

    if (sem_id == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Press enter to delete the semaphore!\n");
    getchar();

    status = semctl(sem_id, 0, IPC_RMID);

    if (status == -1)
    {
        perror("Error :!");
        exit(1);
    }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
/

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -s

---------------- Semaphore Arrays ----------------------
key        semid      owner      perms      nsems     
0x01051100 0          aayushi312 777        1         
0x78051100 1          aayushi312 700        1         
0x66051100 2          aayushi312 700        1         
0x6b051100 3          aayushi312 700        1         

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to delete the semaphore!

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x78051100 1          aayushi312 700        1         
0x66051100 2          aayushi312 700        1         
0x6b051100 3          aayushi312 700        1         



========================================================================================================
*/  
