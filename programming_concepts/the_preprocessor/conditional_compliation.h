/* myfile.h */
#ifndef CONDITIONAL_COMPILATION_H /* 1. Has this symbol been defined yet? */
#define CONDITIONAL_COMPILATION_H /* 2. If not, define it now */

/* --- all declarations, definitions, etc. go here --- */
#include <stdio.h> // will be skipped if already included
                   // the following way of defining a function is not preferred
void print(void) {
    printf("Inside print function in .h file\n");
}

/* end of guarded section */
#endif  /* 3. Close the “if not defined” */
