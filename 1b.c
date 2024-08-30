/*
============================================================================
Name : 1b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Create the following types of a files using (i) shell command (ii) system call 
             b. hard link (link system call)
Date: 8th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
int main()
{
 int lk=link("/home/aayushi312000/Documents/folder1/folder2/folder3/newfile.txt","/home/aayushi312000/Desktop/syslink_sortcut/hlink.txt");
 perror("msg:");
}

/*=======================================================================================================================================================
OUTPUT:


-------------------------------------------------------- (i) shell command----------------------------------------------------

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ln "/home/aayushi312000/Documents/folder1/folder2/folder3/newfile.txt" "/home/aayushi312000/Documents/cr_hlink_.txt"

content of newfile.txt: 
aayushi312000@aayushi312000-81WB:~/Documents/folder1/folder2/folder3$ cat newfile.txt
file for hardlink testing


aayushi312000@aayushi312000-81WB:~/Documents$ ls
 cprograms       extra     sftlink_fldr  'text files tmp'
 cr_slink_.txt   folder1   syslink
aayushi312000@aayushi312000-81WB:~/Documents$ ls
 cprograms       cr_slink_.txt   folder1        syslink
 cr_hlink_.txt   extra           sftlink_fldr  'text files tmp'
 
 
content of hardlink file cr_hlink_.txt
aayushi312000@aayushi312000-81WB:~/Documents$ cat cr_hlink_.txt
file for hardlink testing
aayushi312000@aayushi312000-81WB:~/Documents$ 


------------------------------------------------------(ii) system call ----------------------------------------------------


TERMINAL:1
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc link_p1_b.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
hardlink has been created successfully..aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 


TERMINAL:2 content of newfile.txt
aayushi312000@aayushi312000-81WB:~/Documents/folder1/folder2/folder3$ cat newfile.txt
file for hardlink testing

TERMINAL :3 content of hardlink file hlink.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ ls
abc.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ ls
abc.txt  hlink.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ cat hlink.txt
file for hardlink testing
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ 


OUTPUT of ls-l 
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ ls -l
total 8
lrwxrwxrwx 1 aayushi312000 aayushi312000 64 Aug 30 15:15 abc.txt -> /home/aayushi312000/Documents/folder1/folder2/folder4/file12.txt
-rw-rw-r-- 2 aayushi312000 aayushi312000 26 Aug 30 15:24 hlink.txt

===============================================================================================================================================================*/

