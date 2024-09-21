
/*
============================================================================
Name : 32a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to implement semaphore to protect any critical section.
              a. rewrite the ticket number creation program using semaphore
              
Date: 21/09/2024
============================================================================
*/
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h> 
#include <stdlib.h>

void main()
{
    char *ticketFile = "./ticket_file.txt";           
    int data; 
    int status;
    key_t key;      

    // Create a new ticket file / open an exisiting one
    int fd = open(ticketFile, O_CREAT | O_RDWR, 0777);
    if (fd == -1)
    {
        perror("Error:");
        exit(1);
    }

    // Defines a semaphore's structure
    union semun
    {
        int val;               \
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
        struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
    } sem_set;

    key = ftok(".", 'x');
    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int sem_id = semget(key, 1, 0); // Get the semaphore if it exists
    if (sem_id == -1)
    {
        sem_id = semget(key, 1, IPC_CREAT | 0700); // Create a new semaphore 
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

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();
    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    status = semop(sem_id, &semOp, 1);
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }
    
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    
    // =========== Start of Critical Section ===========

    int rb = read(fd, &data, sizeof(data));
    if (rb == -1)
    {
        perror("Error :");
        exit(1);
    }
    else if (rb == 0) // Ticket file has no data
        data = 1;
    else
    {
        data += 1;
        int offset = lseek(fd, 0, SEEK_SET);
        if (offset == -1)
        {
            perror("Error :");
            exit(1);
        }
    }

    int wb = write(fd, &data, sizeof(data));
    if (wb == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Your ticker number is - %d\n", data);

    printf("Press enter to exit from critical section!\n");
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
    close(fd);
}


/*
========================================================================================================
OUTPUT:
========================================================================================================
  



========================================================================================================
*/  
