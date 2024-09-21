/*
============================================================================
Name : 31a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create a semaphore and initialize value to the semaphore.
              a. create a binary semaphore
              
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
    key_t key;
    union semun {
        int val; // Value of the semaphore
    } sem_set;

    key = ftok(".", 1);
    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int sem_id = semget(key, 1, IPC_CREAT | 0777);

    if(sem_id == -1) {
        perror("Error :");
        exit(1);
    }

    sem_set.val = 1; // 1 ----> binary semaphore

    int status = semctl(sem_id, 0, SETVAL, sem_set);

    if(status == -1) {
        perror("Error :");
        exit(1);
    }
    
    
    // Check and display the semaphore value
    int sem_value = semctl(sem_id, 0, GETVAL);
    if(sem_value == -1) {
        perror("Error :");
        exit(1);
    }
    printf("Initial semaphore value: %d\n", sem_value);
}

/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Initial semaphore value: 1
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/  
