/*
============================================================================
Name : 32c.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to implement semaphore to protect any critical section.
              c. protect multiple pseudo resources ( may be two) using counting semaphore
              
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
    char *filename = "./read_file.txt"; 
    char buff[1000];

    key_t sem_key;      
    int status;

    // Create a new ticket file / open an exisiting one
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error :");
        exit(1);
    }

    // Defines a semaphore's structure
    union semun
    {
        int val;               // Value of the semaphore
    } sem_set;
    
     
     /// ============ Creating / Getting Semaphore ==========
    
    sem_key = ftok(".", 'k');
    if (sem_key == -1)
    {
        perror("Error:");
        exit(1);
    }

    int sem_id = semget(sem_key, 1, 0); // Get the semaphore if it exists
    if (sem_id == -1)
    {
        sem_id = semget(sem_key, 1, IPC_CREAT | 0700); // Create a new semaphore 
        if (sem_id == -1)
        {
            perror("Error :");
            exit(1);
        }

        sem_set.val = 3; // Set a counting semaphore
        status = semctl(sem_id, 0, SETVAL, sem_set);
        if (status == -1)
        {
            perror("Error:");
            exit(1);
        }
    }
    
    
    // ===========Defines the operation on the semaphore============

    struct sembuf semOp; 
    semOp.sem_num = 0;
    semOp.sem_flg = IPC_NOWAIT;

    printf("Press enter to obtain lock for the critical section!\n");
    getchar();

    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    status = semop(sem_id, &semOp, 1);
    if (status == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Obtained lock on critical section!");

    printf("Now entering critical section!");



    // =========== Start of Critical Section ===========

    int rb = read(fd, &buff, 1000);
    if (rb == -1)
    {
        perror("Error :");
        exit(1);
    }
    else if (rb == 0) // Sample file has no data
        printf("No data exists!\n");
    else
        printf("Sample data: \n %s", buff);

    printf("\n\nPress enter key to exit critical section!\n");
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
//Sem.val=3
TERMINAL 1,2,3:
ayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to obtain lock for the critical section!

Obtained lock on critical section!Now entering critical section!Sample data: 
 Lord Krishna, the eighth avatar of Lord Vishnu, possessed 16 kalas or divine qualities. These qualities include compassion, patience, forgiveness, justice, impartiality
m.V

Press enter key to exit critical section!

TERMINAL 4:
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to obtain lock for the critical section!

Error :: Resource temporarily unavailable
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/  
