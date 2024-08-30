
/*
============================================================================
Name : 2.c
Author : Prajapati Aayushi Sadashivbhai
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
              identify all the process related information in the corresponding proc directory.
Date: 8th Aug, 2024.
============================================================================
*/
#include<stdio.h>
int main(){
 for(;;);
}

/*===========================================================================
OUTPUT:
aayushi312000@aayushi312000-81WB:/proc/8459$ ls
arch_status         fd                 net            setgroups
attr                fdinfo             ns             smaps
autogroup           gid_map            numa_maps      smaps_rollup
auxv                io                 oom_adj        stack
cgroup              ksm_merging_pages  oom_score      stat
clear_refs          ksm_stat           oom_score_adj  statm
cmdline             limits             pagemap        status
comm                loginuid           patch_state    syscall
coredump_filter     map_files          personality    task
cpu_resctrl_groups  maps               projid_map     timens_offsets
cpuset              mem                root           timers
cwd                 mountinfo          sched          timerslack_ns
environ             mounts             schedstat      uid_map
exe                 mountstats         sessionid      wchan


aayushi312000@aayushi312000-81WB:/proc/8459$ cat stat
8459 (a.out) R 2712 8459 2712 34816 2712 4194304 111 0 0 0 3318 0 0 0 20 0 1 0 1047146 2543616 224 18446744073709551615 94767400398848 94767400399169 140725566202960 0 0 0 0 0 0 0 0 0 17 3 0 0 0 0 0 94767400410608 94767400411152 94767414734848 140725566210807 140725566210815 140725566210815 140725566214128 0


aayushi312000@aayushi312000-81WB:/proc/8459$ cd fd
aayushi312000@aayushi312000-81WB:/proc/8459/fd$ ls
0  1  2


=============================================================================*/

