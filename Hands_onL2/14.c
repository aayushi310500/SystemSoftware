/*
============================================================================
Name : 14.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
              the monitor.
Date: 20/09/2024
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
 int main(){
 int fd[2];
char buff0[50];
char buff1[50];

int status = pipe(fd);
if(status==-1){
   perror("Error :");
}
else{
    printf("writing into pipe...\n");
    printf("Please enter data to write in pipe: ");
    fgets(buff1, sizeof(buff1), stdin);
    int wb=write(fd[1],&buff1,sizeof(buff1));
    if(wb==-1){
       perror("Error write:");
    }
    else{
      printf("reading from file...\n");
      int rb=read(fd[0],&buff0,sizeof(buff0));
      if(rb==-1){
         perror("Error:");
      }
      else{
        printf("data:%s\n",buff0);
      }
 }
}
}


/*
========================================================================================================
OUTPUT:
========================================================================================================


aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 14.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
writing into pipe...
Please enter data to write in pipe: hello
reading from file...
data:hello

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/    

