/* Q: What does identical address space mean when a child process is created by forking the parent process
 * This program modifies a value in both child and parent
 * and checks what is the value reflected.
 * // consider reading below links to understand more on how the memory space is created/assigned by OS
 * https://stackoverflow.com/questions/63831450/why-doesnt-address-change-in-forked-process?rq=3
 * https://stackoverflow.com/questions/27486873/fork-system-call-and-memory-space-of-the-process?rq=3
 * https://stackoverflow.com/questions/9724473/how-the-memory-is-mapped-when-fork-is-used?rq=3
 * https://stackoverflow.com/questions/8353641/parent-and-child-address-space-confusion?rq=3
 * // has diagram
 * https://stackoverflow.com/questions/7253659/why-the-address-of-variable-of-child-process-and-parent-process-is-same?rq=3
 * https://stackoverflow.com/questions/5365580/fork-same-memory-addresses?rq=3
 * https://unix.stackexchange.com/questions/207918/what-does-it-mean-fork-will-copy-address-space-of-original-process
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Note [c] - child process, [p] - parent process
void childProcess(int *var) {
    printf("pid of child process : %d\n", getpid());
    printf("[c] Address of the variable local to main() = %p\n", var);
    printf("[c] Address of the variable local to childProcess = %p\n", &var);
    printf("[c] Value of the variable in child process = %d\n", *var);
    // modify the value in child
    //*var = 18;
}

void parentProcess(int *var) {
    printf("pid of parent process : %d\n", getpid());
    printf("[p] Address of the variable local to main() = %p\n", var);
    printf("[p] Address of the variable local to parentProcess = %p\n", &var);
    printf("[p] Value of the variable in parent process = %d\n", *var);
    // modify value in parent
    //*var = 8;
}

int main(void) {
    int a = 1;
    pid_t pid = fork();
    // execution starts parallely
    if(pid > 0)
        parentProcess(&a);
    else 
        childProcess(&a);

    // this statement will be executed by both parent and child process
    printf("[c & p will execute this statement] Value of a = %d [pid = %d]\n", a, getpid());
    return 0;
}

// output
/*
 * Conclusion modification made in respective processes are not reflected in their parent/child process
 * 
<< Case 1, value of a is changed to 8 in parent process >>
----------------------------------------------------------
$ ./a.out
pid of parent process : 58756
[p] Address of the variable local to main() = 0x7ffdfc91c180
[p] Address of the variable local to parentProcess = 0x7ffdfc91c168
[p] Value of the variable in parent process = 1 
[c & p will execute this statement] Value of a = 8 [pid = 58756] <------ parent
pid of child process : 58757
[c] Address of the variable local to main() = 0x7ffdfc91c180
[c] Address of the variable local to childProcess = 0x7ffdfc91c168
[c] Value of the variable in child process = 1
[c & p will execute this statement] Value of a = 1 [pid = 58757] <------ child

<< Case 2, value of a is changed to 18 in child process >>
----------------------------------------------------------
$ ./a.out
pid of parent process : 58803
pid of child process : 58804
[p] Address of the variable local to main() = 0x7ffed3155c50
[c] Address of the variable local to main() = 0x7ffed3155c50
[p] Address of the variable local to parentProcess = 0x7ffed3155c38
[c] Address of the variable local to childProcess = 0x7ffed3155c38
[p] Value of the variable in parent process = 1
[c] Value of the variable in child process = 1
[c & p will execute this statement] Value of a = 1 [pid = 58803] <------ parent
[c & p will execute this statement] Value of a = 18 [pid = 58804] <----- child

*/
