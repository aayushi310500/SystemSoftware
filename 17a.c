/*
============================================================================
Name : 17a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to simulate online ticket reservation. Implement write lock
	      Write a program to open a file, store a ticket number and exit. 
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

int main(){
	struct { 
int ticket_no;
}db;
db.ticket_no=0;
int fd =open("ticket.txt",O_CREAT|O_RDWR,0777);
write(fd,&db,sizeof(db));
lseek(fd,0,SEEK_SET);
read(fd,&db,sizeof(fd));
printf("Ticket_no: %d\n",db.ticket_no);
close(fd);
}



/*===========================================================================
OUTPUT: STORING TICKET NO AND EXIT.
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc online_ticket_reservation_p17_a.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
Ticket_no: 0


=============================================================================*/
