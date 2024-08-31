/*
============================================================================
Name : 18.c
Author : Prajapati Aayushi Sadashivbhai
Description :18. Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record, first lock it then modify/access
              to avoid race condition.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

//--------------------------------------Storing Inital value for Tickets--------------------------------

void initial_store(){
struct {
int train_no;
int ticket_no;
}db[3];

int i;
int fd=open("train_booking.txt",O_CREAT|O_RDWR,0777);
if(fd<0){
perror("error:");
}
for(int i=0;i<3;i++){
db[i].train_no=i+1;
db[i].ticket_no=0;
}
write(fd,db,sizeof(db));
close(fd);
}


//-------------------------------------------- a. Implement write lock-------------------------------------

void write_file(){
struct {
int train_no;
int ticket_no;
}db;

int fd=open("train_booking.txt",O_RDWR,0777);
if(fd<0){
perror("error: ");
}
int input;
printf("choose train num to book between 1,2,3: \n");
scanf("%d",&input);
struct flock lock;
lock.l_type=F_WRLCK;
lock.l_whence=SEEK_SET;
lock.l_start=(input-1)*sizeof(db);
lock.l_len=sizeof(db);
lock.l_pid=getpid();

lseek(fd,(input-1)*sizeof(db),SEEK_SET);
fcntl(fd,F_SETLKW,&lock);
read(fd,&db,sizeof(db));
printf("train no: %d , current ticket no : %d \n",db.train_no,db.ticket_no);
db.ticket_no++;
lseek(fd,(input-1)*sizeof(db),SEEK_SET);
write(fd,&db,sizeof(db));
printf("Press enter to book ticket:\n");
getchar();
getchar();
lseek(fd,(input-1)*sizeof(db),SEEK_SET);
read(fd,&db,sizeof(db));
printf("your ticket no: %d\n",db.ticket_no);
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("done\n");
close(fd);
}


//--------------------------------------------  b. Implement read lock-------------------------------------

void read_file(){
struct {
 int train_no;
int ticket_no;
}db;
int fd=open("train_booking.txt",O_RDWR,0777);
int input;
printf("enter a train no to see the data of that train: \n");
scanf("%d",&input);
struct flock lock;
lock.l_type=F_RDLCK;
lock.l_whence=SEEK_SET;
lock.l_start=(input-1)*sizeof(db);
lock.l_len=sizeof(db);
lock.l_pid=getpid();

fcntl(fd,F_SETLKW,&lock);
lseek(fd,(input-1)*sizeof(db),SEEK_SET);
read(fd,&db,sizeof(db));
printf("train no: %d , current ticket_no : %d \n",db.train_no,db.ticket_no);
printf("press enter to unlock: \n");

getchar();
getchar();
lock.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&lock);
printf("done\n");
close(fd);

}




int main(){
int choice;
printf("4.intialize:\n");
while(1){
printf("1.book ticket:\n");
printf("2.check record:\n");
printf("3.exit\n");
printf("enter the choice: \n");
scanf("%d",&choice);

switch(choice){ 
case 1:
write_file();
break;
case 2:
read_file();
break;
case 3:
return 1;
break;
case 4:
initial_store();
break;
default:
printf("enter valid choice\n");
}
}
}



/*===========================================================================
OUTPUT:

TERMINAL : 1
Booking Ticket in train no:2
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
4.intialize:
1.book ticket:
2.check record:
3.exit
enter the choice: 
4
1.book ticket:
2.check record:
3.exit
enter the choice: 
1
choose train num to book between 1,2,3: 
2
train no: 2 , current ticket no : 0 
Press enter to book ticket:


TERMINAL : 2
Booking Ticket in train no:1  
allowed
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
4.intialize:
1.book ticket:
2.check record:
3.exit
enter the choice: 
1
choose train num to book between 1,2,3: 
1
train no: 1 , current ticket no : 0 
Press enter to book ticket:


-----------------------READING DATA AFTER BOOKING-----------------
TERMINAL 1:
1.book ticket:
2.check record:
3.exit
enter the choice: 
2   
enter a train no to see the data of that train: 
1
train no: 1 , current ticket_no : 1 
press enter to unlock: 

TERMINAL 2:
1.book ticket:
2.check record:
3.exit
enter the choice: 
2   
enter a train no to see the data of that train: 
2
train no: 2 , current ticket_no : 1 
press enter to unlock: 


--------------------SAME RECORD SIMULTANEOUS WRITING NOT ALLOWED----------------
TERMINAL 1:
1.book ticket:
2.check record:
3.exit
enter the choice: 
1       
choose train num to book between 1,2,3: 
2
train no: 2 , current ticket no : 1 
Press enter to book ticket:


TERMINAL 2:
1.book ticket:
2.check record:
3.exit
enter the choice: 
1   
choose train num to book between 1,2,3: 
2



=============================================================================*/




