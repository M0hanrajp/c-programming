#include <stdio.h>
#include "conditional_compliation.h"

#define MACRO_NAME

int main(void) {

#ifdef MACRO_NAME // checks if MACRO_NAME macro is defined
                  // if yes, then below statement is executed 
    printf("Macro name is defined\n");
#else
    // if MACRO_NAME macro is not defined then below statement is executed
    // Similar to if-else statement
    printf("Macro is not defined\n");
#endif

#ifndef MACRO_CODE // if not defined
    printf("Macro code is not defined\n");
#else
    printf("Macro code and are defined\n");
#endif

    // called here, defined in conditional_compilation.h
    // for a proper execution & best practice of using header and multiple c files see multiple_file_compliation/
    print();

    // usecases
    /* In a situation where a code is modified to client specific needs,
     * if client needs are not met then code can be reverted back to it's original state.
     *
     * If you want a peice of code that needs to be executed on specific set of hardware
     * define a macro by hardware type and the piece of code will only be executed if the macro is defined.
     *
     * when using multiple source files, during compilation the compiler will add the code that is
     * mentioned in the header file, this creates multiple copies and creates a error, in order to avoid this
     * use #ifndef or #ifdef conditions.
     *
     * apart from these we can use #if, #elif, #else, #endif (here #if condition should be non zero then subsequent
     * statements are carried out.
     *
     */
    return 0;
}
