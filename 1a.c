/*
============================================================================
Name : 1a.c
Author : Prajapati Aayushi Sadashivbhai
Description : Create the following types of a files using (i) shell command (ii) system call 
              a.soft link (symlink system call)
Date: 8th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
int main()
{
 int sl=  symlink("/home/aayushi312000/Documents/folder1/folder2/folder4/file12.txt", "/home/aayushi312000/Desktop/syslink_sortcut/abc.txt");
 if(sl==-1){perror("error:");}
else{
printf("symlink  has created successfully");
}
}


/*===================================================================================================================================
OUTPUT:

-------------------------------------------------------- (i) shell command----------------------------------------------------

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ln -s "/home/aayushi312000/Documents/folder1/folder2/folder4/file12.txt" "/home/aayushi312000/Documents/cr_slink_.txt"

//content of file12.txt 
aayushi312000@aayushi312000-81WB:~/Documents/folder1/folder2/folder4$ cat file12.txt
syslink editing files


 cprograms   extra   folder1   sftlink_fldr   syslink  'text files tmp'
aayushi312000@aayushi312000-81WB:~/Documents$ ls
 cprograms       extra     sftlink_fldr  'text files tmp'
 cr_slink_.txt   folder1   syslink


//content of cr_slink_.txt
aayushi312000@aayushi312000-81WB:~/Documents$ cat cr_slink_.txt
syslink editing files 
aayushi312000@aayushi312000-81WB:~/Documents$ 




------------------------------------------------------(ii) system call ----------------------------------------------------


//output of terminal 1:
ayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
symlink  has created successfullyaayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 


//content of file12.txt 
aayushi312000@aayushi312000-81WB:~/Documents/folder1/folder2/folder4$ cat file12.txt
syslink editing files

//content of abc.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ ls
hlink.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ ls
abc.txt  hlink.txt
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ cat abc.txt
syslink editing files 
aayushi312000@aayushi312000-81WB:~/Desktop/syslink_sortcut$ 


======================================================================================================================================================*/
