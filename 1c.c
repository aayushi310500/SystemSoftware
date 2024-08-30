/*
============================================================================
Name : 1c.c
Author : Prajapati Aayushi Sadashivbhai
Description : Create the following types of a files using (i) shell command (ii) system call 
              c. FIFO (mkfifo Library Function or mknod system call)
Date: 8th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <fcntl.h>           
#include <sys/stat.h>
int main(){
int stat =mkfifo("/home/aayushi312000/Documents/extra/fifo_syscall.txt",0777);
if(stat==-1){
perror("error");
}
}

/*=============================================================================
OUTPUT:

-------------------------------------------------------- (i) shell command----------------------------------------------------

ayushi312000@aayushi312000-81WB:~/Documents$ ls
 cprograms       cr_slink_.txt   folder1        syslink
 cr_hlink_.txt   extra           sftlink_fldr  'text files tmp'

aayushi312000@aayushi312000-81WB:~/Documents$ ls
 cprograms       cr_slink_.txt   folder1       sftlink_fldr  'text files tmp'
 cr_hlink_.txt   extra           myfifo_.txt   syslink


aayushi312000@aayushi312000-81WB:~/Documents$ cat > myfifo_.txt
hello
hii
okay

aayushi312000@aayushi312000-81WB:~/Documents$ cat < myfifo_.txt
hello
hii
okay


------------------------------------------------------(ii) system call ----------------------------------------------------

TERMINAL 1:(WRITING):
aayushi312000@aayushi312000-81WB:~/Documents/extra$ cat > fifo_syscall.txt
Hii
Helllo


TERMINAL 2:(READING):
aayushi312000@aayushi312000-81WB:~/Documents/extra$  cat < fifo_syscall.txt 
Hii
Helllo


==============================================================================*/
