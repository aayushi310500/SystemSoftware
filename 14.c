/*
============================================================================
Name : 14.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
              verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char * argv[]){
if(argc!=2){
 printf("less or more no of arguments.");
}
char *filename =argv[1];
struct stat st;
if (stat(filename, &st) == -1) {
        perror("error:");
    }
 if (S_ISREG(st.st_mode)) {
        printf("File type: Regular file\n");
    } else if (S_ISDIR(st.st_mode)) {
        printf("File type: Directory\n");
    } else if (S_ISLNK(st.st_mode)) {
        printf("File type: Symbolic link\n");
    } else if (S_ISCHR(st.st_mode)) {
        printf("File type: Character device\n");
    } else if (S_ISBLK(st.st_mode)) {
        printf("File type: Block device\n");
    } else if (S_ISFIFO(st.st_mode)) {
        printf("File type: FIFO (named pipe)\n");
    } else if (S_ISSOCK(st.st_mode)) {
        printf("File type: Socket\n");
    } else {
        printf("File type: Unknown\n");
    }
}

/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc type_of_file_p14.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out dup.txt
File type: Regular file
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out "/home/aayushi312000/Documents/extra/fifo_syscall.txt"
File type: FIFO (named pipe)

=============================================================================*/

