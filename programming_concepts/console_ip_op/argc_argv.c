// A file copy program to copy file
/* we are using command line arguments to receive the filename 
 * program behaves as a unix command line utility
 * program binary is copied to /bin folder to see the effect
 */
#include <stdio.h>
void fileCopy(const char *sfile, const char *tfile) {
    FILE *sf = fopen(sfile, "r");
    if(sf == NULL){ perror("");}

    FILE *tf = fopen(tfile, "w");
    if(tf == NULL){ perror("");}

    int   fc = 0;

    while ((fc = fgetc(sf)) != EOF)
        fputc(fc, tf);

    fclose(sf);
    fclose(tf);
}

int main(int argc, char *argv[]) {
    /* Here argc means argument count and argv means argument vector.
     * argv - array of pointers to strings.
     * argc - number of strings
     * argv[0] will be name of executable.
     * The first argument is the number of parameters passed plus one 
     * to include the name of the program that was executed to get those process running.
     * 
     * Thus, argc is always greater than zero and argv[0] is the name of the executable 
     * (including the path) that was run to begin this process.
     * For example, if we run

        #include <stdio.h>
        int main( int argc, char *argv[] ) {
            printf( "argv[0]:  %s\n", argv[0] );
            return 0;
        }
     * Here we compile this code and first compile and run it so that the executable name is 
     * a.out and then we compile it again and run it so the executable name is arg:

        % gcc argument.0.c
        % ./a.out 
        argv[0]:  ./a.out
        % gcc -o arg argument.0.c
        % ./arg 
        argv[0]:  ./arg
     */

    if(argc != 3){ perror("");}

    fileCopy(argv[1], argv[2]);
    /* oxblood is not created while the program is executed.
     * we are trying to copy contents of poem to oxblood
     */
    return 0;
}

/*
// source file
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/console_ip_op$ ls fdir/
poem

// program name is being run with file directories
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/console_ip_op$ filecopy fdir/poem fdir/oxblood
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/console_ip_op$ cat fdir/oxblood
Oxblood

By Andy Roberts
I squeeze into nine pounds of my dead father’s
Brooks Brothers wingtips,
heels worn down from running between women.
Slip on his herringbone suit coat, flash on him
snapping his fingers, popping his Dentyne,
swinging along to “The Great Pretender.”
The suit’s too big, it can go to Goodwill.
But they don’t make shoes like these anymore.
The old tin of oxblood I prize open,
shift to my nose and remember
all he ever needed was Nat King Cole,
a slice of phosphorescent moon
and a blonde in the passenger seat
down Wainwright Road to the quarry.

// the generated binary is copied to /bin directory
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/console_ip_op$ ls /bin/filecopy
/bin/filecopy 

*/
