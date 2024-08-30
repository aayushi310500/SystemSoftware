/*
============================================================================
Name : 4.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 8th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>
int main(){
int fd =open("/home/aayushi312000/Documents/extra/pipe_list.txt",O_RDWR|O_CREAT|O_EXCL,0777);
//int fd =open("/home/aayushi312000/Documents/extra/pipe_list.txt",O_RDWR|O_CREAT|O_EXCL,0777);
if(fd<0){
perror("error:");
}
else{
printf("%d\n",fd);
}
}

/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc open_p4.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
error:: File exists


does not allow creat if file already exists
=============================================================================*/

