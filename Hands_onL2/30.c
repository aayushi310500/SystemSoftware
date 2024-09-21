/*
============================================================================
Name : 30.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create a shared memory.
              a. write some data to the shared memory
              b. attach with O_RDONLY and check whether you are able to overwrite.
              c. detach the shared memory
              d. remove the shared memory
Date: 21/09/2024
============================================================================
*/
#include <sys/types.h> 
#include <sys/ipc.h>  
#include <sys/shm.h>  
#include <stdlib.h>   
#include <stdio.h>     

void main()
{
    key_t key;       
    ssize_t shm_size = 1024; 
    char *shm_ptr, *shm_rd_ptr;

    key = ftok(".", 1);

    if (key == -1)
    {
        perror("Error :");
        exit(1);
    }

    int shmid = shmget(key, shm_size, IPC_CREAT | 0700); // Create the shared memory if it doesn't exist; if it exists use the existing one

    if (shmid == -1)
    {
        perror("Error :");
        exit(1);
    }
    
    // ======================== a> ========================
    shm_ptr = shmat(shmid, 0, 0);

    if (*shm_ptr == -1)
    {
        perror("Error :");
        exit(1);
    }

    printf("Press enter to write to the shared memory!\n");
    getchar();
    
    char data[50];
    printf("Enter data to write:");
    scanf("%[^\n]",data);
    getchar();
    sprintf(shm_ptr,"%s", data); // Writing to the shared memory

    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", shm_ptr); // Reading from the shared memory


    // ======================== b> ========================

    shm_rd_ptr = shmat(shmid, 0, SHM_RDONLY);
    if (*shm_rd_ptr == -1)
    {
        perror("Error :");
        exit(1);
    }
    
   
    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("Data from shared memory: %s\n", shm_rd_ptr); // Reading from the shared memory




    // ======================== c> ========================
    printf("Detaching pointer to shared memory!\n");
    shmdt(shm_ptr);       // Dettach pointer to Shared Memory
    shmdt(shm_rd_ptr); // Dettach pointer to Shared Memory
    
    

    // ======================== d> ========================
    printf("Press enter to delete the shared memory!\n");
    getchar();

    // Delete Shared Memory
    shmctl(shmid, IPC_RMID, NULL);
    // ===================================================
}


/*
========================================================================================================
OUTPUT:
========================================================================================================


aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Press enter to write to the shared memory!

Enter data to write:hello
Press enter to read from the shared memory!

Data from shared memory: hello
Press enter to read from the shared memory!

Data from shared memory: hello
Detaching pointer to shared memory!
Press enter to delete the shared memory!

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 




aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x01051100 1          aayushi312 700        1024       2                       

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
