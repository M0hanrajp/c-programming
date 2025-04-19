/* Write a program that helps in appending contents from one file to another file */
#include <stdio.h>

void appendContentsOfFile(const char *sourceFile, const char *targetFile) {
    FILE *sf = fopen(sourceFile, "r+"); // read and write mode, can also use a mode
                                        // if a mode is used then no need of fseek
    FILE *tf = fopen(targetFile, "r");
    int tc = 0;
    // Move pointer of target file to 1 byte before EOF
    fseek(sf, -1, SEEK_END);
    fputc(' ', sf); // here fputc increments the file pointer to the next position
    // Copy from target file to source file
    while ((tc = fgetc(tf)) != EOF) {
        fputc(tc, sf);
    }
    fclose(sf);
    fclose(tf);
}

int main(void) {
    appendContentsOfFile("edir/a_problem.txt", "edir/b_problem.txt");
    return 0;
}

// Be careful when manipulating file on unix like editors
/* if source file has the following text "I wish I"
 * if you check properly
 * _IO_read_ptr = 0x555555559660 "I wish I\n"
 *  _IO_read_end = 0x555555559660 "I wish I\n", _IO_read_base = 0x555555559660 "I wish I\n",
 * there is a new line included
 * Unix-style text files conventionally end with a newline character. 
 * Some editors automatically insert one at the end when you save a file.
 * Link: https://stackoverflow.com/questions/27549718/behaviour-of-fseek-and-seek-end
 */

// How fseek works here ?
/* Before program execution
// soruce file
~/c-programming/programming_concepts/file_ip_op/excercises$ cat edir/a_problem.txt
Carpe

~/c-programming/programming_concepts/file_ip_op/excercises$ hexdump -cC edir/a_problem.txt
0000000    C   a   r   p   e  \n
00000000  43  61  72  70  65  0a                                 |Carpe.|
00000006

// target file
~/c-programming/programming_concepts/file_ip_op/excercises$ cat edir/b_problem.txt
Diem

// After program execution
~/c-programming/programming_concepts/file_ip_op/excercises$ cat edir/a_problem.txt
Carpe Diem

fseek(sf, -1, SEEK_END);
1. This moves the file pointer to 1 byte before the end of a_problem.txt, which is the position of the newline character (0a).
2. At this position I insert the space and then copy chars from other file to source file.

~/c-programming/programming_concepts/file_ip_op/excercises$ hexdump -cC edir/a_problem.txt
<offset>    < chars in hexadecimal representation>                   <ascii text representation>
0000000    C   a   r   p   e       D   i   e   m  \n
00000000  43  61  72  70  65  20  44  69  65  6d  0a                 |Carpe Diem.|
0000000b
43 -> C
61 -> a
72 -> r
70 -> p
65 -> e
20 -> Space ( )
44 -> D
69 -> i
65 -> e
6d -> m
0a -> Newline (\n)
ASCII Representation: |Carpe Diem.|
*/
