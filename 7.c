/*
============================================================================
Name : 7.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 12th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>
int main(){
int buff[300];
int fd1=open("/home/aayushi312000/Documents/extra/pipe_list.txt",O_RDONLY,0777);
if(fd1<0){
  perror("Error:");
}
//int n=read(fd1,buff,100);
int fd2=open("/home/aayushi312000/Documents/extra/cpy_pipe_list.txt",O_CREAT|O_WRONLY,0777);
if(fd2<0){
  perror("error");
}
int n;
while(n=read(fd1,buff,sizeof(buff))>0){
  write(fd2,buff,n);
}
//write(fd2,buff,n);
}

/*===========================================================================
OUTPUT:

TERMINAL: 1(running code:)
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc copy_p7.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 


TERMINAL:2
aayushi312000@aayushi312000-81WB:~/Documents/extra$ ls
creat_txt.txt  fifo1.txt  fifo_syscall.txt  pipe_list.txt  seeking.txt
aayushi312000@aayushi312000-81WB:~/Documents/extra$ ls
cpy_pipe_list.txt  fifo1.txt         pipe_list.txt
creat_txt.txt      fifo_syscall.txt  seeking.txt
aayushi312000@aayushi312000-81WB:~/Documents/extra$ cat pipe_list.txt  <<<-------------content of original file
apple
orange
banana
lime
pineapple
strawberry
blueberry
watermelon
muskmelon
grapes
aayushi312000@aayushi312000-81WB:~/Documents/extra$ cat cpy_pipe_list.txt  <<-------------content of copied file
apple
orange
banana
lime
pineapple
strawberry
blueberry
watermelon
muskmelon
grapes





=============================================================================*/

