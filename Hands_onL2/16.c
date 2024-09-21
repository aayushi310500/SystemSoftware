/*
============================================================================
Name : 16.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to send and receive data from parent to child vice versa. Use two way
             communication.
Date: 20/09/2024
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
int ptc_fd[2];
int ctp_fd[2];
char parent_msg[100];
char child_msg[100];
char buff[100];

if(pipe(ptc_fd)==-1){
    perror("Error:");
    exit(1);
}
if(pipe(ctp_fd)==-1){
    perror("Error:");
    exit(1);
}


int pid=fork();
if(pid==-1){
    perror("Error:");
    exit(1);
}
else{
    if(pid>0){
//Parent
      
      close(ptc_fd[0]);
      close(ctp_fd[1]);
      printf("Writing into pipe(PARENT)\n");
      printf("Enter Msg from the parent ,send to the child:\n");
      fgets(parent_msg, sizeof(parent_msg), stdin);
      int wb=write(ptc_fd[1],parent_msg,sizeof(parent_msg));
      if(wb==-1){
          perror("Error:");
          exit(1);
        }
      close(ptc_fd[1]); 
        
      printf("Reading from pipe(PARENT) msg from child::\n");
      int rb=read(ctp_fd[0],buff,sizeof(buff));
      printf("parent received:%s\n",buff);

      
      close(ctp_fd[0]);
}

else{
      //Child
    close(ptc_fd[1]);
    close(ctp_fd[0]);

      //printf("Reading from pipe(CHILD) ,msg from parent::\n");
    int rb=read(ptc_fd[0],buff,sizeof(buff));
     if (rb == -1) {
            perror("Error reading from parent pipe:");
            exit(1);
        }
    printf("child received: %s\n",buff);

     close(ptc_fd[0]);
    printf("Writing into pipe(CHILD)\n");
     printf("Enter Msg from the chid ,send to the parent:\n");
     fgets(child_msg, sizeof(child_msg), stdin);
    int wb=write(ctp_fd[1],child_msg,sizeof(child_msg));
    if(wb==-1){
        perror("Error:");
        exit(1);
    }
        close(ctp_fd[1]); 
        close(ptc_fd[0]);
    

  }
} 
}


/*
========================================================================================================
OUTPUT:
========================================================================================================

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 16.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Writing into pipe(PARENT)
Enter Msg from the parent ,send to the child:
hello
Reading from pipe(PARENT) msg from child::
child received: hello

Writing into pipe(CHILD)
Enter Msg from the chid ,send to the parent:
hii
parent received:hii

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



========================================================================================================
*/



