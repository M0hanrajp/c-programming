/* Understanding fork 
 */
#include <stdio.h>
#include <unistd.h> // getpid
#include <sys/types.h> // pid_t

void childProcess(pid_t *pid) {
    pid_t cpid = getpid();
    printf("I'm inside child process!!, pid:: %d & cpid:: %d\n", *pid, cpid);
}

void parentProcess(pid_t *pid) {
    pid_t ppid = getpid();
    printf("I'm inside parent process!!, pid:: %d & ppid:: %d\n", *pid, ppid);
}

int main(void) {
    int forkRetVal = 0;
    forkRetVal = fork();

    if(forkRetVal == 0)
        childProcess(&forkRetVal);
    else
        parentProcess(&forkRetVal);
    return 0;
}

// output
/*
- The output depends the CPU scheduling, we can see some time child is printed out first
- important thing, fork returns non zero value (child's process id) to parent process.
- fork returns 0 to child process.

// output with ppid and cpid (refer the functions)
$ gcc -g -Wall 1_understanding_fork.c
$ ./a.out
I'm inside parent process!!, pid:: 46528
I'm inside child process!!, pid:: 46529
...
$ ./a.out
I'm inside parent process!!, pid:: 46546
I'm inside child process!!, pid:: 46547
$ ./a.out
I'm inside child process!!, pid:: 46549     << child process is printed first
I'm inside parent process!!, pid:: 46548
$ ./a.out
I'm inside child process!!, pid:: 46551     << child process is printed first
I'm inside parent process!!, pid:: 46550
...
$ ./a.out
I'm inside parent process!!, pid:: 46552
I'm inside child process!!, pid:: 46553

// output with return value of fork()
$ ./a.out
I'm inside parent process!!, pid:: 46994
I'm inside child process!!, pid:: 0
$ ./a.out
I'm inside parent process!!, pid:: 46996
I'm inside child process!!, pid:: 0
$ ./a.out
I'm inside parent process!!, pid:: 46998
I'm inside child process!!, pid:: 0
...
$ ./a.out
I'm inside parent process!!, pid:: 47008
I'm inside child process!!, pid:: 0
$ ./a.out
I'm inside child process!!, pid:: 0
I'm inside parent process!!, pid:: 47010
$ ./a.out
I'm inside parent process!!, pid:: 47012
I'm inside child process!!, pid:: 0

*/
