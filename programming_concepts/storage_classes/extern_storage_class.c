#include <stdio.h>
#include "extern_storage_class.h"

// extern - static duration and external linkage (unless already declared internal)
/* It can be used with function and object declarations in both file and block scope (excluding function parameter lists)
 * If extern appears on a redeclaration of an identifier that was already declared with internal linkage, 
 * the linkage remains internal. 
 * Otherwise (if the prior declaration was external, no-linkage, or is not in scope), the linkage is external.
 */

int main(void) {

    printf("from main() int a = %d\n", a); // 1
    incrementExternVariable();
    printExternVariable(); // 2
    multiplyExternByTwo();
    incrementExternVariable();
    printExternVariable(); // 5
    checkValueofB(); // this variable is defined as unitialized
    return 0;
}

/* Note: when you are declaring a variable extern int b without any prior reference
 * it's not standard practice
extern int b; // file scope, external linkage, static duration, uninitialized

The following error is observed:
$ gcc -g -Wall extern_storage_class.c
/usr/bin/ld: /tmp/cc4d6JW3.o: warning: relocation against `b' in read-only section `.text'
/usr/bin/ld: /tmp/cc4d6JW3.o: in function `main':
/extern_storage_class.c:16: undefined reference to `b'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
*/
