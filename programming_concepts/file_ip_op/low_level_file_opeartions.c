// Using system calls in file operations.
/* A system call can be defined as a request to the operating system to do something on behalf of the program. 
 * During the execution of a system call, the mode is change from user mode to kernel mode (or system mode) 
 * to allow the execution of the system call.
 *
 * When a system call causes an error, it returns -1 and store the error number in a variable called “errno” 
 * given in a header file called /usr/include/errno.h.
 * function perror can be used to print a diagnostic message.
 */
// for the meaning of functions refer systems programming pdf in this directory
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#define CYCLE 1

void copyFileWithSysCalls(const char *sFile, const char *tFile, char *buffer) {

    int sfd = 0, tfd = 0, nbr = 0; 
    // sf - source file descriptor, tf - target file descriptor, nrb - number of bytes read.
    
    sfd = open(sFile, O_RDONLY);
    if(sfd == -1){ perror("");}
    tfd = open(tFile, O_CREAT | O_WRONLY, S_IWRITE | S_IRWXU);
    if(tfd == -1){ perror("");}
    printf("sfd :: %d & tfd :: %d\n", sfd, tfd);

    while ((nbr = read(sfd, buffer, 128)) != 0) {
        printf("Number of bytes read = %d\n", nbr);
        write(tfd, buffer, nbr); // write the amount of bytes read from buffer
    }
    close(sfd);
    close(tfd);
}

int main(void) {
    char buffer[128];
    printf("sizeof(buffer) :: %zu\n", sizeof(buffer));
    copyFileWithSysCalls("fdir/test-file.txt", "fdir/low-level.txt", buffer);
    return 0;
}
/* 
$ ./a.out
sfd :: 3 & tfd :: 4
Number of bytes read = 128
Number of bytes read = 128
Number of bytes read = 128
Number of bytes read = 41
*/

/* constant that can be used to set permissions (sys/stat.h)
S_IREAD --- read permission for the owner
S_IWRITE --- write permission for the owner
S_IEXEC --- execute/search permission for the owner
S_IRWXU --- read, write, execute permission for the user
S_IRGRP – read for group
S_IWGRP – write for group
S_IXGRP – execute for group
S_IRWXG – read, write, execute for the group
S_IROTH --- read for others
S_IWOTH – write for others
S_IXOTH -- execute for others
S_IRWXO – read , write , execute for others
For example, to create a file with read and write access only to user, we can do the
following.
creat(“myfile”, S_IREAD | S_IWRITE);

// flag codes
O_RDONLY -- opens file for read only
O_WRONLY – opens file for write only
O_RDWR – opens file for reading and writing
O_NDELAY – prevents possible blocking
O_APPEND --- opens the file for appending
Copyright @ 2009 Ananda Gunawardena
O_CREAT -- creates the file if it does not exists
O_TRUNC -- truncates the size to zero
O_EXCL – produces an error if the O_CREAT bit is on and file exists
*/
