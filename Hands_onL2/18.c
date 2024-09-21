/*
============================================================================
Name : 18.c
Author : Prajapati Aayushi Sadashivbhai
Description :Write a program to find out total number of directories on the pwd.
             execute ls -l | grep ^d | wc ? Use only dup2.     
Date: 20/09/2024
============================================================================
*/


#include <unistd.h>   
#include <sys/types.h> 
#include <stdio.h>     

void main()
{
    int pipe_cmd_1_2_fd[2], pipe_cmd_2_3_fd[2]; // fd[0] -> read, fd[1] -> write
  

    int pipe_1_status = pipe(pipe_cmd_1_2_fd);
    int pipe_2_status = pipe(pipe_cmd_2_3_fd);

    if (pipe_1_status == -1 )
        perror("Error 1:");
    else
    {
        int pid1 = fork();

        if (pid1 == -1)
            perror("Error 1");
        else if (pid1 == 0)
        {
            // Child One will enter this branch
            close(pipe_cmd_2_3_fd[1]); // Close the write end of the pipe
            close(pipe_cmd_1_2_fd[0]);
            close(pipe_cmd_1_2_fd[1]);

            close(STDIN_FILENO);
            dup2(pipe_cmd_2_3_fd[0], STDIN_FILENO);

            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent will enter this branch
            int pid2 = fork();

            if (pid2 == -1)
                perror("Error 2:");
            else if (pid2 == 0)
            {
                // Child Two will enter this branch

                close(pipe_cmd_1_2_fd[1]); // Close the write end of the pipe
                close(pipe_cmd_2_3_fd[0]);

                close(STDIN_FILENO);
                dup2(pipe_cmd_1_2_fd[0], STDIN_FILENO);
                close(STDOUT_FILENO);
                dup2(pipe_cmd_2_3_fd[1], STDOUT_FILENO);

                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
            else  
            {
                // Parent will enter this branch

                // Parent will execute the `ls -l` command
                close(pipe_cmd_1_2_fd[0]); // Close the read end of the pipe
                close(pipe_cmd_2_3_fd[1]);
                close(pipe_cmd_2_3_fd[0]);

                close(STDOUT_FILENO); // Close the file descriptor to the standard output
                dup2(pipe_cmd_1_2_fd[1], STDOUT_FILENO); // Reassign standard output to pipe output

                execl("/usr/bin/ls", "ls -l", "-l", NULL);
            }
        }
    }
}
