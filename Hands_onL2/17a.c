/*
============================================================================
Name : 17a.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to execute ls -l | wc.
             a. use dup
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
      close(1);
      close(fd[0]);
      dup(fd[1]); // STDOUT will be reassigned to pipefd[1]
      execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }
    else {
      close(0);  
      close(fd[1]);
      dup(fd[0]); // STDIN will be reassigned to pipefdp[0]
      execl("/usr/bin/wc", "wc", NULL);
    }
   }
}

/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 17a.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
     79     704    5156
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l | wc
     79     704    5156
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/
