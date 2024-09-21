/*
============================================================================
Name : 32b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to implement semaphore to protect any critical section.
              b. protect shared memory from concurrent write access
              
Date: 21/09/2024
============================================================================
*/


#include <sys/ipc.h>  
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/shm.h>   
#include <stdlib.h>    
#include <stdio.h>     

void main()
{
    key_t sem_key;  
    int sem_id; 
    

    key_t shm_key;         
    int shm_id;   
    ssize_t shm_size = 1024; 
    char *shm_pointer;
    
    int status;
    // ============ Creating / Getting Semaphore ==========

    // Defines a semaphore's structure
    union semun
    {
        int val;               
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
        struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
    } sem_set;


    // ============ Creating / Getting Semaphor==========
    
    sem_key = ftok(".", 'f');
    if (sem_key == -1)
    {
        perror("Error:");
        exit(1);
    }

    sem_id = semget(sem_key, 1, 0); // Get the semaphore if it exists
    if (sem_id == -1)
    {
        sem_id = semget(sem_key, 1, IPC_CREAT | 0700); // Create a new semaphore
        if (sem_id == -1)
        {
            perror("Error :");
            exit(1);
        }

        sem_set.val = 1; // Set a binary semaphore
        status = semctl(sem_id, 0, SETVAL, sem_set);
        if (status == -1)
        {
            perror("Error :");
            exit(1);
        }
    }
    
    

    // ================================================

    // ============ Creating / Getting Shared Memory ==========
    shm_key = ftok(".", 'g');

    if (shm_key == -1)
    {
        perror("Error :");
        exit(1);
    }

    shm_id = shmget(shm_key, shm_size, IPC_CREAT | 0700); // Create the shared memory if it doesn't exist; if it exists use the existing one

    if (shm_id == -1)
    {
        perror("Error:");
        exit(1);
    }

    // printf("Shared Memory Identifier: %d\n", shmIdentifier);

    shm_pointer = shmat(shm_id, 0, 0);

    if (*shm_pointer == -1)
    {
        perror("Error :");
        exit(1);
    }



    // ========================================================

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to lock the critical section!\n");
    getchar();
    
    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    status = semop(sem_id, &semOp, 1);
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    
    printf("Critical Section is now locked!\n");

    printf("Start of the critical section!\n");


    // =========== Start of Critical Section ===========

    printf("Writing to the shared memory!\n");
    // Writing to the shared memory
    char data[50];
    printf("enter data to write:");
    scanf("%[^\n]",data);
    sprintf(shm_pointer,"%s", data);

    printf("Press enter to read from the shared memory!\n");
    getchar();

    // Reading from the shared memory
    printf("%s\n", shm_pointer);

    printf("Press enter to exit the critical section!\n");
    getchar();

    // =========== End of Critical Section =============

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    status = semop(sem_id, &semOp, 1);
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Critical section is now unlocked!\n");
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
TERMINAL 1:
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to lock the critical section!

Critical Section is now locked!
Start of the critical section!
Writing to the shared memory!
enter data to write:hello


TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to lock the critical section!

=========================================================After came out from Critical Section====================================================

TERMINAL 1:
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to lock the critical section!

Critical Section is now locked!
Start of the critical section!
Writing to the shared memory!
enter data to write:hello
Press enter to read from the shared memory!
hello
Press enter to exit the critical section!

Critical section is now unlocked!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to lock the critical section!

Critical Section is now locked!
Start of the critical section!
Writing to the shared memory!
enter data to write:hhk
Press enter to read from the shared memory!
hhk
Press enter to exit the critical section!

Critical section is now unlocked!

========================================================================================================
*/  
