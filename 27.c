/*
============================================================================
Name : 1a.c
Author : Prajapati Aayushi Sadashivbhai
Description : CWrite a program to execute ls -Rl by the following system calls
              a. execl
              b. execlp
              c. execle
              d. execv
              e. execvp
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
void execl_(){
printf("execl:\n");
 if(execl("/bin/ls","ls","-Rl",NULL)<0){
 perror("error:");
}
}

void execlp_(){
printf("execlp:\n");

if(execlp("ls","ls","-Rl",NULL)<0){
perror("error:");
}       
}

void execle_(){
printf("execle:\n");
char *envp[]={"MY_VAR=123",NULL};
if(execle("/bin/ls","ls","-Rl",NULL,envp)<0){
perror("error:");
}
}

void execv_(){
printf("execv:\n");
 char *argv[] = {"ls", "-Rl", NULL};
if(execv("/bin/ls",argv)<0){
perror("error:");
}
}
 void execvp_(){
char *argv[] = {"ls", "-Rl", NULL};
printf("execvp:\n");
if (execvp("ls", argv) == -1) {
 perror("error:");
}
}


 int main(){
int choice;
  printf("Choose which exec function to use to run ls -Rl:\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
 switch (choice) {
        case 1:
            execl_();
            break;
        case 2:
            execlp_();
            break;
        case 3:
            execle_();
            break;
        case 4:
            execv_();
            break;
        case 5:
            execvp_();
            break;
        default:
            printf("Invalid choice!\n");
    }
}


/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
Choose which exec function to use to run ls -Rl:
1. execl
2. execlp
3. execle
4. execv
5. execvp
Enter your choice (1-5): 2  (execlp)
execlp:
.:
total 264
-rwxrwxr-x 1 aayushi312000 aayushi312000 16520 Aug 30 20:29 a.out
-rwxrwxr-x 1 aayushi312000 aayushi312000 16368 Aug 30 18:18 b
-rw-rw-r-- 1 aayushi312000 aayushi312000   514 Aug 22 09:23 copy_7.c.save
-rw-rw-r-- 1 aayushi312000 aayushi312000  1849 Aug 30 16:17 copy_p7.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   888 Aug 30 15:52 creat_p3.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   578 Aug 30 00:41 daemon_p30.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2245 Aug 30 16:42 dup_p11.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    86 Aug 30 16:42 dup.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  4065 Aug 30 18:00 enviorn_p15.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   997 Aug 30 20:27 execl_p26.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1975 Aug 30 16:56 fcntl_p12.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1654 Aug 30 16:02 fd_5.c
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file1.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file2.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file3.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file4.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file5.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000    35 Aug 30 19:13 fork.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  2053 Aug 30 15:49 inf_loop_p2.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1992 Aug 30 16:22 info_p9.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1272 Aug 30 16:21 line_by_line_p8.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    33 Aug 27 23:59 linebyline.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1797 Aug 30 15:32 link_p1_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    64 Aug 30 18:15 lock.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  2468 Aug 30 16:37 lseek_p10.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1728 Aug 30 00:40 ls-rl_p27.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2173 Aug 30 18:20 mandatory_locking_p16_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2802 Aug 30 18:17 mandatory_lock_p16_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   986 Aug 30 15:41 mkfifo_p1_c.c
-rw------- 1 aayushi312000 aayushi312000     1 Aug 27 18:22 nano.22866.save
-rw-rw-r-- 1 aayushi312000 aayushi312000  1072 Aug 30 19:02 nice_p20.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1073 Aug 30 18:45 online_ticket_reservation_p17_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  4477 Aug 30 18:45 online_ticket_reservation_p17_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   997 Aug 30 15:57 open_p4.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1552 Aug 30 20:18 orphan_p24.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1397 Aug 30 19:13 p_22.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16008 Aug 28 23:09 p_26
-rw-rw-r-- 1 aayushi312000 aayushi312000   187 Aug 28 22:55 p____.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    85 Aug  8 15:03 pipe_list.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1395 Aug 30 19:05 ppid_21.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   494 Aug 29 20:24 read_l_by_p8.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   922 Aug 30 16:05 read_write_p6.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  4737 Aug 30 18:59 record_locking_p18_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1403 Aug 30 10:00 record_locking_p18.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   856 Aug 30 00:40 rt_priority_p28.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1244 Aug 30 14:54 sched_p29.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16000 Aug 29 16:15 sum
-rw-rw-r-- 1 aayushi312000 aayushi312000   571 Aug 30 20:26 sum_p26_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1469 Aug 30 15:19 symlink_p1_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000     8 Aug 30 18:44 ticket.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1053 Aug 30 19:00 timestamp_p19.c
-rwxrwxr-x 1 aayushi312000 aayushi312000    24 Aug 30 18:59 train_booking.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000    32 Aug 30 17:53 train_record.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1809 Aug 30 17:02 type_of_file_p14.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2655 Aug 30 20:26 waitpid_p25.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1598 Aug 30 19:43 zombie_p23.c




aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
Choose which exec function to use to run ls -Rl:
1. execl
2. execlp
3. execle
4. execv
5. execvp
Enter your choice (1-5): 4 (execv)
execv:
.:
total 264
-rwxrwxr-x 1 aayushi312000 aayushi312000 16520 Aug 30 20:29 a.out
-rwxrwxr-x 1 aayushi312000 aayushi312000 16368 Aug 30 18:18 b
-rw-rw-r-- 1 aayushi312000 aayushi312000   514 Aug 22 09:23 copy_7.c.save
-rw-rw-r-- 1 aayushi312000 aayushi312000  1849 Aug 30 16:17 copy_p7.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   888 Aug 30 15:52 creat_p3.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   578 Aug 30 00:41 daemon_p30.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2245 Aug 30 16:42 dup_p11.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    86 Aug 30 16:42 dup.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  4065 Aug 30 18:00 enviorn_p15.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   997 Aug 30 20:27 execl_p26.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1975 Aug 30 16:56 fcntl_p12.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1654 Aug 30 16:02 fd_5.c
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file1.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file2.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file3.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file4.txt
-rwxrwxr-x 1 aayushi312000 aayushi312000     0 Aug 30 16:00 file5.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000    35 Aug 30 19:13 fork.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  2053 Aug 30 15:49 inf_loop_p2.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1992 Aug 30 16:22 info_p9.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1272 Aug 30 16:21 line_by_line_p8.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    33 Aug 27 23:59 linebyline.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1797 Aug 30 15:32 link_p1_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    64 Aug 30 18:15 lock.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  2468 Aug 30 16:37 lseek_p10.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1728 Aug 30 00:40 ls-rl_p27.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2173 Aug 30 18:20 mandatory_locking_p16_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2802 Aug 30 18:17 mandatory_lock_p16_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   986 Aug 30 15:41 mkfifo_p1_c.c
-rw------- 1 aayushi312000 aayushi312000     1 Aug 27 18:22 nano.22866.save
-rw-rw-r-- 1 aayushi312000 aayushi312000  1072 Aug 30 19:02 nice_p20.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1073 Aug 30 18:45 online_ticket_reservation_p17_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  4477 Aug 30 18:45 online_ticket_reservation_p17_b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   997 Aug 30 15:57 open_p4.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1552 Aug 30 20:18 orphan_p24.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1397 Aug 30 19:13 p_22.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16008 Aug 28 23:09 p_26
-rw-rw-r-- 1 aayushi312000 aayushi312000   187 Aug 28 22:55 p____.c
-rw-rw-r-- 1 aayushi312000 aayushi312000    85 Aug  8 15:03 pipe_list.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1395 Aug 30 19:05 ppid_21.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   494 Aug 29 20:24 read_l_by_p8.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   922 Aug 30 16:05 read_write_p6.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  4737 Aug 30 18:59 record_locking_p18_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1403 Aug 30 10:00 record_locking_p18.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   856 Aug 30 00:40 rt_priority_p28.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1244 Aug 30 14:54 sched_p29.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16000 Aug 29 16:15 sum
-rw-rw-r-- 1 aayushi312000 aayushi312000   571 Aug 30 20:26 sum_p26_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1469 Aug 30 15:19 symlink_p1_a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000     8 Aug 30 18:44 ticket.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1053 Aug 30 19:00 timestamp_p19.c
-rwxrwxr-x 1 aayushi312000 aayushi312000    24 Aug 30 18:59 train_booking.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000    32 Aug 30 17:53 train_record.txt
-rw-rw-r-- 1 aayushi312000 aayushi312000  1809 Aug 30 17:02 type_of_file_p14.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2655 Aug 30 20:26 waitpid_p25.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1598 Aug 30 19:43 zombie_p23.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ 

=============================================================================*/
