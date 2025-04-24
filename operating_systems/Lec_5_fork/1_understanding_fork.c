/* Understanding fork 
 */
#include <stdio.h>
#include <unistd.h> // getpid
#include <sys/types.h> // pid_t

void childProcess(pid_t *pid) {
    pid_t cpid = getpid();
    printf("I'm inside child process!!, %d & cpid using getpid():: %d\n", *pid, cpid);
}

void parentProcess(pid_t *pid) {
    pid_t ppid = getpid();
    printf("I'm inside parent process!!, fork returned:: %d & ppid using getpid():: %d\n", *pid, ppid);
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
$ ./a.out
I'm inside parent process!!, fork returned:: 56443 & ppid using getpid():: 56442
I'm inside child process!!, 0 & cpid using getpid():: 56443

$ ./a.out
I'm inside parent process!!, fork returned:: 56447 & ppid using getpid():: 56446
I'm inside child process!!, 0 & cpid using getpid():: 56447

// Here CPU decided to priortize child process execution first
$ ./a.out
I'm inside child process!!, 0 & cpid using getpid():: 56483
I'm inside parent process!!, fork returned:: 56483 & ppid using getpid():: 56482

*/
