/*
============================================================================
Name : 26b.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to execute an executable program.
              b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){
//char *argv[] = {"./sum", "10", "20", NULL};
 if (execl("./sum","./a.out" ,argv[1],argv[2],NULL) == -1) {
        perror("error:");
    }
}

/*===========================================================================
OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc execl_p26.c 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 2 3
a+b = 5aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 

=============================================================================*/
