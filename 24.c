/*
============================================================================
Name : 24.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create an orphan process.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
int main(){
   int pid=fork();
   if(pid<0){
  perror("error:");
}
if(pid==0){
printf("child process is running ,before orphan child pid:%d ,parent pid %d\n",getpid(),getppid());
printf("press enter:");
  getchar();
 printf("child process is running ,after orphan child pid:%d ,parent pid : %d\n",getpid(),getppid());
 getchar();
 getchar(); 
}

else {
  printf("parent process is running ,parent pid %d ",getpid()); 
}
}


/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc orphan_p24.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
parent process is running ,parent pid 21500 child process is running ,before orphan child pid:21501 ,parent pid 21500
press enter:aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ child process is running ,after orphan child pid:21501 ,parent pid : 1420



ayushi312000@aayushi312000-81WB:/proc/1420$ cd /proc/1420
aayushi312000@aayushi312000-81WB:/proc/1420$ cat status
Name:	systemd
Umask:	0002
State:	S (sleeping)
Tgid:	1420
Ngid:	0
Pid:	1420
PPid:	1    // new parent's ppid became 1

=============================================================================*/
