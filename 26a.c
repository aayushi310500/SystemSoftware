/*
============================================================================
Name : 26a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to execute an executable program.
              use some executable program
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
 if(argc !=3){
  printf("less or more no of arguments");
return 1;
}
   int a=atoi(argv[1]);
   int b=atoi(argv[2]);
   int c=a+b;
   printf("a+b = %d",c);
}
