#include <stdio.h>
#include "extern_storage_class.h"

// extern - static duration and external linkage (unless already declared internal)
/* It can be used with function and object declarations in both file and block scope (excluding function parameter lists)
 * If extern appears on a redeclaration of an identifier that was already declared with internal linkage, 
 * the linkage remains internal. 
 * Otherwise (if the prior declaration was external, no-linkage, or is not in scope), the linkage is external.
 */

int a = 1; 
/* This filescope definition of a variable 
 * compiler during linkage, will be able to reference this as the definition
 * for the declaration of extern int a that is provided in extern_storage_class.h
 */

int b;
/* This filescope definition of a variable 
 * compiler during linkage, will be able to reference this as the definition
 * for the declaration of extern int a that is provided in extern_storage_class.h
 */

void incrementExternVariable(void) {
    a++;
}

void printExternVariable(void) {
    printf("Value of extern variable :: %d\n", a);
}

void multiplyExternByTwo(void) {
    a *= 2;
}

void checkValueofB(void) {
    printf("Value of extern variable b :: %d\n", b);
}
