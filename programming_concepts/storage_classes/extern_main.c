/* This program showcases usage of extern declaration outside of extern_main.c
 * without providing a reference in the header file.
 * extern int x is directly declared in another file.
 * the variable is updated as per it's properties.
 *
 * This program was written to just test that properties
 * */
#include <stdio.h>
#include "extern_storage_class.h"

extern int x = 8;
/* x is declared with extern but:
 *  The C standard (§6.9.2) says that any declaration with an initializer 
 *  is a definition, no matter what storage-class specifier you wrote.
 *  extern without initializer ⇒ declaration only. Only declarations without initializers reserve no storage.
 *  
 *  x is modified in another file extern_main_helper.c
 *  extern has external linkage, static duration, file scope */

int y = 88;
/* y is declared without extern keyword, it still behaves as extern
 *  y is modified in another file extern_main_helper.c
 *  y also has external linkage, static duration, file scope 
 */

int main(void) {
    printf("Value of x in main() = %d\n", x);
    printf("Value of y in main() = %d\n", y);
    foo();
    printf("value of x in main() after modifying in extern_main_helper = %d\n", x);
    printf("value of y in main() after modifying in extern_main_helper = %d\n", y);
    return 0;
}
