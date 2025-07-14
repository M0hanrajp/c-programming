#include <stdio.h>

enum TV { FOX = 11, CNN = 25, ESPN = 15, HBO = 22, MAX = 30, NBC = 32 };

void printEnum(enum TV *ptr) {
    printf("List of cable stations:\n");
    printf(" FOX: \t%2d\n", *(ptr));
    printf(" HBO: \t%2d\n", *(ptr + 3));
    printf(" MAX: \t%2d\n", *(ptr + 4));
}

int main(void) {
 
    /* introduces type enum TV
     * integer constants FOX, CNN ... or also called enumeration constant
     * Each enumeration-constant that appears in the body of an enumeration specifier 
     * becomes an integer constant with type int(until C23) in the enclosing scope and 
     * can be used whenever integer constants are required (e.g. as a case label or as a non-VLA array size).
     */
    printf("List of cable stations:\n");
    printf(" FOX: \t%2d\n", FOX);
    printf(" HBO: \t%2d\n", HBO);
    printf(" MAX: \t%2d\n", MAX);

    enum TV a[7] = {FOX, CNN, ESPN, HBO, MAX, NBC};
    printEnum(a);

    return 0;
}
/* Note:
 * enum Color; // Error: no forward-declarations for enums in C
 * enum Foo { A, B, C = 10, D, E = 1, F, G = F + C };
 * // A=0, B=1, C=10, D=11, E=1, F=2, G=12
 */
