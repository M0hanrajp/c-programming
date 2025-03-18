// A program to format dispaly of data through printf
#include <stdio.h>

int main(void) {
    /* the general format of printf
     * printf("format string", list of variables);
     * format specifiers begin with %, escape sequence with \
     *
     * printf reads the "format string" from left to right (as long as it encounters % or \
     * When it encounters a %, it reads the first variable (from left after `,`) [Needs verification]
     * when it encounters \n it takes cursor to the next line.
     *
     *
     * the general format of scanf
     * scanf("format string", list of addresses of variables)
     *
     */

    printf("Num is %d \n", 45);
    printf("Num is %.2f \n", 0.3445); // print only 2 decimal places
    printf("Num is %6d \n", 45);
    printf("Num is %-6d \n", 45); // same logic can be used in string
    printf("Str is %10s \n", "console"); // reserves 10 cols with right justification (positive)

    return 0;
}
