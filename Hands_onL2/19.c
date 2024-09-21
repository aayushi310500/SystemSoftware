/*
============================================================================
Name : 19.c
Author : Prajapati Aayushi Sadashivbhai
Description :Create a FIFO file by
              a. mknod command
              b. mkfifo command
              c. use strace command to find out, which command (mknod or mkfifo) is better.
              c. mknod system call
              d. mkfifo library function 
Date: 20/09/2024
============================================================================
*/

#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

void main()
{

    // Using `mkfifo` library function

    if (mkfifo("./mkfifo_lib", 0666) == -1)
        perror("Error :");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");

    // Using `mknod` system call
    if (mknod("./mknod_sys", __S_IFIFO | 0666, 0) == -1)
        perror("Error :");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
}






/*
========================================================================================================
OUTPUT:
========================================================================================================

10a.c  10b.c  10c.c  11.c  12.c  1a  1a.c  1b.c  1c.c  2.c  3.c  4.c  5.c  6.c  7.c  8a.c  8b.c  8c.c  8d.c  8e.c  8f.c  8g.c  9.c  a.out
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ nano 18.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ mknod my_nod p
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ mkfifo my_fifo
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls
10a.c  10b.c  10c.c  11.c  12.c  1a  1a.c  1b.c  1c.c  2.c  3.c  4.c  5.c  6.c  7.c  8a.c  8b.c  8c.c  8d.c  8e.c  8f.c  8g.c  9.c  a.out  my_fifo  my_nod
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ strace mknod my_nod_str p

aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls
10a.c  10b.c  10c.c  11.c  12.c  1a  1a.c  1b.c  1c.c  2.c  3.c  4.c  5.c  6.c  7.c  8a.c  8b.c  8c.c  8d.c  8e.c  8f.c  8g.c  9.c  a.out  my_fifo  my_fifo_str  my_nod  my_nod_str
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l  my_fifo_str 
prw-rw-r-- 1 aayushi312000 aayushi312000 0 Sep 20 15:08 my_fifo_str
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l  my_nod_str 
prw-rw-r-- 1 aayushi312000 aayushi312000 0 Sep 20 15:07 my_nod_str
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l my_fifo
prw-rw-r-- 1 aayushi312000 aayushi312000 0 Sep 20 15:06 my_fifo
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l my_nod
prw-rw-r-- 1 aayushi312000 aayushi312000 0 Sep 20 15:06 my_nod
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ 



i312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ strace -c mkfifo my_fifo_str
mkfifo: cannot create fifo 'my_fifo_str': File exists
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         7           read
  0.00    0.000000           0         4           write
  0.00    0.000000           0        10           close
  0.00    0.000000           0        19           mmap
  0.00    0.000000           0         5           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         2           pread64
  0.00    0.000000           0         2         2 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         2 statfs
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         1           set_tid_address
  0.00    0.000000           0        31        23 openat
  0.00    0.000000           0         1         1 mknodat
  0.00    0.000000           0         8           newfstatat
  0.00    0.000000           0         1           set_robust_list
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
  0.00    0.000000           0         1           rseq
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000           0       103        29 total



aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ strace -c mknod my_nod_str
mknod: missing operand after ‘my_nod_str’
Try 'mknod --help' for more information.
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 33.73    0.000284          14        19           mmap
 16.75    0.000141           7        19        11 openat
  9.98    0.000084          16         5           mprotect
  7.60    0.000064           8         8           newfstatat
  5.46    0.000046           6         7           read
  5.46    0.000046           4        10           close
  4.04    0.000034          34         1           munmap
  3.56    0.000030           7         4           write
  3.56    0.000030          15         2         2 statfs
  2.26    0.000019           6         3           brk
  1.07    0.000009           4         2           pread64
  1.07    0.000009           4         2         2 access
  0.95    0.000008           4         2         1 arch_prctl
  0.95    0.000008           8         1           set_tid_address
  0.95    0.000008           8         1           prlimit64
  0.95    0.000008           8         1           getrandom
  0.83    0.000007           7         1           set_robust_list
  0.83    0.000007           7         1           rseq
  0.00    0.000000           0         1           execve
------ ----------- ----------- --------- --------- ----------------
100.00    0.000842           9        90        16 total





aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ cc 19.c
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ./a.out
Succesfully created FIFO file. Check using `ll` or `ls -l` command!
Succesfully created FIFO file. Check using `ll` or `ls -l` command!
aayushi312000@aayushi312000-81WB:~/MTech/SS/SystemSoftware/Hands_onL2$ ls -l
total 132
-rw-rw-r-- 1 aayushi312000 aayushi312000  1576 Sep 20 15:20 10a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1525 Sep 20 15:20 10b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1479 Sep 20 15:20 10c.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2127 Sep 20 15:20 11.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1806 Sep 20 15:19 12.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  3181 Sep 20 15:33 19.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16088 Sep 18 18:45 1a
-rw-rw-r-- 1 aayushi312000 aayushi312000  1690 Sep 20 11:58 1a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2130 Sep 20 12:19 1b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  2090 Sep 20 12:26 1c.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  5528 Sep 20 12:31 2.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1727 Sep 20 12:33 3.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1482 Sep 20 12:34 4.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  5164 Sep 20 12:35 5.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1144 Sep 20 12:36 6.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1319 Sep 20 12:36 7.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1332 Sep 20 12:37 8a.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1387 Sep 20 12:40 8b.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1401 Sep 20 12:40 8c.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1489 Sep 20 12:40 8d.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1583 Sep 20 12:44 8e.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1692 Sep 20 12:45 8f.c
-rw-rw-r-- 1 aayushi312000 aayushi312000  1682 Sep 20 12:46 8g.c
-rw-rw-r-- 1 aayushi312000 aayushi312000   961 Sep 20 12:49 9.c
-rwxrwxr-x 1 aayushi312000 aayushi312000 16088 Sep 20 15:33 a.out
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:33 mkfifo_lib
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:33 mknod_sys
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:06 my_fifo
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:08 my_fifo_str
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:06 my_nod
prw-rw-r-- 1 aayushi312000 aayushi312000     0 Sep 20 15:07 my_nod_str


========================================================================================================
*/


