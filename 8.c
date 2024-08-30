/*
============================================================================
Name : 7.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 28th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
int main(){
  char buff[1];
  int fd1=open("/home/aayushi312000/Documents/extra/pipe_list.txt",O_RDONLY,0777);
  int n;
  while(n=read(fd1,buff,1)>0){
     if(buff[0]=='\n')
        getchar();
     else
       printf("%c",buff[0]);	     
  }
  close(fd1);
}


/*=======================================================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc 8.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
                   (printning each line when we press any char.)
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

==========================================================================================================*/
