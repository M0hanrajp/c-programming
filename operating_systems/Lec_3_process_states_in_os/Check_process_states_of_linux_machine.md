### Checking process states of Linux machine.

Look at the STAT column:https://man7.org/linux/man-pages/man1/ps.1.html
```bash
PROCESS STATE CODES         top
       Here are the different values that the s, stat and state output
       specifiers (header "STAT" or "S") will display to describe the
       state of a process:

               D    uninterruptible sleep (usually I/O)
               I    idle kernel thread
               R    running or runnable (on run queue)
               S    interruptible sleep (waiting for an
                    event to complete)
               T    stopped by job control signal
               t    stopped by debugger during the tracing
               W    paging (not valid since Linux 2.6)
               X    dead (should never be seen)
               Z    defunct (“zombie”) process, terminated
                    but not reaped by its parent

       For BSD formats and when the stat keyword is used, additional
       characters may be displayed:

               <    high-priority (not nice to other users)
               N    low-priority (nice to other users)
               L    has pages locked into memory (for real-
                    time and custom I/O)
               s    is a session leader
               l    is multi-threaded (using CLONE_THREAD,
                    like NPTL pthreads do)
               +    is in the foreground process group
==========================================================================
$ ps aux
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
root           1  0.0  0.1 166036 11336 ?        Ss   17:26   0:00 /sbin/init
root           2  0.0  0.0   2776  1924 ?        Sl   17:26   0:00 /init
root           6  0.0  0.0   2776   132 ?        Sl   17:26   0:00 plan9 --control-socket 7 --log-level 4 --server-fd 8 --pipe-fd 10 --log-truncate
root          62  0.0  0.1  47804 14516 ?        S<s  17:26   0:00 /lib/systemd/systemd-journald
root          86  0.0  0.0  21708  5440 ?        Ss   17:26   0:00 /lib/systemd/systemd-udevd
systemd+      90  0.0  0.1  26200 13488 ?        Ss   17:26   0:00 /lib/systemd/systemd-resolved
systemd+      92  0.0  0.0  89364  6516 ?        Ssl  17:26   0:00 /lib/systemd/systemd-timesyncd
root         157  0.0  0.0   4308  2776 ?        Ss   17:26   0:00 /usr/sbin/cron -f -P
message+     159  0.0  0.0   8580  4736 ?        Ss   17:26   0:00 @dbus-daemon --system --address=systemd: --nofork --nopidfile --systemd-activation --syslog-only
root         165  0.0  0.2  30080 18692 ?        Ss   17:26   0:00 /usr/bin/python3 /usr/bin/networkd-dispatcher --run-startup-triggers
syslog       166  0.0  0.0 222404  7320 ?        Ssl  17:26   0:00 /usr/sbin/rsyslogd -n -iNONE
root         169  0.0  0.0  15332  7292 ?        Ss   17:26   0:00 /lib/systemd/systemd-logind
root         177  0.1  0.6 2246692 52736 ?       Ssl  17:26   0:14 /usr/bin/containerd
root         198  0.0  0.0   3240  1068 hvc0     Ss+  17:26   0:00 /sbin/agetty -o -p -- \u --noclear --keep-baud console 115200,38400,9600 vt220
root         201  0.0  0.0   3196  1092 tty1     Ss+  17:26   0:00 /sbin/agetty -o -p -- \u --noclear tty1 linux
root         216  0.0  0.2 107160 21152 ?        Ssl  17:26   0:00 /usr/bin/python3 /usr/share/unattended-upgrades/unattended-upgrade-shutdown --wait-for-signal
root         255  0.0  0.9 2413944 75504 ?       Ssl  17:26   0:02 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
root         540  0.0  0.0   2784   208 ?        Ss   17:26   0:00 /init
root         541  0.0  0.0   2784   212 ?        R    17:26   0:00 /init
mpunix       542  0.0  0.1  10468  9724 pts/0    Ss   17:26   0:00 -bash
root         544  0.0  0.0   7528  5044 pts/1    Ss   17:26   0:00 /bin/login -f
mpunix       635  0.0  0.1  17072  9424 ?        Ss   17:26   0:00 /lib/systemd/systemd --user
mpunix       636  0.0  0.0 168964  3564 ?        S    17:26   0:00 (sd-pam)
mpunix       704  0.0  0.1   9932  8716 pts/1    S+   17:26   0:00 -bash
root        1016  0.0  0.0   2784   212 ?        Ss   17:27   0:00 /init
root        1017  0.0  0.0   2784   216 ?        S    17:27   0:00 /init
mpunix      1023  0.0  0.1   9952  9080 pts/2    Ss+  17:27   0:00 -bash
root        1220  0.0  0.0   2784   212 ?        Ss   17:27   0:00 /init
root        1221  0.0  0.0   2784   216 ?        S    17:27   0:00 /init
mpunix      1226  0.0  0.1   9952  8940 pts/3    Ss+  17:27   0:00 -bash
root        1636  0.0  0.0   2784   212 ?        Ss   18:51   0:00 /init
root        1637  0.0  0.0   2784   216 ?        S    18:51   0:00 /init
mpunix      1642  0.0  0.1   9952  9112 pts/4    Ss   18:51   0:00 -bash
mpunix      1951  0.0  0.1  12248  8660 pts/4    Tl   18:59   0:00 /opt/nvim/usr/bin/nvim
mpunix      1955  1.3  0.4  38436 36476 ?        Ssl  18:59   1:33 /opt/nvim/usr/bin/nvim --embed
mpunix      2016  0.0  0.1  12284  8368 pts/4    Sl+  19:43   0:00 /opt/nvim/usr/bin/nvim
mpunix      2020  2.0  0.5 340464 45240 ?        Ssl  19:43   1:25 /opt/nvim/usr/bin/nvim --embed
mpunix      2496  0.0  0.0   7484  3244 pts/0    R+   20:53   0:00 ps aux
```
### Trace Process transitions
https://man7.org/linux/man-pages/man1/strace.1.html

- Use strace to monitor system calls and process execution:
    - `strace -f -e trace=all chrt -r 1 ./program`
For real-time tracking:`watch -n 1 "ps -eo pid,ppid,stat,cmd"`
```bash
$ sudo strace -f -e trace=all chrt -r 1 /usr/sbin/rsyslogd
execve("/usr/bin/chrt", ["chrt", "-r", "1", "/usr/sbin/rsyslogd"], 0x7ffc8861ae80 /* 14 vars */) = 0
brk(NULL)                               = 0x562b43517000
arch_prctl(0x3001 /* ARCH_??? */, 0x7ffccf850620) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f3adff60000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=35335, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 35335, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f3adff57000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\315A\vq\17\17\tLh2\355\331Y1\0m"..., 68, 896) = 68
newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f3adfd2e000
mprotect(0x7f3adfd56000, 2023424, PROT_NONE) = 0
mmap(0x7f3adfd56000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f3adfd56000
mmap(0x7f3adfeeb000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7f3adfeeb000
mmap(0x7f3adff44000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x7f3adff44000
mmap(0x7f3adff4a000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f3adff4a000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f3adfd2b000
arch_prctl(ARCH_SET_FS, 0x7f3adfd2b740) = 0
set_tid_address(0x7f3adfd2ba10)         = 3183
set_robust_list(0x7f3adfd2ba20, 24)     = 0
rseq(0x7f3adfd2c0e0, 0x20, 0, 0x53053053) = 0
mprotect(0x7f3adff44000, 16384, PROT_READ) = 0
mprotect(0x562b130a6000, 4096, PROT_READ) = 0
mprotect(0x7f3adff9a000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7f3adff57000, 35335)           = 0
getrandom("\x58\x78\x6b\x2b\x83\x3b\x66\xe5", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x562b43517000
brk(0x562b43538000)                     = 0x562b43538000
...
...
openat(AT_FDCWD, "/usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache", O_RDONLY) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=27002, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 27002, PROT_READ, MAP_SHARED, 3, 0) = 0x7f3adff59000
close(3)                                = 0
...
...
sched_get_priority_min(SCHED_RR)        = 1
sched_get_priority_max(SCHED_RR)        = 99
sched_setscheduler(0, SCHED_RR, [1])    = 0
execve("/usr/sbin/rsyslogd", ["/usr/sbin/rsyslogd"], 0x7ffccf850810 /* 14 vars */) = 0
brk(NULL)                               = 0x55d4c4e00000
arch_prctl(0x3001 /* ARCH_??? */, 0x7ffcff5ed1b0) = -1 EINVAL (Invalid argument)
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f325e6f8000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=35335, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 35335, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f325e6ef000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libz.so.1", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=108936, ...}, AT_EMPTY_PATH) = 0
mmap(NULL, 110776, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f325e6d3000
mprotect(0x7f325e6d5000, 98304, PROT_NONE) = 0
...
...
[pid  3184] --- SIGTTOU {si_signo=SIGTTOU, si_code=SI_USER, si_pid=3184, si_uid=104} ---
[pid  3184] rt_sigreturn({mask=[]})     = 0
[pid  3184] socket(AF_UNIX, SOCK_DGRAM|SOCK_CLOEXEC, 0) = 1
[pid  3184] connect(1, {sa_family=AF_UNIX, sun_path="/dev/log"}, 110) = 0
[pid  3184] sendto(1, "<46>Apr  3 21:05:52 rsyslogd: rs"..., 63, MSG_NOSIGNAL, NULL, 0) = 63
[pid  3184] sendto(1, "<46>Apr  3 21:05:52 rsyslogd: rs"..., 62, MSG_NOSIGNAL, NULL, 0) = 62
[pid  3184] sendto(1, "<46>Apr  3 21:05:52 rsyslogd: [o"..., 131, MSG_NOSIGNAL, NULL, 0) = 131
[pid  3185] <... poll resumed>)         = 1 ([{fd=3, revents=POLLIN}])
[pid  3184] rt_sigprocmask(SIG_BLOCK, [HUP TERM CHLD],  <unfinished ...>
[pid  3185] recvmsg(3,  <unfinished ...>
[pid  3184] <... rt_sigprocmask resumed>[], 8) = 0
[pid  3185] <... recvmsg resumed>{msg_name=NULL, msg_namelen=0, msg_iov=[{iov_base="<46>Apr  3 21:05:52 rsyslogd: rs"..., iov_len=8096}], msg_iovlen=1, msg_control=[{cmsg_len=32, cmsg_level=SOL_SOCKET, cmsg_type=SO_TIMESTAMP_OLD, cmsg_data={tv_sec=1743694552, tv_usec=48376}}, {cmsg_len=28, cmsg_level=SOL_SOCKET, cmsg_type=SCM_CREDENTIALS, cmsg_data={pid=3184, uid=104, gid=111}}], msg_controllen=64, msg_flags=0}, MSG_DONTWAIT) = 63
[pid  3184] pselect6(0, NULL, NULL, NULL, {tv_sec=600, tv_nsec=0}, {sigmask=[], sigsetsize=8} <unfinished ...>
[pid  3185] mmap(NULL, 8392704, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_STACK, -1, 0) = 0x7f325cf21000
[pid  3185] mprotect(0x7f325cf22000, 8388608, PROT_READ|PROT_WRITE) = 0
[pid  3185] rt_sigprocmask(SIG_BLOCK, ~[], ~[KILL SEGV STOP TTIN RTMIN RT_1], 8) = 0
[pid  3185] clone3({flags=CLONE_VM|CLONE_FS|CLONE_FILES|CLONE_SIGHAND|CLONE_THREAD|CLONE_SYSVSEM|CLONE_SETTLS|CLONE_PARENT_SETTID|CLONE_CHILD_CLEARTID, child_tid=0x7f325d721910, parent_tid=0x7f325d721910, exit_signal=0, stack=0x7f325cf21000, stack_size=0x7ffe40, tls=0x7f325d721640}strace: Process 3187 attached
 <unfinished ...>
[pid  3187] futex(0x7f325d721c58, FUTEX_WAIT_PRIVATE, 2, NULL <unfinished ...>
[pid  3185] <... clone3 resumed> => {parent_tid=[3187]}, 88) = 3187
[pid  3185] sched_setscheduler(3187, SCHED_RR, [1]) = 0
[pid  3185] rt_sigprocmask(SIG_SETMASK, ~[KILL SEGV STOP TTIN RTMIN RT_1], NULL, 8) = 0
[pid  3185] futex(0x7f325d721c58, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... futex resumed>)        = 0
[pid  3185] <... futex resumed>)        = 1
[pid  3187] futex(0x7f325d721c58, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3185] futex(0x55d4c4e25008, FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME, 0, NULL, FUTEX_BITSET_MATCH_ANY <unfinished ...>
[pid  3187] <... futex resumed>)        = 0
[pid  3187] rseq(0x7f325d721fe0, 0x20, 0, 0x53053053) = 0
[pid  3187] set_robust_list(0x7f325d721920, 24) = 0
[pid  3187] rt_sigprocmask(SIG_SETMASK, ~[KILL SEGV STOP TTIN RTMIN RT_1], NULL, 8) = 0
[pid  3187] rt_sigprocmask(SIG_BLOCK, ~[SEGV TTIN RTMIN RT_1], NULL, 8) = 0
[pid  3187] prctl(PR_SET_NAME, "rs:main Q:Reg") = 0
[pid  3187] futex(0x55d4c4e25008, FUTEX_WAKE_PRIVATE, 2147483647) = 1
[pid  3185] <... futex resumed>)        = 0
[pid  3187] mmap(0x7f3254000000, 67108864, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE, -1, 0 <unfinished ...>
[pid  3185] futex(0x55d4c4e24fb8, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... mmap resumed>)         = 0x7f3254000000
[pid  3185] <... futex resumed>)        = 0
[pid  3187] mprotect(0x7f3254000000, 135168, PROT_READ|PROT_WRITE <unfinished ...>
[pid  3185] poll([{fd=3, events=POLLIN}], 1, -1 <unfinished ...>
[pid  3187] <... mprotect resumed>)     = 0
[pid  3187] access("/var/log/syslog", F_OK) = 0
[pid  3187] openat(AT_FDCWD, "/var/log/syslog", O_WRONLY|O_CREAT|O_NOCTTY|O_APPEND|O_CLOEXEC, 0640) = 2
[pid  3187] ioctl(2, TCGETS, 0x7f325d7205d0) = -1 ENOTTY (Inappropriate ioctl for device)
[pid  3187] newfstatat(AT_FDCWD, "/var/log/syslog", {st_mode=S_IFREG|0640, st_size=636898, ...}, 0) = 0
[pid  3187] write(2, "Apr  3 21:05:52 LIN-5CG3350MRD r"..., 75) = 75
[pid  3187] futex(0x55d4c4e25150, FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME, 0, NULL, FUTEX_BITSET_MATCH_ANY <unfinished ...>
[pid  3185] <... poll resumed>)         = 1 ([{fd=3, revents=POLLIN}])
[pid  3185] recvmsg(3, {msg_name=NULL, msg_namelen=0, msg_iov=[{iov_base="<46>Apr  3 21:05:52 rsyslogd: rs"..., iov_len=8096}], msg_iovlen=1, msg_control=[{cmsg_len=32, cmsg_level=SOL_SOCKET, cmsg_type=SO_TIMESTAMP_OLD, cmsg_data={tv_sec=1743694552, tv_usec=53314}}, {cmsg_len=28, cmsg_level=SOL_SOCKET, cmsg_type=SCM_CREDENTIALS, cmsg_data={pid=3184, uid=104, gid=111}}], msg_controllen=64, msg_flags=0}, MSG_DONTWAIT) = 62
[pid  3185] futex(0x55d4c4e25150, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... futex resumed>)        = 0
[pid  3185] <... futex resumed>)        = 1
[pid  3187] futex(0x55d4c4e24f50, FUTEX_WAIT_PRIVATE, 2, NULL <unfinished ...>
[pid  3185] futex(0x55d4c4e24f50, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... futex resumed>)        = -1 EAGAIN (Resource temporarily unavailable)
[pid  3185] <... futex resumed>)        = 0
[pid  3187] futex(0x55d4c4e24f50, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3185] poll([{fd=3, events=POLLIN}], 1, -1 <unfinished ...>
[pid  3187] <... futex resumed>)        = 0
[pid  3185] <... poll resumed>)         = 1 ([{fd=3, revents=POLLIN}])
[pid  3187] write(2, "Apr  3 21:05:52 LIN-5CG3350MRD r"..., 74 <unfinished ...>
[pid  3185] recvmsg(3,  <unfinished ...>
[pid  3187] <... write resumed>)        = 74
[pid  3185] <... recvmsg resumed>{msg_name=NULL, msg_namelen=0, msg_iov=[{iov_base="<46>Apr  3 21:05:52 rsyslogd: [o"..., iov_len=8096}], msg_iovlen=1, msg_control=[{cmsg_len=32, cmsg_level=SOL_SOCKET, cmsg_type=SO_TIMESTAMP_OLD, cmsg_data={tv_sec=1743694552, tv_usec=53478}}, {cmsg_len=28, cmsg_level=SOL_SOCKET, cmsg_type=SCM_CREDENTIALS, cmsg_data={pid=3184, uid=104, gid=111}}], msg_controllen=64, msg_flags=0}, MSG_DONTWAIT) = 131
[pid  3187] futex(0x55d4c4e25154, FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME, 0, NULL, FUTEX_BITSET_MATCH_ANY <unfinished ...>
[pid  3185] futex(0x55d4c4e25154, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... futex resumed>)        = -1 EAGAIN (Resource temporarily unavailable)
[pid  3185] <... futex resumed>)        = 0
[pid  3187] futex(0x55d4c4e24f50, FUTEX_WAIT_PRIVATE, 2, NULL <unfinished ...>
[pid  3185] futex(0x55d4c4e24f50, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3187] <... futex resumed>)        = -1 EAGAIN (Resource temporarily unavailable)
[pid  3185] <... futex resumed>)        = 0
[pid  3187] futex(0x55d4c4e24f50, FUTEX_WAKE_PRIVATE, 1 <unfinished ...>
[pid  3185] poll([{fd=3, events=POLLIN}], 1, -1 <unfinished ...>
[pid  3187] <... futex resumed>)        = 0
[pid  3187] write(2, "Apr  3 21:05:52 LIN-5CG3350MRD r"..., 143) = 143
[pid  3187] futex(0x55d4c4e25150, FUTEX_WAIT_BITSET_PRIVATE|FUTEX_CLOCK_REALTIME, 0, NULL, FUTEX_BITSET_MATCH_ANY^Cstrace: Process 3187 detached
 <detached ...>
```
### Monitoring Process Scheduling

https://man7.org/linux/man-pages/man1/chrt.1.html

Check the current scheduling policy of a process:
- SCHED_OTHER – Normal time-sharing (default)
- SCHED_FIFO – First-in, first-out (non-preemptive)
- SCHED_RR – Round-robin (preemptive)
```bash
$ chrt -p 159
pid 159's current scheduling policy: SCHED_OTHER
pid 159's current scheduling priority: 0
...
$ chrt -p 1
pid 1's current scheduling policy: SCHED_OTHER
pid 1's current scheduling priority: 0
```

### Checking Memory Usage (Main vs. Secondary Memory)
- https://man7.org/linux/man-pages/man1/top.1.html
```bash
$ top
top - 21:14:59 up  3:48,  1 user,  load average: 0.03, 0.04, 0.01
Tasks:  41 total,   1 running,  39 sleeping,   1 stopped,   0 zombie

%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st

MiB Mem :   7579.2 total,   6720.3 free,    577.0 used,    281.9 buff/cache
MiB Swap:   2048.0 total,   2048.0 free,      0.0 used.   6769.3 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
      1 root      20   0  166036  11336   8284 S   0.0   0.1   0:00.95 systemd
      2 root      20   0    2776   1924   1796 S   0.0   0.0   0:00.05 init-systemd(Ub
      6 root      20   0    2776    132    132 S   0.0   0.0   0:00.00 init
     62 root      19  -1   47804  15020  13972 S   0.0   0.2   0:00.44 systemd-journal
     86 root      20   0   21708   5440   4356 S   0.0   0.1   0:01.01 systemd-udevd
     90 systemd+  20   0   26200  13488   8496 S   0.0   0.2   0:00.25 systemd-resolve
     92 systemd+  20   0   89364   6516   5716 S   0.0   0.1   0:00.41 systemd-timesyn
    157 root      20   0    4308   2776   2548 S   0.0   0.0   0:00.04 cron
    159 message+  20   0    8580   4736   4200 S   0.0   0.1   0:00.09 dbus-daemon
```
### IO wait checks
```
$ iostat -x 1
Linux 5.15.167.4-microsoft-standard-WSL2 (LIN-5CG3350MRD)       04/03/25        _x86_64_        (12 CPU)

avg-cpu:  %user   %nice %system %iowait  %steal   %idle
           0.14    0.00    0.04    0.09    0.00   99.73

Device            r/s     rkB/s   rrqm/s  %rrqm r_await rareq-sz     w/s     wkB/s   wrqm/s  %wrqm w_await wareq-sz     d/s     dkB/s   drqm/s  %drqm d_await dareq-sz     f/s f_await  aqu-sz  %util
sda              0.09      5.82     0.03  24.69    0.42    66.69    0.00      0.00     0.00   0.00    0.00     0.00    0.00      0.00     0.00   0.00    0.00     0.00    0.00    0.00    0.00   0.01
sdb              0.01      0.16     0.00   0.00    0.16    21.84    0.00      0.00     0.00   0.00    4.50     2.00    0.00      0.00     0.00   0.00    0.00     0.00    0.00    6.00    0.00   0.00
sdc              3.10     78.61     0.94  23.32    0.56    25.34    2.21     27.15     0.53  19.33    5.60    12.29    0.02     90.09     0.00   7.42    0.21  4038.26    1.89    5.46    0.02   2.92
```
### Lifecycle

https://github.com/ColinIanKing/forkstat?tab=readme-ov-file
```bash
^Cmpunix@LIN-5CG3350MRD:~/c-programming/operating_systems$ sudo forkstat -X
Time     Event     PID     UID    EUID TTY     Info   Duration Process
21:27:09 fork        0               ┬parent          [swapper]
21:27:09 fork     4375               └child           <unknown>
21:27:09 fork        0               ┬parent          [swapper]
21:27:09 fork     4376               └child           <unknown>
21:27:09 comm     4375               ↻                <unknown> -> <unknown>
21:27:09 comm     4376               ↻                <unknown> -> <unknown>
21:27:09 exit     4376               ⇥     0   0.013s <unknown>
21:27:09 exit     4375               ⇥     0   0.014s <unknown>
21:27:49 exit     3751               ⇥     0  unknown <unknown>
21:29:12 fork        0               ┬parent          [swapper]
21:29:12 fork     4377               └child           <unknown>
21:29:12 fork        0               ┬parent          [swapper]
21:29:12 fork     4378               └child           <unknown>
21:29:16 exit     4377               ⇥     0   3.187s <unknown>
21:29:16 exit     4378               ⇥     0   3.187s <unknown>
^C
    Fork     Exec     Exit Coredump     Comm    Clone   Ptrace      Uid      Sid    Total Process
       4        0        5        0        2        0        0        0        0       11 <unknown>
```
