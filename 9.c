/*
================================================================================
Name : 9.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to print the following information about a given file.
              a. inode
              b. number of hard links
              c. uid
              d. gid
              e. size
              f. block size
              g. number of blocks
              h. time of last access
              i. time of last modification
              j. time of last change
Date: 14th Aug, 2024.
===============================================================================
*/

#include<stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>

int main(){
struct stat statbuf;
int st=stat("/home/aayushi312000/Documents/extra/pipe_list.txt",&statbuf);
if(st<0){
perror("error : ");
exit(EXIT_FAILURE);

}
printf("INode:%ld\n",statbuf.st_ino);
printf("No of hardlinks: %ld\n",statbuf.st_nlink);
printf("UID: %u\n", statbuf.st_uid);
printf("GID: %u\n", statbuf.st_gid);
printf("File size: %ld bytes\n",statbuf.st_size);
printf("Block size: %ld bytes\n", statbuf.st_blksize);
printf("Blocks allocated:%ld\n", statbuf.st_blocks);
printf("Last status change: %s\n", ctime(&statbuf.st_ctime));
printf("Last file access: %s\n", ctime(&statbuf.st_atime));
printf("Last file modification: %s\n", ctime(&statbuf.st_mtime));
exit(EXIT_SUCCESS);
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc info_p9.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out
INode:1063967
No of hardlinks: 1
UID: 1000
GID: 1000
File size: 85 bytes
Block size: 4096 bytes
Blocks allocated:8
Last status change: Thu Aug  8 15:03:05 2024

Last file access: Fri Aug 30 16:09:23 2024

Last file modification: Thu Aug  8 15:03:05 2024

=============================================================================*/

