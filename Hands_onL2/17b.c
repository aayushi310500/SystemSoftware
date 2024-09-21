/*
============================================================================
Name : 17b.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to execute ls -l | wc.
             b. use dup2
Date: 20/09/2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main(){
   int fd[2];
   
   int status=pipe(fd);
   
   if(status==-1){
    perror("Error:");
   }
   else{
    int pid=fork();
    if(pid==-1){
      perror("Error:");
    }
    else if(!pid){
      close(fd[0]);
      dup2(fd[1],1); // STDOUT will be reassigned to pipefd[1]
      execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }
    else {
      close(fd[1]);  
      dup2(fd[0],0); // STDIN will be reassigned to pipefdp[0]

      execl("/usr/bin/wc", "wc", NULL);
    }
   }
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 17b.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
     79     704    5156
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l | wc
     79     704    5156
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
