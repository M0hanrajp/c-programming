/* Write the macro definition for the following
 * a. test weather character is small case letter or not 
 * b. test weather character is upper case letter or not 
 * c. test weather character is alphabet or not (using a & b macro)
 * d. test weather a number is bigger than other number or not.
 */

#include <stdio.h>

// macro and their definitions
#define SMALLCASE(c) (c > 96 && c < 123)
#define UPPERCASE(c) (c > 64 && c < 92)
#define CHECKALPHABET(c) (SMALLCASE(c) || UPPERCASE(c))
#define BIGGESTNUMBER(a, b) (a > b ? a : b)

int main(void) {
    char c = 'a';
    printf("Small case %d\n", SMALLCASE(c));
    printf("Upper case %d\n", UPPERCASE(c));
    printf("Check alphabet %d\n", CHECKALPHABET(c));
    printf("Check larger number %d\n", BIGGESTNUMBER(4, 4));
    return 0;
}
