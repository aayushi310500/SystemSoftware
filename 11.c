/*
============================================================================
Name : 11.c
Author : Prajapati Aayushi Sadashivbhai
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
               descriptors and check whether the file is updated properly or not.
               a. use dup
               b. use dup2
               c. use fcntl

Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main(int argc,char *argv[]){
char buff[1024];
if(argc !=2){
 printf("less or more arguments");
}
  int fd1;
   const char *filename = argv[1];
  fd1=open(filename,O_RDWR|O_CREAT|O_APPEND,0777);
 if (fd1 == -1) {
        perror("open");
  }
  int fd_dup=dup(fd1);
  if(fd_dup ==-1){
 perror("dup");
        close(fd1);
}

int fd_dup2=dup2(fd1,10);
 if (fd_dup2 == -1) {
        perror("dup2");
        close(fd1);
        close(fd_dup);
    }
int fd_fcntl = fcntl(fd1, F_DUPFD, 20);
if (fd_fcntl == -1) {
        perror("dup2");
        close(fd1);
        close(fd_dup);
        close(fd_dup2);	
    }

char *data1="appending with fd  \n";
char *data2="appending with dup  \n";
char *data3="appending with dup2  \n";
char *data4="appending with fcntl  \n";
write(fd1, data1, strlen(data1));
write(fd_dup, data2, strlen(data2));
write(fd_dup2,data3,strlen(data3));
write(fd_fcntl,data4,strlen(data4));
//int n=read(fd_fcntl,buff,sizeof(buff));
  lseek(fd1, 0, SEEK_SET);
int data;
 while ((data = read(fd1, buff, sizeof(buff))) > 0) {
int t = write(1, buff, data);
if (t == -1) {
            perror("error:");
            close(fd1);
        }
    }
//printf("no of bytes:%d",n);
//write(1,buff,n);
}


/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc dup_p11.c 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out dup.txt
appending with fd  
appending with dup  
appending with dup2  
appending with fcntl  
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 

=============================================================================*/

