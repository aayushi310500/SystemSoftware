/*
============================================================================
Name : 30.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2024.
============================================================================
*/

  
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
int main(){
if(!fork()){
  setsid();
  chdir("/");
  umask(0);
  while(1){
    sleep(20);
    printf("child pid: %d\n",getpid());
    printf("Daemon process is running..");
}
}
else{
 exit(0);
}
}



/*=======================================================================================================================================

OUTPUT:

aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ cc 30.c
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ ./a.out 
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ child pid: 5377
Daemon process is running..child pid: 5377
Daemon process is running..child pid: 5377
Daemon process is running..child pid: 5377
Daemon process is running..child pid: 5377
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ Daemon process is running..child pid: 5377
^C
aayushi312000@aayushi312000-81WB:~/Documents/cprograms$ Daemon process is running..child pid: 5377
kill 9 5377
bash: kill: (9) - No such process



aayushi312000@aayushi312000-81WB:~$ sudo ps -el
[sudo] password for aayushi312000: 
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
4 S     0       1       0  0  80   0 - 42157 ep_pol ?        00:00:02 systemd
1 S     0       2       0  0  80   0 -     0 kthrea ?        00:00:00 kthreadd
1 I     0       3       2  0  60 -20 -     0 rescue ?        00:00:00 rcu_gp
1 I     0       4       2  0  60 -20 -     0 rescue ?        00:00:00 rcu_par_gp
1 I     0       5       2  0  60 -20 -     0 rescue ?        00:00:00 slub_flush
1 I     0       6       2  0  60 -20 -     0 rescue ?        00:00:00 netns
1 I     0       8       2  0  60 -20 -     0 worker ?        00:00:00 kworker/0:
1 I     0      10       2  0  60 -20 -     0 rescue ?        00:00:00 mm_percpu_
1 I     0      11       2  0  80   0 -     0 rcu_ta ?        00:00:00 rcu_tasks_
1 I     0      12       2  0  80   0 -     0 rcu_ta ?        00:00:00 rcu_tasks_
1 I     0      13       2  0  80   0 -     0 rcu_ta ?        00:00:00 rcu_tasks_
1 S     0      14       2  0  80   0 -     0 smpboo ?        00:00:00 ksoftirqd/
1 I     0      15       2  0  80   0 -     0 rcu_gp ?        00:00:01 rcu_preemp
1 S     0      16       2  0 -40   - -     0 smpboo ?        00:00:00 migration/

4 S  1000    5088    2671  0  80   0 - 599178 do_pol ?       00:00:00 Web Conten
4 S  1000    5091    2671  0  80   0 - 599178 do_pol ?       00:00:00 Web Conten
1 I     0    5133       2  0  80   0 -     0 worker ?        00:00:00 kworker/3:
1 I     0    5188       2  0  80   0 -     0 worker ?        00:00:00 kworker/0:
1 I     0    5323       2  0  80   0 -     0 worker ?        00:00:00 kworker/2:
1 I     0    5324       2  0  80   0 -     0 worker ?        00:00:00 kworker/7:
1 I     0    5339       2  0  80   0 -     0 worker ?        00:00:00 kworker/4:
0 S  1000    5350    1418  0  80   0 -  7668 do_wai ?        00:00:00 gnome-term
0 S  1000    5353    5350  0  80   0 - 114449 do_pol ?       00:00:00 gnome-term
0 S  1000    5359    4744  0  80   0 -  2795 do_wai pts/3    00:00:00 bash
1 I     0    5367       2  0  80   0 -     0 worker ?        00:00:00 kworker/u1
1 I     0    5369       2  0  80   0 -     0 worker ?        00:00:00 kworker/1:
1 S  1000    5377    1418  0  80   0 -   654 hrtime ?        00:00:00 a.out       <<-------------------------------- ? denotes it's running in background
4 S     0    5395    5359  0  80   0 -  3371 do_pol pts/3    00:00:00 sudo
1 S     0    5398    5395  0  80   0 -  3371 do_pol pts/4    00:00:00 sudo



=======================================================================================================================================*/
