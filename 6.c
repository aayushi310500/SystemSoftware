/*
============================================================================
Name : 6.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 12th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
int main(){
char buff[50];
int n = read(0,buff,sizeof(buff)/sizeof(buff[0]));
write(1,buff,n);
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc read_write_p6.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
writing from stdinput <<------writing from stdinput with read call
writing from stdinput  <<-----reading from stdout with write call

=============================================================================*/

