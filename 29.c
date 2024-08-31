/*
============================================================================
Name : 29.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
              SCHED_RR).
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>
int main(){
int pid=getpid();
 struct sched_param param;
int sched_ = sched_getscheduler(pid);
if(sched_==-1){
perror("error");
}
if(sched_==SCHED_OTHER){
 printf("current scheduling is SCHED_OTHER\n");
}
else if(sched_==SCHED_FIFO){
printf("current scheduling is SCHED_FIFO\n");
}
else if(sched_==SCHED_RR){
printf("current scheduling is SCHED_RR\n");
}
else{
printf("unknown scheduling policy");
}
//changing schedulin policy:
param.sched_priority = 20;  // Set a new priority
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
    }
 printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);

 sched_ = sched_getscheduler(pid);
    if (sched_ == -1) {
     perror("error: ");
    }

    // Print the final scheduling policy
    //print_policy(policy);
}


/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
current scheduling is SCHED_OTHER
sched_setscheduler: Operation not permitted
Scheduling policy changed to SCHED_RR with priority 20
=============================================================================*/







