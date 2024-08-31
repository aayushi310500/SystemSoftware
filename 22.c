/*
============================================================================
Name : 22.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<string.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){
 char *filename=argv[1];
  int fd1=open(filename,O_RDWR,0777);
    if (fd1 < 0) {
        perror("error:");
    }
  int id =fork();
if (id < 0) {
        perror("error:");
        close(fd1);
    }
  if(id==0){
char* str1="writing by child\n";
write(fd1,str1,strlen(str1));
}
else{
char* str2="writing by parent\n";
write(fd1,str2,strlen(str2));
wait(0);

lseek(fd1,0,SEEK_SET);
char buff[1024];
int data;
while((data=read(fd1,buff,sizeof(buff)))>0){
  int t=write(1,buff,data);
if(t ==-1){
 perror("error:");
}
}
}

close(fd1);
}


/*===========================================================================
OUTPUT:
lseek(fd1,0,SEEK_SET);
char buff[1024];
int data;
while((data=read(fd1,buff,sizeof(buff)))>0){
  int t=write(1,buff,data);
if(t ==-1){
 perror("error:");
}
}
=============================================================================*/
