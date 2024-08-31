/*
============================================================================
Name : 12.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
void opening_mode(int fd1){
int flags=fcntl(fd1,F_GETFL);
 if (flags == -1) {
        perror("error:");
        close(fd1);
    }
int access_mode = flags & O_ACCMODE;
printf("access mode :%d\n",access_mode);
if(access_mode==O_RDONLY){
 printf("file is opened in readonly mode\n");
}
else if(access_mode==O_WRONLY){ 
 printf("file is opened in writeonly mode\n");
}
else if(access_mode==O_RDWR){ 
 printf("file is opened in readwrite mode\n");
}
else{
printf("file is opened some other mode\n");

}
if(flags & O_APPEND) {
        printf("O_APPEND flag is set\n");
    }
if (flags & O_NONBLOCK) {
        printf("O_NONBLOCK flag is set\n");
    }
}


int main(int argc,char * argv[]){
if(argc!=2){
printf("less or more arguments");
}	
char *filename=argv[1];
int fd1;
fd1=open(filename,O_RDONLY|O_APPEND,0777);
if(fd1<0){
perror("error:");
}
opening_mode(fd1);
close(fd1);
fd1=open(filename,O_WRONLY|O_APPEND,0777);
if(fd1<0){
perror("error:");
}
opening_mode(fd1);
close(fd1);


fd1=open(filename,O_RDWR|O_APPEND,0777);
if(fd1<0){
perror("error:");
}
opening_mode(fd1);
close(fd1);
}


/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc fcntl_p12.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out dup.txt
access mode :0
file is opened in readonly mode
O_APPEND flag is set
access mode :1
file is opened in writeonly mode
O_APPEND flag is set
access mode :2
file is opened in readwrite mode
O_APPEND flag is set

=============================================================================*/

