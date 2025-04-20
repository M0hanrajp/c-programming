/* There are two files
 * Copy contents from both files (line by line) in an alternating manner
 * paste the contents in third file
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void copyAlternatingLines(const char *sourceFileA, const char *sourceFileB, const char *targetFile) {
    FILE *sfa = fopen(sourceFileA, "r");
    FILE *sfb = fopen(sourceFileB, "r");
    FILE  *tf = fopen(targetFile,  "w");
    bool sfaEOF = false, sfbEOF = false;
    char sbuff[1024];

    while (!sfaEOF || !sfbEOF) {
        if(!sfaEOF) {
            fgets(sbuff, sizeof(sbuff), sfa);
            if(feof(sfa)) {
                sfaEOF = true;
            } else {
                fputs(sbuff, tf);
            }
            memset(sbuff, 0, sizeof(sbuff));
        }
        if(!sfbEOF) {
            fgets(sbuff, sizeof(sbuff), sfb);
            if(feof(sfb)) {
                sfbEOF = true;
            } else {
                fputs(sbuff, tf);
            }
            memset(sbuff, 0, sizeof(sbuff));
        }
    }
}

int main(void) {
    copyAlternatingLines("edir/e_problem_sfa.txt", "edir/e_problem_sfb.txt", "edir/e_problem_tf.txt");
    return 0;
}

// output
/* Before copying

$ cat edir/e_problem_sfa.txt
1. Identify the key components and types of autonomous robots.
3. Describe the basic principles of embodied AI in robotics.

// Length of sfb is greater than sfa
$ cat edir/e_problem_sfb.txt
2. Recognize the main elements of robotic systems and architecture.
4. List the primary sensors and perception techniques used in robotics.
5. Outline the fundamental concepts of localization and mapping in autonomous navigation.
6. Recall the basic principles of control systems in robotics.

// final output
$ cat edir/e_problem_tf.txt
1. Identify the key components and types of autonomous robots.
2. Recognize the main elements of robotic systems and architecture.
3. Describe the basic principles of embodied AI in robotics.
4. List the primary sensors and perception techniques used in robotics.
5. Outline the fundamental concepts of localization and mapping in autonomous navigation.
6. Recall the basic principles of control systems in robotics.
*/
