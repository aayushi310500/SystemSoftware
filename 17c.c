/*
============================================================================
Name : 17b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to simulate online ticket reservation.  Write a separate program, to
	      open the file, implement write lock, read the ticket number, increment the number and print
	      the new ticket number then close the file
Date: 28th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


void read_ticket(){
struct {
int ticket_no;
}db;
int fd=open("ticket.txt",O_RDWR,0777);
if(fd<0){
perror("error: ");
}
struct flock lock;
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();
printf("before entering into critical section.\n");
fcntl(fd,F_SETLKW,&lock);
read(fd,&db,sizeof(db));
printf("current ticket no is: %d\n",db.ticket_no);
printf("press enter to unlock\n");
getchar();
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("unlocked\n");
printf("done..");
close(fd);
}


void book_ticket(){
struct flock lock;
struct {
int ticket_no;
}db;
int fd=open("ticket.txt",O_RDWR,0777);
if(fd<0){
perror("error:");
}
lock.l_type=F_WRLCK;
lock.l_whence=SEEK_SET;
lock.l_start=0;
lock.l_len=0;
lock.l_pid=getpid();
printf("before entering into critical section.\n");
fcntl(fd,F_SETLKW,&lock);
read(fd,&db,sizeof(db));
printf("current ticket no is: %d\n",db.ticket_no);
//printf("press enter to book ticket: \n");
//getchar();
//getchar();
db.ticket_no++;
lseek(fd,0,SEEK_SET);
write(fd,&db,sizeof(db));
lseek(fd,0,SEEK_SET); 
read(fd,&db,sizeof(db));
printf("your ticket no is: %d\n",db.ticket_no);
printf("press enter to unlock\n");
getchar();
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("unlocked\n");
printf("done..");
close(fd);
}


int main(){
int choice;
printf("1.book ticket.\n");
printf("2.read ticket.\n");
printf("enter your choice:\n");
scanf("%d",&choice);
switch(choice){
case 1:
book_ticket();
break;
case 2:
read_ticket();
break;
default:
printf("enter valid choice:\n");
break;
}
}

/*===========================================================================
OUTPUT:
//-------------------------------MULTIPLE READ ALLOWED----------------------
TERMINAL 1:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
1.book ticket.
2.read ticket.
enter your choice:
2
current ticket no is: 10
press enter to unlock

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
1.book ticket.
2.read ticket.
enter your choice:
2
current ticket no is: 10
press enter to unlock



//-------------------------------READ WRITE CONFLICT----------------------
TERMINAL 1:
done..aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
1.book ticket.
2.read ticket.
enter your choice:
2
before entering into critical section.
current ticket no is: 16
press enter to unlock

TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
1.book ticket.
2.read ticket.
enter your choice:
1
before entering into critical section.


-------------------------------AFTER UNLOCKED---------------------------
TERMINAL 1:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
1.book ticket.
2.read ticket.
enter your choice:
2
before entering into critical section.
current ticket no is: 16
press enter to unlock

unlocked
done..

TERMINAL :2
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
1.book ticket.
2.read ticket.
enter your choice:
1
before entering into critical section.
current ticket no is: 16
your ticket no is: 17
press enter to unlock


//-------------------------------WRITE WRITE CONFLICT----------------------

TERMINAL :1
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
1.book ticket.
2.read ticket.
enter your choice:
1
before entering into critical section.
current ticket no is: 17
your ticket no is: 18
press enter to unlock
  
TERMINAL 2:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
1.book ticket.
2.read ticket.
enter your choice:
1
before entering into critical section.

AFTER UNLOCKED:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
1.book ticket.
2.read ticket.
enter your choice:
1
before entering into critical section.
current ticket no is: 18
your ticket no is: 19
press enter to unlock


=============================================================================*/





