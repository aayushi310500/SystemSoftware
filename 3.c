/*
============================================================================
Name : 3.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 8th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
int main(){
int fd;
fd = creat("/home/aayushi312000/Documents/extra/creat_txt.txt", 0744);
if(fd<0){
perror("error:");
}
else{
printf("value of file descriptor: %d\n",fd);
}
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc creat_p3.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
value of file descriptor: 3

=============================================================================*/

