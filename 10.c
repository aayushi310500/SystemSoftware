/*
===============================================================================================================
Name : 10.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
              bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.e
Date: 19th Aug, 2024.
================================================================================================================
*/

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
int main(){
  int fd1=open("/home/aayushi312000/Documents/extra/seeking.txt",O_RDWR,0777);
char buff[1024];
  if(fd1<0){
   perror("error:");
}
printf("Enter exactly 10 chars \n");
int rd1=read(0,buff,10);
//printf("rd1: %d\n",rd1);
 write(fd1,buff,10);
 printf("press enter \n");
getchar();
getchar();
int offset = lseek(fd1,10,SEEK_CUR);
printf("offset: %d \n",offset);
printf("Enter exactly 10 chars \n");
int rd2=read(0,buff,10);
//printf("====== %d\n",rd2);
write(fd1,buff,10);

//if(offset ==-1){
//perror("failed to lseek");
//}
//else{
//printf("offset is set");
//getch();

//printf("offset: %d \n",offset);
lseek(fd1,0,SEEK_SET);
int data;
while ((data = read(fd1, buff, sizeof(buff))) > 0) {
        // Write the content to stdout
int t = write(1, buff, data);
if (t == -1) {
            perror("error:");
            close(fd1);
        }
    }
close(fd1);
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc lseek_p10.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
Enter exactly 10 chars 
abcdefghij
press enter 

offset: 20 
Enter exactly 10 chars 
ABCDEFGHIJ

OUTPUT FOR B>
aayushi312000@aayushi312000-81WB:~/Documents/extra$ od -c seeking.txt
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   A   B   C   D   E   F   G   H   I   J
0000036

here \0 indicates whitespace , lseek(fd1,10,SEEK_CUR); it will give 10 whitespace and then starts writing.

=============================================================================*/


