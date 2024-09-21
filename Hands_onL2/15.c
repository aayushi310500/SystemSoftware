/*
============================================================================
Name : 15.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a simple program to send some data from parent to the child process.
Date: 20/09/2024
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
int fd[2];

char buff0[50];
char buff1[50];

int status = pipe(fd);
if(status==-1){
  perror("Error:");
  exit(1);
}
else{
   int pid= fork();
   if(pid==-1){
   perror("Error:");
   }

   else if(pid>0){
//parent
    close(fd[0]);
    printf("enter data to write into pipe (parent):");
    fgets(buff1, sizeof(buff1), stdin);
    int wb=write(fd[1],&buff1,sizeof(buff1));
    if(wb==-1){
      perror("error");
    }
    close(fd[1]);
  }
  else{
   //child:
    close(fd[1]);
    int rb=read(fd[0],&buff0,sizeof(buff0));
    if(rb==-1){
    perror("Error:");
    }
    else{
      printf("data from parent to child: %s\n",buff0);
    }
  close(fd[0]);
}

}
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 15.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
enter data to write into pipe (parent):hello
data from parent to child: hello

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 


========================================================================================================
*/ 
