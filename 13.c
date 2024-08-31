/*
============================================================================
Name : 13.c
Author : Prajapati Aayushi Sadashivbhai
Description : 1 Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>


int main(int argc, char const *argv[])
{
    fd_set rfds;
    struct timeval t;
    int ans;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    t.tv_sec=10;
    t.tv_usec=0;

    ans = select(1, &rfds, NULL, NULL, &t);

    if(ans<0)
    {
    perror("error: ");
    }
    else if(ans>0){
        printf("There is input in these 10 seconds\n");
    }
    else {
        printf("There is NO input in these 10 seconds\n");
    }

    return 0;
}


/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
hii There is NO input in these 10 seconds
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
hiiThere is NO input in these 10 seconds
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
hii
There is input in these 10 seconds

=============================================================================*/


