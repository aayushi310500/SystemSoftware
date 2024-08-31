/*
============================================================================
Name : 16a.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to perform mandatory locking.
              a. Implement write lock
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include <sys/file.h>
#include<string.h>
#include<unistd.h>
int main(){
  struct flock lc;
  int fd;
fd = open("lock.txt",O_RDWR,0777);
lc.l_type=F_WRLCK;
lc.l_whence=SEEK_SET;
lc.l_start=0;
lc.l_len=0;
lc.l_pid=getpid();
char* str="hello, writing in the file this is the data stored in the file\n";
printf("before entering into critical section\n");
fcntl(fd,F_SETLKW,&lc);
printf("Inside the critical section..");
write(fd,str,strlen(str)+1);
printf("enter to unclock..");
getchar();
printf("unlocked \n");
lc.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lc);
printf("done\n");
}


/*===========================================================================
OUTPUT:

//-----------------------WRITE WRITE CONFLICT:--------------------
TERMINAL: 1
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
before entering into critical section
Inside the critical section..enter to unclock..

TERMINAL: 2
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
before entering into critical section

//-----------------------AFTER LEAVING CRITICAL SECTION::---------------------

TERMINAL 1:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
before entering into critical section
Inside the critical section..enter to unclock..
unlocked 
done

TERMINAL :2
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
before entering into critical section
Inside the critical section..enter to unclock..

//-----------------------WRITE READ CONFLICT:---------------------
TERMINAL 1: 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
before entering into critical section
Inside the critical section..enter to unclock..

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc mandatory_locking_p16_b.c -o b
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./b
before entering into read critical section

//-----------------------AFTER LEAVING CRITICAL SECTION::---------------------
TERMINAL 1: 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
before entering into critical section
Inside the critical section..enter to unclock..
unlocked 
done

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./b
before entering into read critical section

Inside the critical section..
hello, writing in the file this is the data stored in the file
enter to unclock..
unlocked 
done

=============================================================================*/


