/*
============================================================================
Name : 16b.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to perform mandatory locking.
              a. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<sys/file.h>
#include<string.h>
#include<unistd.h>
int main(){
struct flock lock;
int fd;
int buff[1024];
fd=open("lock.txt",O_RDWR,0777);
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();
printf("before entering into read critical section\n");
fcntl(fd,F_SETLKW,&lock);
printf("Inside the critical section..\n");
int data;
lseek(fd, 0, SEEK_SET);
while((data=read(fd,buff,sizeof(buff)))>0){
int t = write(1, buff, data);
if (t == -1) {
            perror("error:");
            //close(fd);
        }
    }

printf("enter to unclock..\n");
getchar();
printf("unlocked \n");
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("done\n");

}


/*===========================================================================
OUTPUT:
//-----------------------------MULTIPLE READ------------------------------
TERMINAL: 1
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./b
before entering into read critical section
Inside the critical section..
hello, writing in the file this is the data stored in the file
enter to unclock..

TERMINAL :2
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./b
before entering into read critical section
Inside the critical section..
hello, writing in the file this is the data stored in the file
enter to unclock..

//----------------------------- READ WRITE CONFLICT------------------------------
TERMINAL: 1
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./b
before entering into read critical section
Inside the critical section..
hello, writing in the file this is the data stored in the file
enter to unclock..

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
before entering into critical section

=============================================================================*/

