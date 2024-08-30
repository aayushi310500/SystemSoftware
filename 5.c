/*
============================================================================
Name : 5.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd
Date: 28th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <fcntl.h>
int main(){
int count=0;
 char filename[20];
   while(1){
    if(count<5){
//  filename="file";
  sprintf(filename,"file%d.txt",count+1);
  int fd = open(filename,O_CREAT|O_RDWR,0777);
   if(fd<0){
  perror("error");
}
printf("Created and opened %s with file descriptor %d\n", filename, fd);
count++;
}
}
}

/*===========================================================================
OUTPUT:

TERMINAL 1: (running code)
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc fd_5.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out &
[1] 9069
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ Created and opened file1.txt with file descriptor 3
Created and opened file2.txt with file descriptor 4
Created and opened file3.txt with file descriptor 5
Created and opened file4.txt with file descriptor 6
Created and opened file5.txt with file descriptor 7

TERMINAL 2: (in proc dir)
aayushi312000@aayushi312000-81WB:~$ cd /proc/9069/fd
aayushi312000@aayushi312000-81WB:/proc/9069/fd$ ls
0  1  2  3  4  5  6  7
aayushi312000@aayushi312000-81WB:/proc/9069/fd$ 


=============================================================================*/


