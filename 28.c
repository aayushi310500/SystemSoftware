/*
============================================================================
Name : 28.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to get maximum and minimum real time priority.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sched.h>
int main(){
int max_priority,min_priority;
  printf("SCHED_FIFO:\n");
  max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);
 printf("Maximum priority: %d\n", max_priority);
    printf("Minimum priority: %d\n", min_priority);
printf("SCHED_RR:\n");
 max_priority = sched_get_priority_max(SCHED_RR);
    min_priority = sched_get_priority_min(SCHED_RR);
printf("Maximum Priority: %d\n", max_priority);
    printf("Minimum Priority: %d\n", min_priority);

}


/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc rt_priority_p28.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
SCHED_FIFO:
Maximum priority: 99
Minimum priority: 1
SCHED_RR:
Maximum Priority: 99
Minimum Priority: 1

=============================================================================*/
