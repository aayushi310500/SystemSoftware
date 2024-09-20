/*
============================================================================
Name : 5.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to print the system limitation of
              a. maximum length of the arguments to the exec family of functions.
              b. maximum number of simultaneous process per user id.
              c. number of clock ticks (jiffy) per second.
              d. maximum number of open files
              e. size of a page
              f. total number of pages in the physical memory
              g. number of currently available pages in the physical memory.
Date: 19/09/2024
============================================================================
*/

#include <unistd.h>
#include <stdio.h>


void main()
{
    long ans;

 printf("5.a>==========================================================================================================\n");
    // _SC_ARG_MAX =  Maximum length of the arguments to the exec family of functions.
    ans = sysconf(_SC_ARG_MAX);
    if(ans == -1)
        perror("Error :");
    else 
       printf("%s - %ld \n\n", "Maximum length of the arguments to the exec family of functions", ans);
   
   
   
   printf("5.b>==========================================================================================================\n");
    // _SC_CHILD_MAX -  Maximum number of simultaneous process per user id.
    ans = sysconf(_SC_CHILD_MAX);
    if(ans == -1)
        perror("Error:");
    else 
      printf("%s - %ld \n\n", "Maximum number of simultaneous process per user id", ans);
    
    
    
    
    printf("5.c>==========================================================================================================\n");    
    // _SC_CLK_TCK -  Number of clock ticks (jiffy) per second.
    ans = sysconf(_SC_CLK_TCK);
    if(ans == -1)
        perror("Error :");
    else 
        printf("%s - %ld\n\n", "Number of clock ticks (jiffy) per second", ans);
        
        
        
        
   printf("5.d>==========================================================================================================\n"); 
    // _SC_OPEN_MAX -  Maximum number of open files
    ans = sysconf(_SC_OPEN_MAX);
    if(ans == -1)
        perror("Error :");
    else 
        printf("%s - %ld \n\n", "Maximum number of open files", ans);
        
        
        
   printf("5.e>==========================================================================================================\n");
    // _SC_PAGESIZE -  Size of a page
    ans = sysconf(_SC_PAGESIZE);
    if(ans == -1)
        perror("Error :");
    else 
      printf("%s - %ld \n\n", "Size of a page", ans);
      
      
      
      
   printf("5.f>==========================================================================================================\n");
    // _SC_PHYS_PAGES -  Total number of pages in the physical memory
    ans = sysconf(_SC_PHYS_PAGES);
    if(ans == -1)
        perror("Error :");
    else 
         printf("%s - %ld \n\n", "Total number of pages in the physical memory", ans);
         
         
         
   printf("5.g>==========================================================================================================\n");
    // _SC_AVPHYS_PAGES -  Number of  currently available pages in the physical memory.
    ans = sysconf(_SC_AVPHYS_PAGES);
    if(ans == -1)
        perror("Error :");
    else 
     printf("%s - %ld \n\n", "Number of  currently available pages in the physical memory", ans);

}

/*
========================================================================================================
OUTPUT:
========================================================================================================
  
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 5.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out 
5.a>==========================================================================================================
Maximum length of the arguments to the exec family of functions - 2097152 

5.b>==========================================================================================================
Maximum number of simultaneous process per user id - 30401 

5.c>==========================================================================================================
Number of clock ticks (jiffy) per second - 100

5.d>==========================================================================================================
Maximum number of open files - 1024 

5.e>==========================================================================================================
Size of a page - 4096 

5.f>==========================================================================================================
Total number of pages in the physical memory - 1964428 

5.g>==========================================================================================================
Number of  currently available pages in the physical memory - 710405 




========================================================================================================
*/
