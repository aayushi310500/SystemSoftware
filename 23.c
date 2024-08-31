/*
============================================================================
Name : 23.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create a Zombie state of the running program.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>

int main(){
    int pid= fork();
    if(pid<0){
      perror("error:");
    }
    else if(pid==0){
      printf("child process running, child pid: %d",getpid());
    }
    else{
      printf("parent process is running,child pid: %d ,parent pid: %d",pid,getpid());
      getchar();
    }
    //getchar();
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc zombie_p23.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
parent process is running,child pid: 18205 ,parent pid: 18204child process running, child pid: 18205



//------------------------------------------------Checking inside proc directory---------------------------------------



aayushi312000@aayushi312000-81WB:/proc/18066$ cd /proc/18205
aayushi312000@aayushi312000-81WB:/proc/18205$ cat status
Name:	a.out
State:	Z (zombie)
Tgid:	18205
Ngid:	0
Pid:	18205
PPid:	18204
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	0
Groups:	4 24 27 30 46 100 118 1000 
NStgid:	18205
NSpid:	18205
NSpgid:	18204
NSsid:	14250
...........


=============================================================================*/
